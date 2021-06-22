class Node:
    def __init__(self, data= None):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.top = None
        self.size = 0

    def push(self, data):
        node = Node(data)

        if self.top:
            node.next = self.top
        self. top = node
        self.size += 1

    def pop(self):
        if self.size == 0:
            return None

        data = self.top.data
        self.top = self.top.next
        self.size -= 1
        return data

    def peak(self):
        if self.size == 0:
            return None
        return self.top.data


