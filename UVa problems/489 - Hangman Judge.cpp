//#define Q489
#ifdef Q489
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string word;
	string guess;
	vector<bool>founds;
	char * pch;
	int round;
	int lose;
	bool win;


	while (cin >> round && round != -1) {
		cout << "Round " << round << endl;
		win = false;
		word.clear();
		guess.clear();
		founds.clear();
		lose = 0;
		cin >> word;
		cin >> guess;
		for (int i = 0; i < guess.length(); i++) {
			for (int j = i + 1; j < guess.length(); j++) {
				if (guess[i] == guess[j]) {
					guess.erase(guess.begin() + j);
				}
			}
		}
		//sort(guess.begin(), guess.end());
		//guess.erase(unique(guess.begin(), guess.end()), guess.end());
		cerr << guess << endl;
		for (size_t i = 0; i < guess.length(); i++)
		{
			founds.resize(word.size());
			int found = word.find(guess[i]);
			if (found == -1)
				++lose;
			if (lose >= 7 && win == false) {
				cout << "You lose." << endl;
				break;
			}
			while (found != -1) {
				founds[found] = true;
				for (int i = 0; i < founds.size(); i++) {
					if (founds[i] != true) break;
					if (i == founds.size() - 1) {
						cout << "You win." << endl;
						win = true;
					}
				}
				found = word.find(guess[i], found + 1);
			}

		}
		if (lose < 7 && win == false) {
			for (size_t i = 0; i < founds.size(); i++)
			{
				if (founds[i] != true) {
					cout << "You chickened out." << endl;
					break;
				}
				if (i == founds.size() - 1)
					cout << "You win.\n";
			}

		}
	}




	return 0;
}



#endif 