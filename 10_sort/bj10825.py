import sys
sys.stdin = open("bj10825.txt", 'r')

A = int(sys.stdin.readline())
big_list = []

for _ in range(A):
    big_list.append(sys.stdin.readline().split())
big_list.sort(key=lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))

for i in range(A):
    print(big_list[i][0])
