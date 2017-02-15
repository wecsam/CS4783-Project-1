#include <cstdlib>
#include "MessageCharacter.h"
using namespace std;

MessageCharacter::MessageCharacter(vector<int>&& keyValues) : keyValues(move(keyValues)) {}
MessageCharacter::MessageCharacter(const MessageCharacter& rhs) : keyValues(rhs.keyValues) {}
MessageCharacter::MessageCharacter(MessageCharacter&& rhs) : keyValues(move(rhs.keyValues)) {}

int MessageCharacter::getRandomCipherValue() const {
	return keyValues[rand() % keyValues.size()];
}
