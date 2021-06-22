import sys
sys.stdin = open('bj17219.txt', 'r')


class Node:
    def __init__(self, site=None, password=None):
        self.site = site
        self.password = password
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None

    def insert(self, site, password):
        node = Node(site, password)
        parent = None
        current = self.root

        while current:
            parent = current
            if node.site < current.site:
                current = current.left
            else:
                current = current.right

        if parent is None:
            self.root = node
        elif node.site < parent.site:
            parent.left = node
        else:
            parent.right = node

    def search(self, site):
        node = self.root
        while True:
            if node is None:
                return node
            elif node.site == site:
                return node
            elif site < node.site:
                node = node.left
            elif site > node.site:
                node = node.right


if __name__ == "__main__":
    tree = Tree()
    n, m = map(int, input().split())
    for _ in range(n):
        st, pw = sys.stdin.readline().split()
        tree.insert(st, pw)

    for _ in range(m):
        find_password = sys.stdin.readline().rstrip('\n')
        A = tree.search(find_password)
        print(A.password)

















