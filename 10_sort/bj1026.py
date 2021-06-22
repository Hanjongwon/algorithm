from quicksort import *
# from bubble import *
import sys
sys.stdin = open("bj1026.txt", 'r')
A = int(input())
des_list = [-i for i in map(int, input().split())]
asc_list = list(map(int, input().split()))


# des_list.sort()
# asc_list.sort(reverse=True)
# value = 0

quick_sort(des_list, 0, len(des_list)-1)
quick_sort(asc_list, 0, len(asc_list)-1)
des_list2 = [-i for i in des_list]
value = 0
for j in range(A):
    value += des_list2[j] * asc_list[j]
print(value)


# bubble_sort(des_list)
# bubble_sort(asc_list)
# des_list2 = [-i for i in des_list]
# value = 0
# for j in range(A):
#     value += des_list2[j] * asc_list[j]
# print(value)




