#include <iostream>
#include <vector>

using namespace std;

int custom_lower_bound(const vector<int>& a, int x) {
    int left = 0;
    int right = a.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int custom_upper_bound(const vector<int>& a, int x) {
    int left = 0;
    int right = a.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int q;
            cin >> q;
            int lower = custom_lower_bound(a, q);
            int upper = custom_upper_bound(a, q);
            cout << (upper - lower) << "\n";
        }
    }
    return 0;
}
