#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include "Key.h"
using namespace std;
#define KEY_FILE_NAME "Key.csv"
#define MSG_BAD_CHAR "This character is not in the key and cannot be encrypted: "

int main(){
	// Read the key file.
	ifstream keyfile(KEY_FILE_NAME);
	if(!keyfile){
		cerr << "Could not read key file!\n";
		return 1;
	}
	// Instantiate a key object.
	Key k(keyfile);
	if(!k){
		cerr << "The key file is invalid!\n";
		return 2;
	}
	// Get a message to encode from stdin.
	string input;
	do {
		cerr << "Enter a message to encrypt: ";
		getline(cin, input);
	} while(!input.length());
	// Print encrypted message to stdout.
	bool first = true;
	for(char c : input){
		int e = k.encrypt(c);
		if(e < 0){
			if(!first){
				cerr << '\n';
			}
			cerr << MSG_BAD_CHAR << c << '\n';
		}else{
			if(!first){
				cout << ',';
			}
			cout << e;
			first = false;
		}
	}
    
	cout << endl;
	return 0;
}
