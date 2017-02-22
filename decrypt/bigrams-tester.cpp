#include <iostream>
#include "Bigrams.h"
using namespace std;

int main(){
	// Prompt the user for a letter or space.
	char first;
	cerr << "Enter a lowercase letter or a space: ";
	cin.get(first);
	// Check that this letter is in Bigrams::PROB_2_GIVEN_1.
	auto distribution = Bigrams::PROB_2_GIVEN_1.find(first);
	if(distribution == Bigrams::PROB_2_GIVEN_1.end()){
		cerr << "Please use a lowercase letter or a space.\n";
	}else{
		for(const auto& probability : distribution->second){
			cout << "The probability that '" << probability.first
				<< "' follows '" << first << "' is " << probability.second
				<< ".\n";
		}
	}
	return 0;
}
