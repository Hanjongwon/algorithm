import random


def binary_search(ordered_list, target):
    left, right = 0, len(ordered_list)-1

    while left <= right:
        mid = (left + right) // 2

        if target < ordered_list[mid]:
            right = mid -1

        elif target > ordered_list[mid]:
            left = mid + 1
        else:
            return mid

    return None


test = random.choices(range(1, 15), k=10)
test.sort()
print(test)
_target = 11
result = binary_search(test, _target)
print(result)
