A = input()
list1 = []

for i in A:
    if len[list1] == 0:
        list1.append(i)
    elif list1[0] < i:
        list1.pop()
        list1.append[i]


print(*list1)