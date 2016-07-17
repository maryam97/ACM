#define Q195
#ifdef Q195
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
#define INF (int)1e9
#define int64 long long
using namespace std;

bool func(char a, char b) {
	if (tolower(a) == tolower(b)) {
		return (a < b);
	}
	else return (tolower(a) < tolower(b));
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;

	while (t--) {
		string word;
		cin >> word;
		
		sort(word.begin(), word.end(),func);
		cout << word << endl;
		while (next_permutation(word.begin(), word.end(), func)) {
			cout << word << endl;
		}
		//cerr << endl;
	}


	return 0;
}


#endif 