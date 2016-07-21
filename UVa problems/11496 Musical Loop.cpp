//#define Q11496
#ifdef Q11496
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int num,sig;
	vector<int>signals;
	int peak;
	while (cin >> num && num) {
		signals.clear();
		peak = 0;
		while (num--) {
			cin >> sig;
			signals.push_back(sig);
		}
		signals.push_back(signals[0]);
		signals.push_back(signals[1]);

		for (int i = 1; i < signals.size() - 1; i++) {
			if (signals[i] > signals[i - 1] && signals[i] > signals[i + 1])
				++peak;
			if (signals[i] < signals[i - 1] && signals[i] < signals[i + 1])
				++peak;

		}
		cout << peak << endl;

	}


	return 0;
}

#endif 