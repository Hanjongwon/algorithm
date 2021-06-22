import sys
sys.stdin = open("bj10825.txt", 'r')

A = int(input())
big_list = []
for i in range(A):
    big_list.append(list(map(str, sys.stdin.readline().split())))

big_list.sort(key=lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))
for i in range(A):
    print(big_list[i][0])