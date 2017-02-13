#include <sstream>
#include "Key.h"
using namespace std;

Key::Key(istream& keyfile, const string& COLUMN_CHAR, const string& COLUMN_FREQ, const string& COLUMN_START){
	// Check that the key file is ready for reading.
	if(keyfile){
		readKeyFileSuccess = true;
		// Read the header row for column headings.
		vector<string> rowExploded;
		getlineAndExplode(keyfile, rowExploded);
		const size_t headerRowSize = rowExploded.size();
		// Find the offsets (from the left-most column) of the three required columns.
		size_t columnCharOffset, columnFreqOffset, columnStartOffset;
		columnCharOffset = columnFreqOffset = columnStartOffset = headerRowSize;
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
			}else if(rowExploded[i] == COLUMN_FREQ){
				if(columnFreqOffset == headerRowSize){
					columnFreqOffset = i;
				}else{
					noDuplicateColumnHeadings = false;
					return;
				}
			}else if(rowExploded[i] == COLUMN_START){
				if(columnStartOffset == headerRowSize){
					columnStartOffset = i;
				}else{
					noDuplicateColumnHeadings = false;
					return;
				}
			}
		}
		// Check that the three required columns are present.
		if(columnCharOffset < headerRowSize && columnFreqOffset < headerRowSize && columnStartOffset < headerRowSize){
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
				// The start and frequency columns must be converted to int.
				int start, freq;
				try{
					start = stoi(rowExploded[columnStartOffset]); // Requires C++ 2011
					freq = stoi(rowExploded[columnFreqOffset]);
				}catch(const invalid_argument& e){
					allColumnsCorrectDataType = false;
					return;
				}catch(const out_of_range& e){
					allColumnsInRange = false;
					return;
				}
				// Check that the letter column is really only one character surrounded by single quotes.
				if(rowExploded[columnCharOffset].length() == 3 && rowExploded[columnCharOffset][0] == '\'' && rowExploded[columnCharOffset][2] == '\''){
					// All checks passed. Add this row to the map.
					charToKeyValues.emplace(rowExploded[columnCharOffset][1], MessageCharacter(start, freq));
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
Key::Key(istream& keyfile) : Key(keyfile, "English Letter", "Average Frequency", "Key Values Start") {}
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
	auto mci = charToKeyValues.find(c);
	if(mci == charToKeyValues.end()){
		return -1;
	}
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
	if(getline(keyfile, rowstr)){
		return explode(rowstr, result, comma);
	}
	return false;
}
