class Node:
    def __init__(self, item):
        self.item = item
        self.next = None


class Queue:
    def __init__(self):
        self.front = None
        self.back = None

    def empty(self):
        return self.front is None and self.back is None

    def enqueue(self, item):
        new_node = Node(item)
        if self.empty():
            self.front = new_node
        else:
            self.back.next = new_node
        self.back = new_node

    def dequeue(self):
        if self.empty():
            raise Exception("Queue: 'dequeue' applied to empty container")
        current_front = self.front
        item = current_front.item
        self.front = self.front.next
        del current_front
        if self.front is None:
            self.back = None
        return item


n = int(input())
cards1 = input().split()
cards2 = input().split()

q1 = Queue()
q2 = Queue()

for c in cards1:
    q1.enqueue(int(c))
for c in cards2:
    q2.enqueue(int(c))

moves = 0
MAX_MOVES = 200000

while not q1.empty() and not q2.empty() and moves < MAX_MOVES:
    c1 = q1.dequeue()
    c2 = q2.dequeue()
    moves += 1

    if c1 == 0 and c2 == n - 1:
        q1.enqueue(c1)
        q1.enqueue(c2)
    elif c2 == 0 and c1 == n - 1:
        q2.enqueue(c1)
        q2.enqueue(c2)
    elif c1 > c2:
        q1.enqueue(c1)
        q1.enqueue(c2)
    else:
        q2.enqueue(c1)
        q2.enqueue(c2)

if moves == MAX_MOVES and not q1.empty() and not q2.empty():
    print("draw")
elif q2.empty():
    print("first", moves)
else:
    print("second", moves)
