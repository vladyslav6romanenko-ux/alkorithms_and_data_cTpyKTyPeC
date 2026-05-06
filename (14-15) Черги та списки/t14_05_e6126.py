import sys

class Node:
    def __init__(self, item):
        self.item = item
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.back = None
        self._size = 0

    def empty(self):
        return self.front is None

    def push(self, item):
        n = Node(item)
        if self.empty():
            self.front = n
        else:
            self.back.next = n
        self.back = n
        self._size += 1
        print("ok")

    def pop(self):
        if self.empty():
            print("error")
            return
        item = self.front.item
        self.front = self.front.next
        if self.front is None:
            self.back = None
        self._size -= 1
        print(item)

    def get_front(self):
        if self.empty():
            print("error")
        else:
            print(self.front.item)

    def size(self):
        print(self._size)

    def clear(self):
        self.front = None
        self.back = None
        self._size = 0
        print("ok")

def main():
    data = sys.stdin.read().split()
    q = Queue()
    i = 0
    while i < len(data):
        cmd = data[i]
        i += 1
        if cmd == "exit":
            print("bye")
            break
        elif cmd == "push":
            q.push(int(data[i]))
            i += 1
        elif cmd == "pop":
            q.pop()
        elif cmd == "front":
            q.get_front()
        elif cmd == "size":
            q.size()
        elif cmd == "clear":
            q.clear()

if __name__ == '__main__':
    main()
