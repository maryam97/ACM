//#define Q00599
#ifdef Q00599
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include<string>
#include <stack>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	int n,cont, components,point;
	cin >> n;
	string a;
	vector<char> v;
	set<char>ver;
	for (int i = 0; i < n; i++) {
		cont = 0;
		while (cin >> a) {
			if (a[0] == '*')
				break;
			ver.insert(a[1]);
			ver.insert(a[3]);
			cont++;
		}
		cin >> a;
		for (int j = 0; j < a.size(); j += 2) {
			v.push_back(a[j]);
		}
		point = v.size() - ver.size();
		components = v.size() - cont;
		cout << "There are " << components - point << " tree(s) and " << point << " acorn(s).\n";
		v.clear();
		ver.clear();
	}

}

#endif 