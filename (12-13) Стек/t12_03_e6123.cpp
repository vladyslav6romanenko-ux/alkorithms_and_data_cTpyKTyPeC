#include <iostream>
#include <string>

using namespace std;

struct Node {
    int item;
    Node* next;
};

class Stack {
    Node* top_node = nullptr;
    int sz = 0;

public:
    void push(int item) {
        top_node = new Node{item, top_node};
        sz++;
        cout << "ok\n";
    }

    void pop() {
        if (!top_node) {
            cout << "error\n";
            return;
        }
        Node* temp = top_node;
        cout << temp->item << "\n";
        top_node = top_node->next;
        delete temp;
        sz--;
    }

    void back() {
        if (!top_node) cout << "error\n";
        else cout << top_node->item << "\n";
    }

    void size() {
        cout << sz << "\n";
    }

    void clear() {
        while (top_node) {
            Node* temp = top_node;
            top_node = top_node->next;
            delete temp;
        }
        sz = 0;
        cout << "ok\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Stack s;
    string op;
    while (cin >> op && op != "exit") {
        if (op == "push") {
            int n;
            cin >> n;
            s.push(n);
        } else if (op == "pop") {
            s.pop();
        } else if (op == "back") {
            s.back();
        } else if (op == "size") {
            s.size();
        } else if (op == "clear") {
            s.clear();
        }
    }
    cout << "bye\n";
    
    return 0;
}
