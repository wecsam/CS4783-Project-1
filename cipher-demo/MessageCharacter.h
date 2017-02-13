class MessageCharacter {
public:
	// Pass in the first key value (column 3 in the assignment sheet) for this character (column 1).
	// This class does not actually need to know what character it represents.
	MessageCharacter(int, int);
	// Returns a random value between cipherValueRangeStart and (cipherValueRangeStart + averageFrequency), inclusive.
	// You should call srand before using this function.
	int getRandomCipherValue() const;
	// The default copy and move constructors will work fine for this.
private:
	int cipherValueRangeStart;
	int averageFrequency;
};
