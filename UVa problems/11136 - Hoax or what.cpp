#define Q11136
#ifdef Q11136
#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tc;
	int number; int amount; long long int paid = 0;
	multiset<int>amounts;

	while (cin >> tc && tc != 0) {
		amounts.clear();
		paid = 0;
		while (tc--) {
			cin >> number;
			while (number--) {
				cin >> amount;
				amounts.insert(amount);
			}
			multiset<int>::iterator it1 = amounts.begin(),it3 = amounts.end();
			multiset<int>::reverse_iterator it2 = amounts.rbegin(); 
			paid += (*it2 - *it1);
			amounts.erase(it1); --it3;
			amounts.erase(it3);
			if (tc == 0) {
				cerr << endl;
				cout << paid << endl;
				cerr << endl;
			}
		}
	}

	return 0;
}

#endif 