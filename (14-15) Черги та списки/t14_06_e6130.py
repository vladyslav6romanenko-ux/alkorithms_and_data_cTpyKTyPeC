import sys

class Node:
    def __init__(self, item):
        self.item = item
        self.prev = None
        self.next = None

class Deque:
    def __init__(self):
        self.front = None
        self.back = None
        self._size = 0

    def empty(self):
        return self.front is None

    def push_front(self, item):
        n = Node(item)
        n.next = self.front
        if not self.empty():
            self.front.prev = n
        else:
            self.back = n
        self.front = n
        self._size += 1
        print("ok")

    def push_back(self, item):
        n = Node(item)
        n.prev = self.back
        if not self.empty():
            self.back.next = n
        else:
            self.front = n
        self.back = n
        self._size += 1
        print("ok")

    def pop_front(self):
        if self.empty():
            print("error")
            return
        item = self.front.item
        self.front = self.front.next
        if self.front is None:
            self.back = None
        else:
            self.front.prev = None
        self._size -= 1
        print(item)

    def pop_back(self):
        if self.empty():
            print("error")
            return
        item = self.back.item
        self.back = self.back.prev
        if self.back is None:
            self.front = None
        else:
            self.back.next = None
        self._size -= 1
        print(item)

    def get_front(self):
        if self.empty():
            print("error")
        else:
            print(self.front.item)

    def get_back(self):
        if self.empty():
            print("error")
        else:
            print(self.back.item)

    def size(self):
        print(self._size)

    def clear(self):
        self.front = None
        self.back = None
        self._size = 0
        print("ok")

def main():
    data = sys.stdin.read().split()
    dq = Deque()
    i = 0
    while i < len(data):
        cmd = data[i]
        i += 1
        if cmd == "exit":
            print("bye")
            break
        elif cmd == "push_front":
            dq.push_front(int(data[i]))
            i += 1
        elif cmd == "push_back":
            dq.push_back(int(data[i]))
            i += 1
        elif cmd == "pop_front":
            dq.pop_front()
        elif cmd == "pop_back":
            dq.pop_back()
        elif cmd == "front":
            dq.get_front()
        elif cmd == "back":
            dq.get_back()
        elif cmd == "size":
            dq.size()
        elif cmd == "clear":
            dq.clear()

if __name__ == '__main__':
    main()
