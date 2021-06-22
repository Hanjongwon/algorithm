import sys
sys.stdin = open('bj1620.txt', 'r')

n, m = map(int, input().split())
name_list = [0]
name_dict = {}

for i in range(n):
    name = sys.stdin.readline().rstrip('\n')
    name_list.append(name)
    name_dict[name] = i + 1

for _ in range(m):
    question = sys.stdin.readline().rstrip('\n')
    if question.isnumeric():
        print(name_list[int(question)])

    else:
        print(name_dict.get(question))
