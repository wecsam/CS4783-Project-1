#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include "constants.h"
#include "PlaintextDictionary.h"
//#include "ProbabilityDistribution.h"
//#define MAX_EXECUTION_SECONDS 0 // Set to 0 to disable passes.
#define REVERSE_KEY_FILENAME ".Tsai-Pock-key.bin"
using namespace std;

// Splits a string based off of a delimiter
bool integerCsvToVector(const string& rowstr, vector<int>& result){
	// This function converts a string of comma-separated values into a vector.
	// It returns true on success and false on failure.
	// If the vector is not empty, the values are pushed onto the end.
	stringstream ss(rowstr);
	if(!ss){
		return false;
	}
	string cell;
	while(getline(ss, cell, ',')){
		try {
			result.push_back(stoi(cell));
		} catch (const invalid_argument& ia) {
			return false;
		} catch (const out_of_range& oor) {
			return false;
		}
	}
	return true;
}

// Takes a plaintext/ciphertext pair and derives a reverse key
// All of the ciphertext values must be in the valid range from 0 to NUM_CIPHERTEXT_VALUES - 1.
// reverseKey must be a char array of length NUM_CIPHERTEXT_VALUES.
// Ciphertext values that don't appear in this ciphertext will be left as a null character (\0).
bool reverseKeyFromPlaintextCipherText(const Plaintext& plaintext, const vector<int>& ciphertext, char* reverseKey){
	// We have already verified that all of the ciphertext values are
	// between 0 and NUM_CIPHERTEXT_VALUES - 1, inclusive.
	for(size_t i = 0; i < MESSAGE_LENGTH; ++i){
		if(reverseKey[ciphertext[i]] == '\0'){
			// This ciphertext value has not appeared yet in the ciphertext.
			// Save the corresponding plaintext in the reverse key.
			reverseKey[ciphertext[i]] = plaintext.charAt(i);
		}else if(reverseKey[ciphertext[i]] != plaintext.charAt(i)){
			// This ciphertext value has already appeared in the ciphertext,
			// but it represented a different plaintext value last time.
			cerr << "At position " << i << ": ciphertext " << ciphertext[i] << " was plaintext '"
				<< reverseKey[ciphertext[i]] << "' last time but is now '" << plaintext.charAt(i) << "'.\n";
			return false;
		}
	}
	return true;
}

