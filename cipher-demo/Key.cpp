#include <sstream>
#include "Key.h"
using namespace std;

Key::Key(istream& keyfile, const string& COLUMN_CHAR, const string& COLUMN_KEY_VALUES){
	// Check that the key file is ready for reading.
	if(keyfile){
		readKeyFileSuccess = true;
		// Read the header row for column headings.
		vector<string> rowExploded;
		getlineAndExplode(keyfile, rowExploded);
		const size_t headerRowSize = rowExploded.size();
		// Find the offsets (from the left-most column) of the three required columns.
		size_t columnCharOffset, columnKeyValuesOffset;
		columnCharOffset = columnKeyValuesOffset = headerRowSize;
		noDuplicateColumnHeadings = true;
		for(size_t i = 0; i < headerRowSize; ++i){
			if(rowExploded[i] == COLUMN_CHAR){
				if(columnCharOffset == headerRowSize){
					columnCharOffset = i;
				}else{
					// This column has the same heading as another column.
					noDuplicateColumnHeadings = false;
					return;
				}
			}else if(rowExploded[i] == COLUMN_KEY_VALUES){
				if(columnKeyValuesOffset == headerRowSize){
					columnKeyValuesOffset = i;
				}else{
					noDuplicateColumnHeadings = false;
					return;
				}
			}
		}
		// Check that the three required columns are present.
		if(columnCharOffset < headerRowSize && columnKeyValuesOffset < headerRowSize){
			allColumnsFound = true;
			// Finally, we can begin reading the rest of the key file into a map.
			allRowsValidWidth = true;
			allColumnsCorrectDataType = true;
			allColumnsInRange = true;
			rowExploded.clear();
			while(getlineAndExplode(keyfile, rowExploded)){
				// Check that this row has the same or more columns than the header row.
				if(rowExploded.size() < headerRowSize){
					allRowsValidWidth = false;
					return;
				}
				// The key values column must be exploded; it is space-delimited.
				vector<string> keyValuesStr;
				explode(rowExploded[columnKeyValuesOffset], keyValuesStr, ' ');
				if(keyValuesStr.size() == 0){
					allColumnsCorrectDataType = false;
					return;
				}
				// Convert the key values from strings to ints.
				vector<int> keyValues;
				keyValues.reserve(keyValuesStr.size());
				for(const string& s : keyValuesStr){
					try{
						keyValues.push_back(stoi(s)); // Requires C++ 2011
					}catch(const invalid_argument& e){
						allColumnsCorrectDataType = false;
						return;
					}catch(const out_of_range& e){
						allColumnsInRange = false;
						return;
					}
				}
				// Check that the letter column is really only one character surrounded by single quotes.
				if(rowExploded[columnCharOffset].length() == 3 && rowExploded[columnCharOffset][0] == '\'' && rowExploded[columnCharOffset][2] == '\''){
					// All checks passed. Add this row to the map.
					charToKeyValues.emplace(rowExploded[columnCharOffset][1], MessageCharacter(move(keyValues)));
				}else{
					allColumnsCorrectDataType = false;
					return;
				}
				rowExploded.clear();
			}
		}else{
			allColumnsFound = false;
		}
	}else{
		readKeyFileSuccess = false;
	}
}
Key::Key(istream& keyfile) : Key(keyfile, "English Letter", "Key Values (Space Delimited)") {}
Key::Key(const Key& rhs)
: charToKeyValues(rhs.charToKeyValues), readKeyFileSuccess(rhs.readKeyFileSuccess),
noDuplicateColumnHeadings(rhs.noDuplicateColumnHeadings), allColumnsFound(rhs.allColumnsFound),
allColumnsCorrectDataType(rhs.allColumnsCorrectDataType), allColumnsInRange(rhs.allColumnsInRange),
allRowsValidWidth(rhs.allRowsValidWidth)
{}
Key::Key(Key&& rhs)
: charToKeyValues(move(rhs.charToKeyValues)), readKeyFileSuccess(rhs.readKeyFileSuccess),
noDuplicateColumnHeadings(rhs.noDuplicateColumnHeadings), allColumnsFound(rhs.allColumnsFound),
allColumnsCorrectDataType(rhs.allColumnsCorrectDataType), allColumnsInRange(rhs.allColumnsInRange),
allRowsValidWidth(rhs.allRowsValidWidth)
{}
int Key::encrypt(char c) const {
	// Get an iterator to the MessageCharacter in the map.
	auto mci = charToKeyValues.find(c);
	if(mci == charToKeyValues.end()){
		// This character is not in this key, so it cannot be encrypted.
		return -1;
	}
	// The assignment sheet says that the key value will be chosen by an undisclosed scheduling algorithm,
	// but the best that we have here is a random choice.
	return mci->second.getRandomCipherValue();
}
Key::operator bool() const {
	return readKeyFileSuccess && noDuplicateColumnHeadings && allColumnsFound && allColumnsCorrectDataType && allColumnsInRange && allRowsValidWidth;
}
bool Key::explode(const string& rowstr, vector<string>& result, char comma){
	// This function converts a string of comma-separated values into a vector.
	// It returns true on success and false on failure.
	// If the vector is not empty, the values are pushed onto the end.
	stringstream ss(rowstr);
	if(!ss){
		return false;
	}
	string cell;
	while(getline(ss, cell, comma)){
		result.push_back(move(cell));
	}
	return true;
}
bool Key::getlineAndExplode(istream& keyfile, vector<string>& result, char comma){
	string rowstr;
	return getline(keyfile, rowstr) && explode(rowstr, result, comma);
}
