import sys
sys.stdin = open("bj12865.txt", 'r')


def knapsack(capacity, item):
    if capacity == 0 or item >= _number:
        return 0

    if _weight[item] > capacity:
        return knapsack(capacity, item+1)

    if _memo.get((capacity, item)) is None:
        with_the_item = _value[item] + knapsack(capacity-_weight[item], item+1)
        without_the_item = knapsack(capacity, item+1)
        _memo[(capacity, item)] = max(without_the_item, with_the_item)
    return _memo.get((capacity, item))


_memo = {}
_weight = []
_value = []
_number, _capacity = map(int, input().split())

for _ in range(_number):
    A, B = map(int, input().split())
    _weight.append(A)
    _value.append(B)
print(knapsack(_capacity, 0))
