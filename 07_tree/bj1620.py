import sys
sys.stdin = open('bj1620.txt', 'r')


class Node:
    def __init__(self, data = None, num=None):
        self.data = data
        self.num = num
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None

    def insert(self, data, num):
        node = Node(data)
        node.num = num
        parent = None
        current = self.root

        while current:
            parent = current
            if node.data < current.data:
                current = current.left
            else:
                current = current.right

        if parent is None:
            self.root = node
        elif node.data < parent.data:
            parent.left = node
        else:
            parent.right = node

    def search(self, data):
        node = self.root
        while True:
            if node is None:
                return node
            elif node.data == data:
                return node
            elif data < node.data:
                node = node.left
            elif data > node.data:
                node = node.right


if __name__ == "__main__":
    n, m = map(int, input().split())
    name_list = [0]
    tree = Tree()

    for i in range(1, n+1):
        name = sys.stdin.readline().rstrip('\n')
        name.lower()
        name_list.append(name)
        tree.insert(name, i)

    for _ in range(m):
        question = sys.stdin.readline().rstrip('\n')
        if question.isalpha():
            found = tree.search(question)
            print(found.num)
        else:
            B = int(question)
            print(name_list[B])






