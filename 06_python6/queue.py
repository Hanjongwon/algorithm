class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class Queue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def enqueue(self, data):
        node = Node(data)

        if self.size == 0:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            self.tail = node
        self.size += 1

    def dequeue(self):
        if self.size == 0:
            return None
        self.size -= 1
        self.head = self.head.next


n = int(input())
q = Queue()
for i in range(1, n+1):
    q.enqueue(i)

while q.size > 1:
    q.dequeue()
    q.tail.next = q.head
    q.tail = q.tail.next
    q.head = q.head.next
print(q.tail.data)