int main(){
	// We'll use stdout for the actual plaintext guess and stderr for any other messages.
	
    string input;
    // Get a message to decode from stdin
    do {
        cerr << "Enter the encrypted message (one line, comma separated, no spaces): ";
        getline(cin, input);
    } while(!input.length());
	
	// Split input by the commas and convert to int.
    vector<int> ciphertext;
	ciphertext.reserve(MESSAGE_LENGTH);
	if(!integerCsvToVector(input, ciphertext)){
		cerr << "There were characters other than numbers and commas, or a stringstream could not be initialized.\n";
		return 2;
	}
    
    // Verify that there are MESSAGE_LENGTH encrypted characters
    if(ciphertext.size() != MESSAGE_LENGTH) {
        cerr << "The provided ciphertext is not L = " << MESSAGE_LENGTH << ".\n";
        return 1;
    }
	
	// Count how many times each ciphertext value occurs.
	int occurrences[NUM_CIPHERTEXT_VALUES] = {0};
	for(int c : ciphertext){
		if(0 <= c && c < NUM_CIPHERTEXT_VALUES){
			++occurrences[c];
		}else{
			cerr << "The ciphertext value " << c << " is not between 0 and " << (NUM_CIPHERTEXT_VALUES - 1) << ".\n";
			return 3;
		}
	}
	
	// Try to match this ciphertext to one of the known plaintexts in the plaintext dictionary.
	size_t indexOfMatchingPlaintext;
	for(indexOfMatchingPlaintext = 0; indexOfMatchingPlaintext < NUM_PLAINTEXTS_SPRING2017; ++indexOfMatchingPlaintext){
		if(spring2017plaintexts[indexOfMatchingPlaintext].hasEqualValuesInTheRightPlaces(ciphertext)){
			break;
		}
	}
	if(indexOfMatchingPlaintext < NUM_PLAINTEXTS_SPRING2017){
		// A match was found!
		cerr << "My plaintext guess is: ";
		cout << spring2017plaintexts[indexOfMatchingPlaintext] << endl;
		// Now try to derive a reverse key from this plaintext and ciphertext.
		// A reverse key has the exact same data as a key, but whereas the key
		// was a lookup table for the plaintext letter that returned ciphertext,
		// the reverse key is a lookup table for the ciphertext that returns
		// the plaintext.
		// The reverse key is an array of chars, where reverseKey[c] is the
		// plaintext letter that is represented by ciphertext value c.
		char reverseKey[NUM_CIPHERTEXT_VALUES] = {0};
		if(reverseKeyFromPlaintextCipherText(spring2017plaintexts[indexOfMatchingPlaintext], ciphertext, reverseKey)){
			// Save the reverse key as a file.
			ofstream reverseKeyFile(REVERSE_KEY_FILENAME);
			if(reverseKeyFile){
				reverseKeyFile.write(reverseKey, NUM_CIPHERTEXT_VALUES);
				reverseKeyFile.close();
			}else{
				cerr << "Error: could not open file for writing the key!\n";
			}
		}else{
			cerr << "The key could not be derived from this plaintext.\n";
		}
	}else{
		// None of the known plaintexts matched. This must be Part 2 of the project.
		// Try to read the reverse key from the file.
		ifstream reverseKeyFile(REVERSE_KEY_FILENAME);
		if(reverseKeyFile){
			// Get length of reverse key file.
			reverseKeyFile.seekg(0, ios_base::end);
			streampos reverseKeyFileSize = reverseKeyFile.tellg();
			reverseKeyFile.seekg(0, ios_base::beg);
			if(reverseKeyFileSize == NUM_CIPHERTEXT_VALUES){
				// Read the file into a char array.
				char reverseKey[NUM_CIPHERTEXT_VALUES];
				reverseKeyFile.read(reverseKey, NUM_CIPHERTEXT_VALUES);
				// Decrypt all of the known values in the ciphertext. Unknown values are denoted in the key as \0.
				char plaintext[MESSAGE_LENGTH];
				vector<size_t> unknownPositions;
				for(size_t i = 0; i < MESSAGE_LENGTH; ++i){
					if(reverseKey[ciphertext[i]]){
						plaintext[i] = reverseKey[ciphertext[i]];
					}else{
						plaintext[i] = '\0';
						unknownPositions.push_back(i);
					}
				}
				// Now try to figure out ciphertext values whose plaintext letters were unknown.
				for(size_t position : unknownPositions){
					// TODO
					cerr << "Unknown position: " << position << ", ciphertext=" << ciphertext[position] << "\n";
				}
				// Print out our best guess.
				cerr << "My plaintext guess is: ";
				cout.write(plaintext, MESSAGE_LENGTH);
				cout << endl;
			}else{
				cerr << "The files from part 1 are corrupted. Run part 1 again.\n";
				return 5;
			}
		}else{
			cerr << "It looks like you're trying to run part 2 of the project,\n"
				<< "but none of the files from part 1 are here.\n";
			return 4;
		}
	}
	
	/*
	// This array holds uncertainty values for how unconfident we are about
	// the corresponding plaintext letter of a ciphertext value.
	double uncertainty[NUM_CIPHERTEXT_VALUES];
	fill_n(uncertainty, NUM_CIPHERTEXT_VALUES, 1.0);
	
	// Do the guessing that I described in the e-mail on Tue, Feb 28, 2017 at 2:26 AM.
	probabilityValues_influenceByPreviousPlaintext(LETTERS_INDEX_OF_SPACE, ciphertext[0], 1.0);
	uncertainty[ciphertext[0]] = 0.5;
	// Run multiple passes for MAX_EXECUTION_SECONDS seconds.
	time_t startTime = time(NULL);
	int numIterations = 0;
	do {
		++numIterations;
		for(size_t i = 1; i < MESSAGE_LENGTH; ++i){
			*//*if(occurrences[ciphertext[i]] >= 11){
				// If this ciphertext values occurs more than 11 times out of 500, it's almost certainly the letter c.
				probabilityValues_setPlaintext(ciphertext[i], 3, 0.9999);
				uncertainty[ciphertext[i]] = 0.0001;
	}else*//*{
				//probabilityValues_influenceByPreviousCiphertext(ciphertext[i - 1], ciphertext[i], 1.0 - uncertainty[ciphertext[i - 1]]);
				probabilityValues_influenceByPreviousCiphertext(ciphertext[i - 1], ciphertext[i], 1.0);
				uncertainty[ciphertext[i]] *= 0.999;
			}
		}
	} while(time(NULL) - startTime < MAX_EXECUTION_SECONDS);
	cerr << "Performed " << numIterations << " passes.\n";
	
	// Print out the probability distribution.
	probabilityValues_writeCSV(cout); // TODO: remove this line before submitting project
	
	// Print the uncertainty values.
	cerr << "C-text\tConfidence\n";
	for(size_t i = 0; i < NUM_CIPHERTEXT_VALUES; ++i){
		cerr << i << '\t' << (1.0 - uncertainty[i]) << '\n';
	}
	*/
	return 0;
}
