#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DictHash {
private:
    struct Node {
        string key;
        bool is_used;
        bool occupied;
        Node() : is_used(false), occupied(false) {}
    };
    
    vector<Node> table;
    int capacity;
    int total_words;
    int used_words;

    unsigned int get_hash(const string& s) const {
        unsigned int h = 0;
        for (char c : s) {
            h = (h * 31 + c) % capacity;
        }
        return h;
    }

public:
    DictHash(int cap = 500009) { 
        capacity = cap;
        table.resize(capacity);
        total_words = 0;
        used_words = 0;
    }

    void add_dict_word(const string& key) {
        unsigned int idx = get_hash(key);
        while (table[idx].occupied) {
            if (table[idx].key == key) return;
            idx = (idx + 1) % capacity;
        }
        table[idx].key = key;
        table[idx].occupied = true;
        table[idx].is_used = false;
        total_words++;
    }

    bool check_and_mark_used(const string& key) {
        unsigned int idx = get_hash(key);
        while (table[idx].occupied) {
            if (table[idx].key == key) {
                if (!table[idx].is_used) {
                    table[idx].is_used = true;
                    used_words++;
                }
                return true;
            }
            idx = (idx + 1) % capacity;
        }
        return false;
    }

    bool all_used() const {
        return used_words == total_words;
    }
};

char to_lower_char(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    return c;
}

bool is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    DictHash dict(500009);
    string w;
    
    for (int i = 0; i < n; ++i) {
        cin >> w;
        string clean_w = "";
        for (char c : w) {
            if (is_alpha(c)) clean_w += to_lower_char(c);
        }
        if (!clean_w.empty()) {
            dict.add_dict_word(clean_w);
        }
    }

    bool has_unknown = false;
    char c;
    string cur = "";
    
    while (cin >> noskipws >> c) {
        if (is_alpha(c)) {
            cur += to_lower_char(c);
        } else {
            if (!cur.empty()) {
                if (!dict.check_and_mark_used(cur)) {
                    has_unknown = true;
                }
                cur = "";
            }
        }
    }
    if (!cur.empty()) {
        if (!dict.check_and_mark_used(cur)) {
            has_unknown = true;
        }
    }

    if (has_unknown) {
        cout << "Some words from the text are unknown.\n";
    } else if (!dict.all_used()) {
        cout << "The usage of the vocabulary is not perfect.\n";
    } else {
        cout << "Everything is going to be OK.\n";
    }

    return 0;
}
