import bisect

n = int(input())
card = list(map(int, input().split()))
card.sort()
m = int(input())
k = list(map(int, input().split()))


def binary_search(ordered_list, target):
    index = bisect.bisect_left(ordered_list, target)

    if index < len(ordered_list) and ordered_list[index] == target:
        return 1
    else:
        return 0


for i in range(m):
    result = binary_search(card, k[i])
    print(result)
