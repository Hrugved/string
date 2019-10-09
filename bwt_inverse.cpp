#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int letterToIndex(char letter)
{
	switch (letter)
	{
	case 'A': return 1; break;
	case 'C': return 2; break;
	case 'G': return 3; break;
	case 'T': return 4; break;
	case '$': return 0;
	}
}

string InverseBWT(const string& bwt) {
	vector<int> count(bwt.size()); // tells no. of times the (corresponding char in bwt)char appears till that position
	vector<int> cnt(5); // freq-counter
	vector<int> firstOccurence(5); // in first column
	
	int index;
	for (int i = 0; i < bwt.length(); i++) {
		index = letterToIndex(bwt[i]);
		count[i] = (++cnt[index]);
	}

	// count sort
	int fo=0;
	for (int i = 0; i < 5; i++) {
		firstOccurence[i] = fo;
		fo += cnt[i];
	}

	int fc_index = 0; // $
	string text = "$";
	for (int i = 0; i < bwt.length()-1; i++) {
		text = bwt[fc_index] + text;
		fc_index = firstOccurence[letterToIndex(bwt[fc_index])] + (count[fc_index] - 1);
	}

	return text;
}

int main() {
	string bwt;
	cin >> bwt;
	cout << InverseBWT(bwt) << endl;
	return 0;
}
