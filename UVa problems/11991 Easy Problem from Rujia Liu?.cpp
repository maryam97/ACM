//11991 Easy Problem from Rujia Liu?
//#define Q11991
#ifdef Q11991

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
    int k,num;
    vector<int>nums;
    while(n--) {
        cin >> num;
        nums.push_back(num);
    }
    int occur =0;
    bool ok = false;
    while (m --){
        cin >> k >> num;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == num) ++occur;
            if(occur == k){
                cout << i+1 <<endl;
                ok = true;
                break;
            }
            if(!ok) cout << "0\n";
        }
    }
}
}


#endif