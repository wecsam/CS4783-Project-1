#include <vector>
class MessageCharacter {
public:
	// Pass in a vector of key values that can represent a plaintext character.
	// This class does not actually know what character it represents.
	// It is assumed that the vector has a size of at least 1.
	MessageCharacter(std::vector<int>&&);
	// Copy and move constructors
	MessageCharacter(const MessageCharacter&);
	MessageCharacter(MessageCharacter&&);
	// Returns a random value between cipherValueRangeStart and (cipherValueRangeStart + averageFrequency), inclusive.
	// You should call srand before using this function.
	int getRandomCipherValue() const;
	int getNextCipherValue();
	// The default copy and move constructors will work fine for this.
private:
	std::vector<int> keyValues;
	int count;
};
