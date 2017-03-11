#include "Plaintext.h"
using namespace std;
Plaintext::Plaintext(string&& plaintext, map<char, vector<size_t>>&& positionsWithEqualValues)
: plaintext(move(plaintext)), positionsWithEqualValues(move(positionsWithEqualValues)) {
	valid = (plaintext.size() == 500 && positionsWithEqualValues.size() >= 2);
}
bool Plaintext::isValid() const {
	return valid;
}
bool Plaintext::hasEqualValuesInTheRightPlaces(const vector<int>& ciphertext) const {
	// Loop through each vector of positions whose values should be equal to each other.
	for(const auto& equalSet : positionsWithEqualValues){
		// Check that the values at these positions in the ciphertext are all equal.
		// It is assumed that isValid() has already been checked to make sure that the
		// vector has at least two items.
		for(size_t i = 1; i < equalSet.second.size(); ++i){
			if(ciphertext[equalSet.second[0]] != ciphertext[equalSet.second[i]]){
				return false;
			}
		}
	}
	return true;
}
ostream& operator<<(ostream& lhs, const Plaintext& rhs){
	lhs << rhs.plaintext;
	return lhs;
}
