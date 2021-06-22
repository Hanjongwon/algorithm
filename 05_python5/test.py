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

    def traverse(self):
        current = self.head
        while True:
            return current.data
            if current.next == self.head:
                break
            else:
                current = current.next


words = CircularList()
words.insert(None, "eggs")
words.insert(words.head, "ham")
words.insert(words.head, "spam")
for word in words.traverse():
    print(word)