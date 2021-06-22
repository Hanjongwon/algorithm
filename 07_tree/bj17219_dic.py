import sys
sys.stdin = open('bj17219.txt', 'r')

dic = dict()
n, m = map(int, input().split())
for _ in range(n):
    site, pw = sys.stdin.readline().split()
    dic[site] = pw

for _ in range(m):
    question = sys.stdin.readline().rstrip('\n')
    print(dic.get(question))
