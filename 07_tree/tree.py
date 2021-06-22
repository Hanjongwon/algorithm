class Node:
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None

    def find_min(self):
        node = self.root
        while node.left:
            node = node.left
        return node

    def find_max(self):
        node = self.root
        while node.right:
            node = node.right
        return node

    def insert(self, data):
        node = Node(data)
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

    def inorder(self):
        self._inorder(self.root)

    def _inorder(self, node):
        if node:
            self._inorder(node.left)
            print(node.data, end=' ')
            self._inorder(node.right)

    def reverse_inorder(self):
        self._reverse_inorder(self.root)

    def _reverse_inorder(self, node):
        if node:
            self._reverse_inorder(node.right)
            print(node.data, end=' ')
            self._reverse_inorder(node.left)


tree = Tree()
tree.insert(5)
tree.insert(2)
tree.insert(7)
tree.insert(9)
tree.insert(1)

print("min: %s" % tree.find_min().data)
print("max: %s" % tree.find_max().data)

for i in range(1, 10):
    found = tree.search(i)
    print("{}: {}".format(i, found))

tree.inorder()
print()
tree.reverse_inorder()
