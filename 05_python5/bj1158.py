class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class CircularList:
    def __init__(self):
        self.size = 0
        self.head = None

    def insert(self, prev_node, data):
        self.size += 1
        node = Node(data)

        if prev_node:
            node.next = prev_node.next
            prev_node.next = node

        else:
            node.next = node
            self.head = node

    def delete(self, prev_node):
        self.size -= 1

        if prev_node.next != self.head:
            prev_node.next = prev_node.next.next

        else:
            if prev_node != self.head:
                self.head = self.head.next
                prev_node.next = self.head

            else:
                self.head = None


n, k = map(int, input().split())
jo = CircularList()
jo.insert(None, 1)
for i in range(n, 1, -1):
    jo.insert(jo.head, i)
for _ in range(n-1):
    jo.head = jo.head.next
print('<', end='')
while jo.size > 1:
    for _ in range(k-1):
        jo.head = jo.head.next
    print(f"{jo.head.next.data}", end=', ')
    jo.delete(jo.head)
print(f"{jo.head.data}", end='>')
