#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return x * x + sqrt(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double c;
    if (cin >> c) {
        double l = 0.0, r = 1e5;
        for (int i = 0; i < 100; ++i) {
            double m = l + (r - l) / 2.0;
            if (f(m) < c) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << fixed << setprecision(6) << l << "\n";
    }
    return 0;
}
