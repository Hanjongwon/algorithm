def fibonacci_td(n):
    if n < 2:
        return n

    if _memo[n] is None:
        _memo[n] = fibonacci_td(n-1) + fibonacci_td(n-2)

    return _memo[n]


_memo = [None] * 100
print(fibonacci_td(int(input())))


def fibonacci_bu(n):
    memo = [0, 1]

    for i in range(2, n+1):
        memo.append(memo[i - 1]+ memo[i - 2])

    return memo[-1]


print(fibonacci_bu(int(input())))
