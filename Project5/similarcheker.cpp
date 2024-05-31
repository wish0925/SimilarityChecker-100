#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class similarChecker {
public:
	similarChecker(string finput, string sinput)
		: first(finput), second(sinput) {}

	void checkLength() {
		vector<int> length;
		
		length = findWhichOneLong();

		lengthScore = 60 * (1.00 - ((float)(length[0] - length[1]) / length[1]));

		if (lengthScore < 0) lengthScore = 0;
	}

	int getLengthScore() {
		return lengthScore;
	}

private:
	vector<int> findWhichOneLong() {
		vector<int> length;

		if (first.length() >= second.length()) {
			length.push_back(first.length());
			length.push_back(second.length());
		}
		else {
			length.push_back(second.length());
			length.push_back(first.length());
		}

		return length;
	}

	string first;
	string second;

	int lengthScore = 0;
	int alphaScore = 0;
};