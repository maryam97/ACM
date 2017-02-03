//#define p12060
#ifdef p12060

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int digit(int n) {
    int s = 0;
    while (n / 10 != 0)
        n /= 10, s++;
    return s+1;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int sum;
    int tc = 1;
    int n; while (cin >> n && n) {
        cout << "Case " << tc++ << ":\n";
        sum = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            sum += x;
        }
        if (sum%n == 0) {
            if (sum / n >= 0)
                cout << sum / n << endl;
            else cout << "- " << abs(sum / n)<<endl;
        }
        else {
            int f = sum%n;
            int g = gcd(abs(f), n);
            f /= g;
            int m = n;
            n /= g;
            int d = digit(abs(sum) / m) + digit(n) - 1;
            if (sum / m > 0) {
                cout << setw(d+1) << f << endl;
                if (sum/m !=0)
                    cout << sum / m;
                for (int i = 0; i < digit(n); i++) cout << "-"; cout << endl;
                cout << setw(d+1) << n << endl;
            }
            else if (sum / m == 0) {

                if (f < 0) {
                    cout << setw(d + 3) << abs(f) << endl;
                    cout << "- ";
                    for (int i = 0; i < digit(n); i++) cout << "-"; cout << endl;
                    cout << setw(d + 3) << n << endl;
                }
                else {
                    cout << setw(d + 1) << abs(f) << endl;
                    for (int i = 0; i < digit(n); i++) cout << "-"; cout << endl;
                    cout << setw(d + 1) << n << endl;
                }
            }
            else {
                cout << setw(d + 3) << abs(f) << endl;
                if (abs(sum / m) != 0) cout << "- ", cout << abs(sum / m);
                for (int i = 0; i < digit(n); i++) cout << "-"; cout << endl;
                cout << setw(d + 3) << n << endl;
            }
        }
    }


    return 0;
}

#endif
