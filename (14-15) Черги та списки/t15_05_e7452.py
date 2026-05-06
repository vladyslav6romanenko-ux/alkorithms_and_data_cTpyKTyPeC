import sys

# Збільшуємо ліміт рекурсії для глибокого виводу
sys.setrecursionlimit(200000)

class Node:
    def __init__(self, data=0, next_node=None):
        self.data = data
        self.next = next_node

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, val):
        new_node = Node(val)
        if not self.head:
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

    def print_direct(self):
        curr = self.head
        first = True
        while curr:
            if not first:
                print(" ", end="")
            print(curr.data, end="")
            first = False
            curr = curr.next
        print()

    def print_reverse(self):
        self._print_rev(self.head)
        print()

    def _print_rev(self, node):
        if not node:
            return
        self._print_rev(node.next)
        print(node.data, end="")
        if node != self.head:
            print(" ", end="")

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    
    lst = LinkedList()
    for i in range(1, n + 1):
        lst.append(int(input_data[i]))
        
    lst.print_direct()
    lst.print_reverse()

if __name__ == '__main__':
    main()
