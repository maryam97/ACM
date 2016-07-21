//#define Q10954
#ifdef Q10954
#include <iostream>
#include<algorithm>
#include<vector>
#include <queue>
#include<functional>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	vector<int>numbers;
	priority_queue<int, vector<int>, greater<int>>pq;
	int num,amount,cost,ans;
	while (cin >> num && num) {
	 //numbers.clear();
		cost = 0; ans = 0;
		for (int i = 0; i < num;i++) {
			cin >> amount;
			pq.push(amount);
		}
		while (pq.size()!=1) {
			int least = pq.top();
			pq.pop();
			int sec = pq.top();
			pq.pop();
			cost = least + sec;
			pq.push(cost);
			ans += cost;
		}
		pq.pop();
		//cerr << "size: " << pq.size() << endl;
		cout << ans << endl;
	}


	return 0;
}


#endif
//sort(numbers.begin(), numbers.end());
//for (size_t i = 0; i < num; i++)
//{
//	//cerr << numbers[i] << " "; if (i == num - 1)cerr << endl;
//	cost += numbers[i];
//	if (i > 0)
//		ans += cost;
//	
//}