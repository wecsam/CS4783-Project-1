#include <cstdlib>
#include "MessageCharacter.h"

MessageCharacter::MessageCharacter(int cipherValueRangeStart, int averageFrequency)
: cipherValueRangeStart(cipherValueRangeStart), averageFrequency(averageFrequency)
{}
int MessageCharacter::getRandomCipherValue() const {
	return rand() % this->averageFrequency + this->cipherValueRangeStart;
}
