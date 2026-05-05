#include <iostream>
#include <vector>

using namespace std;

bool custom_binary_search(const vector<int>& a, int x) {
    int left = 0;
    int right = a.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return true;
        }
        if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
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
            if (custom_binary_search(a, q)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
