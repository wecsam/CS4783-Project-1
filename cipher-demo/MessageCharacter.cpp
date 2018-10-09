#include <cstdlib>
#include "MessageCharacter.h"
using namespace std;

MessageCharacter::MessageCharacter(vector<int>&& keyValues) : keyValues(move(keyValues)), count(0) {}
MessageCharacter::MessageCharacter(const MessageCharacter& rhs) : keyValues(rhs.keyValues), count(0) {}
MessageCharacter::MessageCharacter(MessageCharacter&& rhs) : keyValues(move(rhs.keyValues)), count(0) {}

int MessageCharacter::getRandomCipherValue() const {
	return keyValues[rand() % keyValues.size()];
}

int MessageCharacter::getNextCipherValue() {
	return keyValues[count++ % keyValues.size()];
}
