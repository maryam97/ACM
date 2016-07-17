//#define Q591
#ifdef Q591
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int t; int number; int sum = 0; int avr = 0; int count = 0; int set=0;
	vector<int>stack;
	while (cin >> t && t != 0){
		stack.clear();
		count = 0; avr = 0; sum = 0;
		++set;
		for (size_t i = 0; i < t; i++)
		{
			cin >> number;
			stack.push_back(number);
			sum += number;
		}
		avr = sum / t;
		sort(stack.begin(), stack.end());
		for (size_t i = 0; i < t; i++)
		{
			if (stack[i]>avr)
				count += ( stack[i] -avr);
		}
	}
	cout << "Set #" << set << endl;
	cout << "The minimum number of moves is " << count << "." << endl;


	return 0;
}

#endif 