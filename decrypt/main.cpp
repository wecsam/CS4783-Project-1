#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "ProbabilityDistribution.h"
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
		result.push_back(stoi(cell));
	}
	return true;
}

int main(){
    string input;
    // Get a message to decode from stdin
    do {
        cerr << "Enter the encrypted message (one line, comma separated, no spaces): ";
        getline(cin, input);
    } while(!input.length());
	
	// TODO: Make sure that the input is all commas and spaces.
	// Split input by the commas and convert to int.
    vector<int> ciphertext;
	ciphertext.reserve(500);
	if(!integerCsvToVector(input, ciphertext)){
		cerr << "A stringstream could not be initialized.\n";
		return 2;
	}
    
    // Verify that there are 500 encrypted characters
//    if(ciphertext.size() != 500) {
//        cerr << "The provided ciphertext is not L = 500.\n";
//        return 1;
//    }
	
	// Do the guessing that I described in the e-mail on Tue, Feb 28, 2017 at 2:26 AM.
	probabilityValues_influenceByPreviousPlaintext(LETTERS_INDEX_OF_SPACE, ciphertext[0], 1.0);
	for(size_t i = 1; i < ciphertext.size(); ++i){
		probabilityValues_influenceByPreviousCiphertext(ciphertext[i - 1], ciphertext[i], 0.25);
	}
	
	// Print out the probability distribution.
	probabilityValues_writeCSV(cout);
	return 0;
}
