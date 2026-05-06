#include <iostream>
#include <vector>

using namespace std;

struct Robot {
    int main_num;
    int aux_num;
};

void merge(vector<Robot>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<Robot> L(n1);
    vector<Robot> R(n2);
    
    for (int i = 0; i < n1; ++i) L[i] = a[left + i];
    for (int j = 0; j < n2; ++j) R[j] = a[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {

        if (L[i].main_num <= R[j].main_num) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }
    
    while (i < n1) {
        a[k++] = L[i++];
    }
    
    while (j < n2) {
        a[k++] = R[j++];
    }
}

void merge_sort(vector<Robot>& a, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<Robot> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].main_num >> a[i].aux_num;
    }
    
    merge_sort(a, 0, n - 1);
    
    for (int i = 0; i < n; ++i) {
        cout << a[i].main_num << " " << a[i].aux_num << "\n";
    }
    
    return 0;
}
