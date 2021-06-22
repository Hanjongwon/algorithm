from bj2606 import
import sys
sys.stdin = open("bj10026.txt", 'r')

A = int(input())
B = int(input())
dic = {}
for i in range(1, A+1):
    dic[i] = list(set())

for j in range(B):
    a, b = map(int, input().split())
    dic[a].append(b)
    dic[b].append(a)

