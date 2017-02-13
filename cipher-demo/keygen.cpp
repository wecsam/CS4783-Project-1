#include <algorithm>    // random_shuffle
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
	// We want to iterate through FREQUENCIES in random order to generate a random key.
	// First, generate an array of FREQUENCIES keys.
	size_t frequenciesKeys[FREQUENCIES_LENGTH];
	iota(frequenciesKeys, frequenciesKeys + FREQUENCIES_LENGTH, 0);
	// Now, shuffle the keys. It looks like this is the best method unless there's a random_access_iterator.
	srand(unsigned(time(0)));
	random_shuffle(frequenciesKeys, frequenciesKeys + FREQUENCIES_LENGTH);
	// Initialize a map from message space characters (column 1 in assignment sheet) to the first of the key values (column 3).
	// For example, if key['a'] == 5, then the letter A can encrypt to any integer between 5 and 11, inclusive. Recall that
	// the value in column 2 for A is 7.
	map<char, int> key;
	/* Scope for numKeyValues */ {
		// Carve out the key values (column 3 in assignment sheet) and assign them to message space characters (column 1).
		int numKeyValues = 0;
		for(size_t i = 0; i < FREQUENCIES_LENGTH; ++i){
			key[FREQUENCIES[frequenciesKeys[i]].first] = numKeyValues;
			numKeyValues += FREQUENCIES[frequenciesKeys[i]].second;
		}
		// Show the number of key values. There should be 106 key values, which will be numbered from 0 to 105.
		cout << "Number of key values: " << numKeyValues << '\n';
	}
	// Output a CSV file that represents the key.
	cout << "Writing key file...\n";
	keyfile << "English Letter,Average Frequency,Key Values Start,Key Values End\n";
	for(size_t i = 0; i < FREQUENCIES_LENGTH; ++i){
		keyfile << '\'' << FREQUENCIES[i].first << "'," // English Letter
				<< FREQUENCIES[i].second << ','         // Average Frequency
				<< key[FREQUENCIES[i].first] << ','     // Key Values Start
				<< key[FREQUENCIES[i].first] + FREQUENCIES[i].second - 1
				<< '\n';
	}
	cout << "Done.\n";
	return 0;
}
