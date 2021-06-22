import math


# def cut_rod(length):
#     if length == 0:
#         return 0
#     max_revenue = -math.inf
#     for i in range(1, length + 1):
#         revenue = _price[i] + cut_rod(length - i)
#         if revenue > max_revenue:
#             max_revenue = revenue
#     return max_revenue
#
#
# _price = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
# _length = 8
# print(cut_rod(_length))


# def cut_rod_td(length):
#     if length == 0:
#         return 0
#
#     if _memo[length] is None:
#         max_revenue = -math.inf
#         for i in range(1, length + 1):
#             revenue = _price[i] + cut_rod_td(length - i)
#             if revenue > max_revenue:
#                 max_revenue = revenue
#         _memo[length] = max_revenue
#     return _memo[length]
#
#
# _memo =[None] * 11
# _price = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
# _length = 8
# print(cut_rod_td(_length))


def cut_rod_bu(length):
    memo = [0]

    for i in range(1, length + 1):
        max_revenue = -math.inf
        for j in range(1, i+1):
            revenue = _price[j] + memo[i-j]
            if revenue > max_revenue:
                max_revenue = revenue
        memo.append(max_revenue)

    return memo[-1]


_price = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
_length = 8
print(cut_rod_bu(_length))













