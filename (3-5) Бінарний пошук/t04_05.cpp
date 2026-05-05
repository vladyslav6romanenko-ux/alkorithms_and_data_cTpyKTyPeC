#include <iostream>
#include <iomanip>

using namespace std;

double f(double x) {
    return x * x * x + 4.0 * x * x + x - 6.0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double l = 0.0, r = 2.0;
    for (int i = 0; i < 100; ++i) {
        double m = l + (r - l) / 2.0;
        if (f(m) < 0) {
            l = m;
        } else {
            r = m;
        }
    }
    
    cout << "x = " << fixed << setprecision(6) << l << "\n";
    return 0;
}
