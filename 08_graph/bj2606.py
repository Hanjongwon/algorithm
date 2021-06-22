import sys
from collections import deque

sys.stdin = open("bj2606.txt", 'r')


def breadth_first_search(graph, root):
    visited = []
    discovered = []
    queue = deque([root])
    discovered.append(root)

    while len(queue) > 0:
        node = queue.popleft()
        visited.append(node)
        undiscovered = set(graph[node]).difference(set(discovered))

        if len(undiscovered) > 0:
            for elem in sorted(undiscovered):
                queue.append(elem)
                discovered.append(elem)

    return visited


A = int(input())
B = int(input())
dict1 = {}
for i in range(A):
    dict1[i+1] = list(set())

for j in range(B):
    a, b = (map(int, input().split()))
    dict1[a].append(b)
    dict1[b].append(a)

ans = breadth_first_search(dict1, 1)
print(len(ans)-1)

