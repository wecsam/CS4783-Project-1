#include <algorithm>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <unordered_set>
#include <vector>
#include "constants.h"
#include "AverageFrequency.h"
#include "EnglishWords.h"
#include "PlaintextDictionary.h"
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

// Returns the length of the istream and also seeks the istream back to the beginning.
streampos istreamGetLengthAndSeekToBeginning(istream& is){
	is.seekg(0, ios_base::end);
	streampos filesize = is.tellg();
	is.seekg(0, ios_base::beg);
	return filesize;
}

// Whether two reverse keys match. If either key has a null byte in a position, that position is ignored.
// It is assumed that keyA and keyB are both of length NUM_CIPHERTEXT_VALUES.
bool reverseKeysMatch(const char* keyA, const char* keyB){
	for(size_t i = 0; i < NUM_CIPHERTEXT_VALUES; ++i){
		if(keyA[i] && keyB[i] && keyA[i] != keyB[i]){
			return false;
		}
	}
	return true;
}

// Whether two buffers match, except in positions where strA has a null byte.
// wordSize is the number of bytes to compare. Both buffers must be at least this length.
// The return value is the first position the buffers do not match. If the buffers match
// all the way to wordSize, then the return value is wordSize.
size_t buffersMatchExceptUnknowns(const size_t wordSize, const char* strA, const char* strB){
	for(size_t i = 0; i < wordSize; ++i){
		if(strA[i] && strA[i] != strB[i]){
			return i;
		}
	}
	return wordSize;
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
	
	// Check that all of the ciphertext values are between 0 and NUM_CIPHERTEXT_VALUES - 1, inclusive.
	for(int c : ciphertext){
		if(!(0 <= c && c < NUM_CIPHERTEXT_VALUES)){
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
			// See if there is already a saved reverse key.
			ifstream reverseKeyFileExisting(REVERSE_KEY_FILENAME);
			if(reverseKeyFileExisting && (istreamGetLengthAndSeekToBeginning(reverseKeyFileExisting) == NUM_CIPHERTEXT_VALUES)){
				// There is a saved reverse key. Let's see if it matches this one.
				// Read the saved reverse key into memory.
				char reverseKeyExisting[NUM_CIPHERTEXT_VALUES];
				reverseKeyFileExisting.read(reverseKeyExisting, NUM_CIPHERTEXT_VALUES);
				reverseKeyFileExisting.close();
				if(reverseKeysMatch(reverseKey, reverseKeyExisting)){
					// They match! Replace unknown values in this key with the values in the existing key.
					for(size_t i = 0; i < NUM_CIPHERTEXT_VALUES; ++i){
						if(!reverseKey[i]){
							reverseKey[i] = reverseKeyExisting[i];
						}
					}
				}
			}
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
			if(istreamGetLengthAndSeekToBeginning(reverseKeyFile) == NUM_CIPHERTEXT_VALUES){
				// Read the file into a char array.
				char reverseKey[NUM_CIPHERTEXT_VALUES];
				reverseKeyFile.read(reverseKey, NUM_CIPHERTEXT_VALUES);
				reverseKeyFile.close();
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
				if(unknownPositions.size()){
					// Pre-compute the result of strlen for all of the English words.
					vector<size_t> EnglishWordLengths;
					EnglishWordLengths.reserve(EnglishWords.size());
					for(const char* s : EnglishWords){
						EnglishWordLengths.push_back(strlen(s));
					}
					// Compute a set of letters whose key values have not been exhausted (i.e. it
					// might be the plaintext letter behind an unknown ciphertext value).
					unordered_set<char> possibleLetters;
					{
						// Get the number of ciphertext values that each English letter is given.
						// Decrement the number of unknown ciphertext values for each ciphertext
						// value that is known.
						auto expectedUnknownCiphertextValues = AverageFrequency();
						for(size_t i = 0; i < NUM_CIPHERTEXT_VALUES; ++i){
							if(reverseKey[i]){
								--expectedUnknownCiphertextValues[reverseKey[i]];
							}
						}
						// If a letter still has unknown ciphertext values, then add it to the set.
						for(const auto& p : expectedUnknownCiphertextValues){
							if(p.second > 0){
								possibleLetters.emplace(p.first);
							}else if(p.second < 0){
								cerr << "Fatal error: retrieved key has too many of '" << p.first << "'!\n";
								return 7;
							}
						}
					}
					// Sanity check: if unknownPositions.size() > 0, then possibleLetters.size() must also be > 0.
					if(!possibleLetters.size()){
						cerr << "Fatal error: inconsistency in retrieved key!\n";
						return 6;
					}
					// Analyze each unknown letter.
					size_t wordEnd = 0;
					for(size_t position : unknownPositions){
						// Skip this position if it was in the same word as the last position.
						if(position < wordEnd){
							continue;
						}
						// The goal is to find a matching English word based on the surrounding known letters.
						// First, find the start and end of the current word.
						size_t wordStart;
						for(wordStart = position; wordStart > 0; --wordStart){
							if(plaintext[wordStart - 1] == ' '){
								break;
							}
						}
						for(wordEnd = position + 1; wordEnd < (MESSAGE_LENGTH - 1); ++wordEnd){
							if(plaintext[wordEnd] == ' '){
								break;
							}
						}
						size_t wordSize = wordEnd - wordStart, firstContiguousKnownSize = position - wordStart;
						// Search the list of English words for a matching word.
						size_t englishWordMatch, englishWordMatchSizeMax = 0;
						int numIndicationsThatThisIsASpace = 0;
						for(size_t i = 0; i < EnglishWords.size(); ++i){
							if(firstContiguousKnownSize < EnglishWordLengths[i] && EnglishWordLengths[i] <= wordSize){
								// This English word is long enough potentially to reveal the plaintext
								// letter of this position, and this English word is shorter than or as
								// short as the unknown word.
								// Check whether the letter in the English word that lines up with this
								// unknown position is one of the letters that are missing key values.
								if(possibleLetters.find(EnglishWords[i][firstContiguousKnownSize]) != possibleLetters.end()){
									// Check whether all of the known characters match.
									size_t matchSize = buffersMatchExceptUnknowns(EnglishWordLengths[i], plaintext + wordStart, EnglishWords[i]);
									if(matchSize > englishWordMatchSizeMax){
										// This English word matches the most plaintext letters so far.
										englishWordMatch = i;
										englishWordMatchSizeMax = matchSize;
									}
								}
							}
							if(firstContiguousKnownSize == EnglishWordLengths[i]){
								// The number of letters after plaintext[wordStart] that are known
								// is equal to the number of letters in this English word.
								// Check whether these known letters are a word. If they are, then
								// this unknown character is probably a space.
								if(equal(plaintext + wordStart, plaintext + position, EnglishWords[i])){
									++numIndicationsThatThisIsASpace;
								}
							}
						}
						// Try to figure out the plaintext letter at this position.
						if(englishWordMatchSizeMax){
							// Overwrite this word within the plaintext with the full English word.
							memcpy(plaintext + wordStart, EnglishWords[englishWordMatch], EnglishWordLengths[englishWordMatch]);
							wordEnd = wordStart + EnglishWordLengths[englishWordMatch];
							// Add a space after the word. This covers the case where there are two unknown letters,
							// where the first is the last letter of a word, and where the second is a space.
							if(wordEnd < MESSAGE_LENGTH && !plaintext[wordEnd]){
								plaintext[wordEnd] = ' ';
							}
						}else if(numIndicationsThatThisIsASpace){
							// This unknown position probably is supposed to contain a space.
							// Let's make it so.
							plaintext[position] = ' ';
							wordEnd = position;
						}else{
							// This is not a known English word. Replace each of the unknown characters with 'e'.
							cerr << "This word is not a known English word: ";
							for(size_t i = 0; i < wordSize; ++i){
								if(plaintext[i]){
									cerr << plaintext[i];
								}else{
									cerr << '?';
									plaintext[i] = 'e';
								}
							}
							cerr << endl;
						}
						// At this point in the code, letters in plaintext between wordStart and wordEnd are all known.
					}
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
	return 0;
}
