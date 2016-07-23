#define Q793
#ifdef Q793
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

void buildUF(int N, vector<int>&p) {

	p.assign(N + 5, 0);

	for (size_t i = 1; i < N + 1; i++)
	{
		p[i] = i;
	}
}
int FindSet(int i, vector<int> &p) {
	return (p[i] == i) ? i : (p[i] = FindSet(p[i], p));
}
bool isSameSet(int i, int j, vector <int>&p) {
	return FindSet(i, p) == FindSet(j, p);
}
void unionSet(int i, int j, vector<int>&p) {
	if (!isSameSet(i, j, p)) {
		int x = FindSet(i, p), y = FindSet(j, p);
		if (x > y)
			p[y] = x;
		else {
			p[x] = y;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	int tc; cin >> tc; int x = tc;
	int num, b, c;
	char a;
	string str, chert;
	int correct, wrong;
	vector<int> p;

	while (tc--) {
		p.clear();
		cin >> num; 
		correct = 0;
		wrong = 0;
		getline(cin, chert);
		buildUF(num, p);
		while (getline(cin, str) && str.length() != 0) {
		
			stringstream ss(str);
			char tmpCh; ss >> tmpCh; int first, sec;
			ss >> first >> sec;
			if (str[0] == 'c')
				unionSet(first, sec, p);
			else if (str[0] == 'q') {
				if (isSameSet(first, sec, p))
					++correct;
				else
					++wrong;
			}
		}

		cout << correct << "," << wrong << endl;
		if (tc != 0)
			cout << endl;

	}


	return 0;
}

#endif