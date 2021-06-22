n, k = map(int, input().split())

jo = []
for i in range(1, n+1):
    jo.append(i)

index = 0

print('<', end='')
while len(jo) > 1:
    for _ in range(k-1):
        index += 1
        if index == len(jo):
            index = 0
    print(f"{jo.pop(index)}", end=', ')
    if index == len(jo):
        index = 0
print(*jo, end='>')
