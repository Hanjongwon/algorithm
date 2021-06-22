import sys
sys.stdin = open("bj1620.txt", 'r')

n, m = map(int, input().split())
name_list = [0]
name_dict = {}

for i in range(n):
    monster = sys.stdin.readline().rstrip("\n")
    monster.lower()
    name_list.append(monster)
    name_dict[monster] = i + 1

for _ in range(m):
    question = sys.stdin.readline().rstrip("\n")
    question.lower()
    A = list(question)
    if A[0].isnumeric():
        print(name_list[int(question)])
    else:
        print(name_dict.get(question))


































