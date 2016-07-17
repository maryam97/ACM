//#define Q10141
#ifdef Q10141
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int n,p;
	string req,chert,met,name;
	int r; float d; float comp,count=0;
	vector<float>prices;
	vector<float>comps;
	vector<string>names;
	vector<int>index,pindex;
	int k = 0,f = 0; float maxComp; float minPrice;
	while (cin >> n >> p) {
		k = 0;
		index.clear();
		pindex.clear();
		comps.clear();
		prices.clear();
		names.clear();
		if (n == 0 && p == 0)
			break;

		getline(cin, chert);
		++count;
		if (count != 1)
			cout << endl;
		for (int i = 0; i < n; i++)
		{
			getline(cin,req);
		}
		//getline(cin, chert);
		for (int j = 0; j < p;j++) {

			getline(cin,name);
			names.push_back(name);
			cin >> d >> r;
			prices.push_back(d);
			comp = ((float)r / (float)n);
			comps.push_back(comp);
			//cerr << "r : "<< r <<" n :"<<n<< " r/n : " << r / n << endl;
			//cerr << " comp " << count << ": " << comp << endl;
			getline(cin, chert);
			for (size_t i = 0; i < r; i++)
			{
				getline(cin,met);
			}

		}

		//cerr << "Comps size:" << comps.size() << endl;
		maxComp = comps[0]; 
		for (int k = 1; k < comps.size(); k++)
		{
			if (comps[k] > maxComp) {
				maxComp = comps[k];

			}
		}
		//cerr << "Comps size:" << comps.size() << endl;
		for (int h = 0; h < comps.size(); h++)
		{
			if (comps[h] == maxComp) {
				k++;
				index.push_back(h);
			}

		}

		if (k == 1) {
			cout << "RFP #" << count << endl;
			cout << names[index[0]] << endl;
		}
		else if (k > 1) {
			minPrice = prices[index[0]];
			for (size_t i = 0; i < index.size(); i++)
			{
				if (prices[index[i]] < minPrice)
					minPrice = prices[index[i]];
			}
			for (int h = 0; h < index.size(); h++)
			{
				if (prices[index[h]] == minPrice) {
					f++;
					pindex.push_back(index[h]);
				}

			}
			if (f == 1) {
				cout << "RFP #" << count << endl;
				cout << names[pindex[0]] << endl;
			}
			else if (f > 1) {
				cout << "RFP #" << count << endl;
				cout << names[pindex[0]] << endl;
			}
		}
		
	}
	

	return 0;
}



#endif 