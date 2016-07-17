//#define Q11727
#ifdef Q11727
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int& sort(int*arr) {
	int temp;
	for (int i = 0; i < 3; i++) {
		for (size_t j = 0;j < 3-i-1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				
			}

		}
	}
	return *arr;
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	int x, y, z;
	for (int i = 0; i < t;i++) {
		cin >> x >> y >> z;
		int xyz[3] = { x,y,z };
		sort(xyz);
		//xyz
		cout << "Case "<< i+1 << ": "<<xyz[1]<<endl;
	}


	return 0;
}


#endif