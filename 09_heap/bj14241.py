import sys


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
slime = list(map(int, sys.stdin.readline().split()))
for i in range(A):
    h.insert(slime[i])

value = 0
while h.size > 1:
    B = h.pop()
    C = h.pop()
    h.insert(B+C)
    value += B * C
print(value)




