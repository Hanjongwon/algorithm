def insertion_sort(unordered):
    for i in range(1, len(unordered)):
        key = unordered[i]

        j = i
        while j > 0 and unordered[j-1] > key:
            unordered[j] = unordered[j-1]
            j -= 1
        unordered[j] = key


test = [45, 23, 87, 12, 32, 4]
insertion_sort(test)
print(test)