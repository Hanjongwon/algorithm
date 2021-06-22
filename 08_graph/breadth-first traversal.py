from collections import deque


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


graph2 = {
    'A': ['B', 'S'],
    'B': ['A'],
    'C': ['D', 'S', 'E', 'F'],
    'D': ['C'],
    'E': ['C', 'H'],
    'F': ['C', 'G'],
    'G': ['S', 'F', 'H'],
    'H': ['G', 'E'],
    'S': ['A', 'G', 'C']
        }


ans = breadth_first_search(graph2, 'A')
print(*ans, sep='-')
