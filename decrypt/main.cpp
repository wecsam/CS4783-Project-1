#include <algorithm>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include "PlaintextDictionary.h"
//#include "ProbabilityDistribution.h"
//#define MAX_EXECUTION_SECONDS 0 // Set to 0 to disable passes.
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
	ciphertext.reserve(500);
	if(!integerCsvToVector(input, ciphertext)){
		cerr << "There were characters other than numbers and commas, or a stringstream could not be initialized.\n";
		return 2;
	}
    
    // Verify that there are 500 encrypted characters
    if(ciphertext.size() != 500) {
        cerr << "The provided ciphertext is not L = 500.\n";
        //return 1;
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
	}else{
		cerr << "None of the known plaintexts matched. This must be Part 2 of the project.\n";
	}
	
	/*
	// Count how many times each ciphertext value occurs.
	int occurrences[NUM_CIPHERTEXT_VALUES] = {0};
	for(int c : ciphertext){
		if(0 <= c && c < NUM_CIPHERTEXT_VALUES){
			++occurrences[c];
		}else{
			cerr << "The ciphertext value " << c << " is not between 0 and " << NUM_CIPHERTEXT_VALUES << ".\n";
			return 3;
		}
	}
	
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
		for(size_t i = 1; i < ciphertext.size(); ++i){
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
