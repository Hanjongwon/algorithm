from collections import deque


def breath_first(node):
    queue = deque()
    queue.append(node)

    while len(queue):
        visit = queue.popleft()
        print(visit.data, end=' ')
        if visit.left:
            queue.append(visit.left)
        if visit.right:
            queue.append(visit.right)