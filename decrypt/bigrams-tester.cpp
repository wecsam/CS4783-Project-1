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
		cout << "Given that the first character is '" << first << "'...\n";
		for(const auto& probability : distribution->second){
			cout << "...the probability of the bigram '" << first << probability.first
				<< "' is " << probability.second * 100 << "%.\n";
		}
	}
	return 0;
}
