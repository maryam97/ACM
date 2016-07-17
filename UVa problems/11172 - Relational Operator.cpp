//#define Q11172
#ifdef Q11172
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int k; cin >> k;
	int a, b;
	while (k--) {
		cin >> a >> b;
		if (a > b)
			cout << ">" << endl;
		else if (a < b)
			cout << "<" << endl;
		else if (a == b)
			cout << "=" << endl;
	}


	return 0;
}

#endif 