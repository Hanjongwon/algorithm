import sys
sys.stdin = open("bj14235.txt", 'r')


class MaxHeap:
    def __init__(self):
        self.heap = [0]
        self.size = 0

    def float_up(self, k):
        while k // 2 > 0:
            if self.heap[k] > self.heap[k//2]:
                self.heap[k], self.heap[k//2] = \
                    self.heap[k//2], self.heap[k]
            k //= 2

    def insert(self, item):
        self.heap.append(item)
        self.size += 1
        self.float_up(self.size)

    def max_index(self, k):
        left = k * 2
        right = k * 2 + 1
        if right > self.size:
            return left
        elif self.heap[left] > self.heap[right]:
            return left
        else:
            return right

    def sink(self, k):
        while k * 2 <= self.size:
            mi = self.max_index(k)
            if self.heap[k] < self.heap[mi]:
                self.heap[k], self.heap[mi] = \
                    self.heap[mi], self.heap[k]
            k = mi

    def pop(self):
        item = self.heap[1]
        self.heap[1] = self.heap[self.size]
        self.heap.pop()
        self.size -= 1
        self.sink(1)
        return item

    def heap_sort(self):
        sorted_list = []
        for _ in range(self.size):
            n = self.pop()
            sorted_list.append(n)

        return sorted_list


h = MaxHeap()
A = int(input())
for _ in range(A):
    B = list(map(int, sys.stdin.readline().split()))
    if B[0] == 0:
        if h.size == 0:
            print(-1)
        else:
            print(h.pop())

    else:
        for i in range(1, B[0] + 1):
            h.insert(B[i])

