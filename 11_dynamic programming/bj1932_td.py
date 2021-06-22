import sys
# sys.stdin = open('bj1932.txt', 'r')


def max_path(row, col):
    if row == _size - 1:
        return _triangle[row][col]

    if _memo[row][col] is None:
        path_left = _triangle[row][col] + max_path(row+1, col)
        path_right = _triangle[row][col] + max_path(row+1, col+1)

        _memo[row][col] = max(path_left, path_right)

    return _memo[row][col]


_memo = list()
_triangle = []
_size = int(input())
for _ in range(_size):
    _triangle.append(list(map(int, input().split())))
for i in range(1, 1000):
    _memo.append([None]*i)
print(max_path(0, 0))
