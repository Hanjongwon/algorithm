import sys, copy
sys.stdin = open("bj10026.txt", 'r')


def depth_first_search(graph, row, col):
    stack = [(row, col)]
    move = [[0, -1], [0, 1], [-1, 0], [1, 0]]

    color = graph[row][col]
    graph[row][col] = 'X'

    while len(stack) > 0:
        row, col = stack.pop()
        for m in range(4):
            next_row, next_col = row, col
            next_row += move[m][0]
            next_col += move[m][1]
            if not check_move(graph, next_row, next_col, color):
                continue
            stack.append((next_row, next_col))
            graph[next_row][next_col] = 'X'


def check_move(graph, row, col, color):
    if row < 0 or row >= size:
        return False

    if col < 0 or col >= size:
        return False
    if graph[row][col] != color:
        return False
    if graph[row][col] == 'X':
        return False
    return True


size = int(input())
list1 = []

for i in range(size):
    A = list(map(str, input()))
    list1.append(A)
list2 = copy.deepcopy(list1)
list3 = copy.deepcopy(list1)

for p in range(size):
    for q in range(size):
        if list3[p][q] == 'G':
            list3[p][q] = 'R'

count1 = 0
count2 = 0

for i in range(size):
    for j in range(size):
        start_row = i
        start_col = j
        if list2[i][j] == 'X':
            continue
        depth_first_search(list2, start_row, start_col)
        count1 += 1

for a in range(size):
    for b in range(size):
        if list3[a][b] == 'X':
            continue
        depth_first_search(list3, a, b)
        count2 += 1
print(count1, count2)











