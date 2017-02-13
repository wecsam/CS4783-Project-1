#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "MessageCharacter.h"

class Key {
public:
	// Pass in an istream that contains a CSV file that holds the key.
	// The CSV file should have English Letter, Average Frequency, and Key Values Start as columns.
	Key(std::istream&);
	// This constructor allows you to specify the column headings in the CSV file.
	// They are, in order: English Letter, Average Frequency, and Key Values Start
	Key(std::istream&, const std::string&, const std::string&, const std::string&);
	// This function returns false if any of the internal error flags are set.
	operator bool() const;
	// Copy and move constructors
	Key(const Key&);
	Key(Key&&);
	// Pass a char to this function to get an encrypted value. It is assumed that there are no errors (check operator bool).
	// If a character cannot be encrypted (i.e. the key does not have a key value for it), -1 is returned.
	int encrypt(char) const;
private:
	std::map<char, MessageCharacter> charToKeyValues;
	bool readKeyFileSuccess;
	bool noDuplicateColumnHeadings;
	bool allColumnsFound;
	bool allColumnsCorrectDataType;
	bool allColumnsInRange;
	bool allRowsValidWidth;
	static bool explode(const std::string&, std::vector<std::string>&, char=',');
	static bool getlineAndExplode(std::istream&, std::vector<std::string>&, char=',');
};
