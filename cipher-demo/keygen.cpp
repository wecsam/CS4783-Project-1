#include <algorithm>    // random_shuffle, sort
#include <array>
#include <ctime>        // time
#include <cstdlib>      // srand
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>      // iota
#include <utility>      // pair
using namespace std;
#define FREQUENCIES_LENGTH 27
#define KEY_FILE_NAME "Key.csv"

const array<pair<char, int>, FREQUENCIES_LENGTH> FREQUENCIES = {{ // Note: requires C++ 2011
	{' ', 19},
	{'a', 7},
	{'b', 1},
	{'c', 2},
	{'d', 4},
	{'e', 10},
	{'f', 2},
	{'g', 2},
	{'h', 5},
	{'i', 6},
	{'j', 1},
	{'k', 1},
	{'l', 3},
	{'m', 2},
	{'n', 6},
	{'o', 6},
	{'p', 2},
	{'q', 1},
	{'r', 5},
	{'s', 5},
	{'t', 7},
	{'u', 2},
	{'v', 1},
	{'w', 2},
	{'x', 1},
	{'y', 2},
	{'z', 1}
}};

int main(){
	// Before we do any work, make sure that we are able to write to the output file.
	ofstream keyfile(KEY_FILE_NAME);
	if(!keyfile){
		cerr << "The output file could not be opened.\n";
		return 1;
	}
	// Seed the random number generator.
	srand(unsigned(time(0)));
	// Find the number of key values. There should be 106 key values, which will be numbered from 0 to 105.
	int numKeyValues = 0;
	for(size_t i = 0; i < FREQUENCIES_LENGTH; ++i){
		numKeyValues += FREQUENCIES[i].second;
	}
	cout << "Number of key values: " << numKeyValues << '\n';
	// Create an array that holds the numbers 0 to 105 in random order.
	int keyValues[numKeyValues];
	iota(keyValues, keyValues + numKeyValues, 0);
	random_shuffle(keyValues, keyValues + numKeyValues);
	// Output a CSV file that represents the key.
	size_t keyValueIndex = 0;
	cout << "Writing key file...\n";
	keyfile << "English Letter,Key Values (Space Delimited)\n";
	for(size_t i = 0; i < FREQUENCIES_LENGTH; ++i){
		// In keyValues, indices from keyValueIndex to (keyValueIndex + FREQUENCIES[i].second - 1) inclusive
		// are key values that shall correspond to this plaintext letter.
		// Sort the key values that correspond to this plaintext character.
		sort(keyValues + keyValueIndex, keyValues + keyValueIndex + FREQUENCIES[i].second);
		// Write the plaintext letter.
		keyfile << '\'' << FREQUENCIES[i].first << "',";
		// Write the key values.
		// Write the first one separately.
		keyfile << keyValues[keyValueIndex];
		for(size_t j = keyValueIndex + 1; j < keyValueIndex + FREQUENCIES[i].second; ++j){
			keyfile << ' ' << keyValues[j];
		}
		keyfile << '\n';
		keyValueIndex += FREQUENCIES[i].second;
	}
	cout << "Done.\n";
	return 0;
}
