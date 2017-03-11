/*
	The purpose of this class is to allow the program to perform a known plaintext attack
	in part 1 of the project. We know that the input will be one of five possible plaintexts
	from plaintext_dictionary.txt. Because the cipher that this project aims to crack is a
	permutation cipher, certain positions will always have values equal to each other,
	regardless of the key that is used to encrypt a plaintext.
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
class Plaintext {
	friend std::ostream& operator<<(std::ostream&, const Plaintext&);
public:
	// Constructor: pass in the unencrypted plaintext and a map from plaintext characters that only have
	// one key value to the positions where those characters occur. (Yes, this could be computed here,
	// but because the plaintexts from the plaintext dictionary are known, it should be computed ahead of
	// time.)
	Plaintext(std::string&& plaintext, std::map<char, std::vector<std::size_t>>&& positionsWithEqualValues);
	// Whether the plaintext is the right length and every vector of positions with equal values has
	// at least two items
	bool isValid() const;
	// Pass in a ciphertext (from main.cpp). This function returns whether that ciphertext's positions
	// with equal values match this plaintext's. In the five plaintexts in plaintext_dictionary.txt,
	// these positions were unique, so you can count on this plaintext being the plaintext that this
	// ciphertext represents.
	// Note: you should call isValid() first. If isValid() is false, then this function exhibits
	// undefined behavior.
	bool hasEqualValuesInTheRightPlaces(const std::vector<int>& ciphertext) const;
	// Returns the character in the unencrypted at position p. It is assumed that p < 500, the length of the
	// plaintext.
	char charAt(std::size_t p) const;
private:
	bool valid;
	// The unencrypted plaintext
	std::string plaintext;
	// Map from a plaintext character to a vector of positions that the character occurs
	std::map<char, std::vector<std::size_t>> positionsWithEqualValues;
};
