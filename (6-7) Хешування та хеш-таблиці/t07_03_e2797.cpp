#include <iostream>
#include <vector>

using namespace std;

class ContactsHash {
private:
    vector<int> table;
    vector<bool> occupied;
    int capacity;
    int unique_count;

public:
    ContactsHash(int cap = 300007) { 
        capacity = cap;
        table.resize(capacity, 0);
        occupied.resize(capacity, false);
        unique_count = 0;
    }

    void add(int number) {
        int idx = number % capacity;
        while (occupied[idx]) {
            if (table[idx] == number) return; 
            idx = (idx + 1) % capacity;       
        }
        table[idx] = number;
        occupied[idx] = true;
        unique_count++;
    }

    int get_unique() const {
        return unique_count;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (cin >> n) {
        ContactsHash ht(300007);
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            ht.add(num);
        }
        cout << ht.get_unique() << "\n";
    }
    return 0;
}
