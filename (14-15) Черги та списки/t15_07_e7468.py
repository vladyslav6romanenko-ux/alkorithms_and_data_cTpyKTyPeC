import sys

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

    def print_list(self):
        curr = self.head
        first = True
        while curr:
            if not first:
                print(" ", end="")
            print(curr.data, end="")
            first = False
            curr = curr.next
        print()

    def reorder_list(self):
        if not self.head or not self.head.next or not self.head.next.next:
            return
        
        slow = self.head
        fast = self.head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            
        head2 = slow.next
        slow.next = None
        
        prev = None
        curr = head2
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        head2 = prev
        
        p1 = self.head
        p2 = head2
        while p2:
            nxt1 = p1.next
            nxt2 = p2.next
            
            p1.next = p2
            p2.next = nxt1
            
            p1 = nxt1
            p2 = nxt2
            
        t = self.head
        while t and t.next:
            t = t.next
        self.tail = t

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    
    lst = LinkedList()
    for i in range(1, n + 1):
        lst.append(int(input_data[i]))
        
    lst.reorder_list()
    lst.print_list()

if __name__ == '__main__':
    main()
