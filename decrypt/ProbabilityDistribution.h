#include <cstddef>
#include <iostream>
#define NUM_LETTERS 27
#define LETTERS_INDEX_OF_SPACE 0 // This is the position within LETTERS of the space character.
#define NUM_CIPHERTEXT_VALUES 106
// For each of the 106 cipher values, this array of arrays
// will hold the probability distributions for each
// character for each encrypted value
extern double probabilityValues [NUM_CIPHERTEXT_VALUES][NUM_LETTERS];
bool probabilityValues_influenceByPreviousCiphertext(int prevCipherValue, int currCipherValue, double influence);
bool probabilityValues_influenceByPreviousPlaintext(std::size_t prevPlaintextValue, int currCipherValue, double influence);
void probabilityValues_writeCSV(std::ostream&);
