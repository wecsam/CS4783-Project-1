#include <map>
class Bigrams {
public:
	// This map tells you the probability of the second character
	// given the first character. Access it as follows:
	// PROB_2_GIVEN_1[first character][second character]
	static const std::map<char, const std::map<char, double>> PROB_2_GIVEN_1;
};
