#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int>& a, int left, int right) {
    if (left >= right) return;
    
    int pivot = a[left + (right - left) / 2];
    int i = left;
    int j = right;
    
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    
    if (left < j) quick_sort(a, left, j);
    if (i < right) quick_sort(a, i, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    quick_sort(a, 0, n - 1);
    
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}
