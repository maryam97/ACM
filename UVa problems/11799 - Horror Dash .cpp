//#define Q11799
#ifdef Q11799
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int t; cin >> t;
	int tt;
	vector<int> num;
	int number;
	for (size_t i = 0; i < t; i++)
	 {
		num.clear();
		cin >> tt;
		while (tt--) {
			cin >> number;
			num.push_back(number);
		}
		sort(num.rbegin(), num.rend());
	/*	for (size_t i = 0; i < num.size(); i++)
		{
			cerr << num[i] << endl;
		}
	*/
		cout << "Case " << i + 1 << ": " << num[0] << endl;

	}


	return 0;
}


#endif