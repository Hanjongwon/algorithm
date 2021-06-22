import sys
sys.stdin = open("bj1932.txt", 'r')


def find_max(row, col):
    for i in range(_size-1, -1, -1):
        for j in range(i):
            _triangle[i-1][j] += max(_triangle[i][j], _triangle[i][j+1])

    return _triangle[row][col]


_triangle = []
_size = int(input())
for _ in range(_size):
    _triangle.append(list(map(int, input().split())))
print(find_max(0, 0))



