//#define Q11498
#ifdef Q11498
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t,n,m,x,y;
	while (cin >> t) {
		if (t == 0)
			break;
		cin >> n >> m;
		while (t--) {
			cin >> x >> y;
			if (x - n > 0 && y - m > 0)
				cout << "NE" << endl;
			else if (x - n > 0 && y - m < 0)
				cout << "SE" << endl;
			else if (x - n < 0 && y - m > 0)
				cout << "NO" << endl;
			else if (x - n < 0 && y - m < 0)
				cout << "SO" << endl;
			else if (x - n == 0 || y - m == 0)
				cout << "divisa" << endl;


		}
	}



	return 0;
}

#endif 