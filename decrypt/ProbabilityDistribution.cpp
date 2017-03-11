#include "ProbabilityDistribution.h"
#include "Bigrams.h"
#define LetterFrequency {0.1832, 0.0655, 0.0127, 0.0227, 0.0335, 0.1022, 0.0197, 0.0164, 0.0486, 0.0573, 0.0011, 0.0057, 0.0336, 0.0202, 0.057, 0.062, 0.015, 0.0009, 0.0497, 0.0533, 0.0751, 0.023, 0.0079, 0.0169, 0.0015, 0.0147, 0.0006}

// Let probabilityValues[x][y] be the probability that ciphertext value x is plaintext letter y.
// For each of the 106 rows, the columns are structured as such:
// Ciphertext 0     { Space, A, B, ..., Z }
// Ciphertext 1     { Space, A, B, ..., Z }
// Ciphertext ...   { Space, A, B, ..., Z }
// Ciphertext 105   { Space, A, B, ..., Z }
double probabilityValues [NUM_CIPHERTEXT_VALUES][NUM_LETTERS] {
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency,
    LetterFrequency
};

// AELPSL = Average of Ending Letter weighted by Probability of Starting Letter
/*
	This is an internal function. Don't put it in the header.
	TODO: Maybe we should just make this whole file class with all static members and methods.
*/
void probabilityValues_influence(int currCipherValue, const double* aelpsl, double influence){
	// Use the probability distribution of the current letter to influence the probability distribution
	// of what the current ciphertext value represents in plaintext.
	for(size_t currLetter = 0; currLetter < NUM_LETTERS; ++currLetter){
		/*std::cerr << "currCipherValue=" << currCipherValue << " influence=" << influence
			<< " probabilityValues[currCipherValue][currLetter]=" << probabilityValues[currCipherValue][currLetter]
			<< " aelpsl[currLetter]=" << aelpsl[currLetter];*/
		// The greater the influence, the more that the new distribution will affect the existing one.
		probabilityValues[currCipherValue][currLetter] = (1.0 - influence) * probabilityValues[currCipherValue][currLetter] +
			influence * aelpsl[currLetter];
		//std::cerr << " Result=" << probabilityValues[currCipherValue][currLetter] << '\n';
	}
}
/*
	Pass in a pair of consecutive ciphertext values. This will update the probability distribution
	based on possible bigrams in the corresponding plaintext.
*/
bool probabilityValues_influenceByPreviousCiphertext(int prevCipherValue, int currCipherValue, double influence){
	// Find the weighted average probability of bigrams that end in this letter, where the weight is
	// the probability that the previous ciphertext value is the first letter in the bigram.
	double aelpsl[NUM_LETTERS] = {0.0};
	for(size_t currLetter = 0; currLetter < NUM_LETTERS; ++currLetter){
		for(size_t prevLetter = 0; prevLetter < NUM_LETTERS; ++prevLetter){
			// Because Bigrams::PROB_2_GIVEN_1 is const, we use the find function.
			// We also use the LETTERS[prevLetter] syntax to convert from an index of the letter to the actual letter.
			// For example, LETTERS[1] == 'A', LETTERS[2] == 'B', and so on.
			auto bigramFirstLetter = Bigrams::PROB_2_GIVEN_1.find(LETTERS[prevLetter]);
			if(bigramFirstLetter == Bigrams::PROB_2_GIVEN_1.end()){
				// There are no bigrams that start with prevLetter.
				return false;
			}
			auto bigramSecondLetter = bigramFirstLetter->second.find(LETTERS[currLetter]);
			if(bigramSecondLetter == bigramFirstLetter->second.end()){
				// There are no bigrams that start with prevLetter and end with currLetter.
				return false;
			}
			aelpsl[currLetter] += probabilityValues[prevCipherValue][prevLetter] * bigramSecondLetter->second;
		}
	}
	probabilityValues_influence(currCipherValue, aelpsl, influence);
	return true;
}
/*
	This is just like probabilityValues_influenceByPreviousCiphertexttext, but the first character is
	specified as plaintext. Use this only when you're 100% sure of what the first character is in the plaintext.
*/
bool probabilityValues_influenceByPreviousPlaintext(size_t prevPlaintextValue, int currCipherValue, double influence){
	double aelpsl[NUM_LETTERS];
	auto bigramFirstLetter = Bigrams::PROB_2_GIVEN_1.find(LETTERS[prevPlaintextValue]);
	if(bigramFirstLetter == Bigrams::PROB_2_GIVEN_1.end()){
		return false;
	}
	for(size_t currLetter = 0; currLetter < NUM_LETTERS; ++currLetter){
		auto bigramSecondLetter = bigramFirstLetter->second.find(LETTERS[currLetter]);
		if(bigramSecondLetter == bigramFirstLetter->second.end()){
			return false;
		}
		aelpsl[currLetter] = bigramSecondLetter->second;
	}
	probabilityValues_influence(currCipherValue, aelpsl, influence);
	return true;
}
/*
	If you're really sure about the current plaintext letter, then use this function.
	For example, if you're 95% sure that ciphertext 87 is plaintext 'c', then call
	probabilityValues_setPlaintext(87, 'c', 0.95).
*/
void probabilityValues_setPlaintext(int currCipherValue, size_t currPlaintextValue, double confidence){
	// Find maximum value except currPlaintextValue's value.
	double maximumExceptCurrPlaintext = 0.0;
	for(size_t currLetter = 0; currLetter < currPlaintextValue; ++currLetter){
		if(maximumExceptCurrPlaintext < probabilityValues[currCipherValue][currLetter]){
			maximumExceptCurrPlaintext = probabilityValues[currCipherValue][currLetter];
		}
	}
	for(size_t currLetter = currPlaintextValue + 1; currLetter < NUM_LETTERS; ++currLetter){
		if(maximumExceptCurrPlaintext < probabilityValues[currCipherValue][currLetter]){
			maximumExceptCurrPlaintext = probabilityValues[currCipherValue][currLetter];
		}
	}
	// Normalize the values other than currPlaintextValue's value to (1 - confidence).
	for(size_t currLetter = 0; currLetter < currPlaintextValue; ++currLetter){
		probabilityValues[currCipherValue][currLetter] = probabilityValues[currCipherValue][currLetter] / maximumExceptCurrPlaintext * (1 - confidence);
	}
	for(size_t currLetter = currPlaintextValue + 1; currLetter < NUM_LETTERS; ++currLetter){
		probabilityValues[currCipherValue][currLetter] = probabilityValues[currCipherValue][currLetter] / maximumExceptCurrPlaintext * (1 - confidence);
	}
	// Set currPlaintextValue's value to confidence.
	probabilityValues[currCipherValue][currPlaintextValue] = confidence;
}
/*
	Use this function to write probabilityValues to an ostream in CSV format.
*/
void probabilityValues_writeCSV(std::ostream& out){
	// Header row
	out << "Ciphertext,";
	for(size_t p = 0; p < NUM_LETTERS - 1; ++p){
		out << '\'' << LETTERS[p] << '\'' << ',';
	}
	out << '\'' << LETTERS[NUM_LETTERS - 1] << '\'' << '\n';
	// Other rows
	for(size_t c = 0; c < NUM_CIPHERTEXT_VALUES; ++c){
		out << c << ',';
		for(size_t p = 0; p < NUM_LETTERS - 1; ++p){
			out << probabilityValues[c][p] << ',';
		}
		out << probabilityValues[c][NUM_LETTERS - 1] << '\n';
	}
}
