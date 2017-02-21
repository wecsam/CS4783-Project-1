#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

// Splits a string based off of a delimiter
template<typename Out>
void split(const string &s, char delim, Out result) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

// Driver for string splitting
vector<string> split(const string &s, char delim) {
    vector<string> v;
    split(s, delim, back_inserter(v));
    return v;
}

int main(){
    string input;
    // Get a message to decode from stdin
    do {
        cerr << "Enter the encrypted message: ";
        getline(cin, input);
    } while(!input.length());
    
    // Verify that there are 500 encrypted characters
    int count = 0;
    for(char c : input) {
        if(c == ',') {
            count++;
        }
    }
    // Enforce the 500 encrypted characters rule
//    if(count != 499) {
//        cerr << "The provided ciphertext is not L = 500.\n";
//        return 1;
//    }
    
    vector<string> ciphertext = split(input, ',');
	return 0;
}
