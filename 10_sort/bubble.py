def bubble_sort(unordered):
    iteration = len(unordered) - 1
    for i in range(iteration):
        for j in range(iteration-i):
            if unordered[j] > unordered[j+1]:
                unordered[j], unordered[j+1] = \
                    unordered[j+1], unordered[j]


if __name__ == '__main__':
    test = [45, 23, 87, 12, 32, 4]
    bubble_sort(test)
    print(test)
