
from matplotlib import pyplot as pl
import time
import random
import sys

# Complejidad: O(n)
def array_sum_loops (to_sum):
    result = 0 #C1
    for n in to_sum:
        result += n #C2 * to_sum
    return result # T(to_sum) = C1 + C2 * to_sum = O(n)

deltas = []
ns = []
array_to_sum = []
for i in range(20):
    for x in range(5000):
        array_to_sum.append(random.randint(1,1000))
    print(len(array_to_sum))
    begin_time = time.time()
    array_sum_loops(array_to_sum)
    end_time = time.time()
    delta = end_time - begin_time
    ns.append(len(array_to_sum))
    deltas.append(delta)

pl.plot(ns, deltas)
pl.show()

# Complejidad: O(n^2)
def insertion_sort(arr, i=1):
    if(i==len(arr)): # Not worse case
        return arr
    elif(arr[i]>=arr[i-1]): # T(n-1)
        return insertion_sort(arr, i+1)
    else:
        a = arr[i-1] #C1
        arr[i-1]=arr[i] #C2
        arr[i]=a #C3
        if (i>1): #C4
            return insertion_sort(arr, i-1) # T(n+1)
        else:
            return insertion_sort(arr,i+1)


sys.setrecursionlimit(500000)


deltas = []
ns = []
for i in range(20):
    begin_time = time.time()
    for w in range(100):
        array_to_sum = []
        for x in range(7 * (i+1)):
            array_to_sum.append(random.randint(1,1000))
        print(len(array_to_sum))
        insertion_sort(array_to_sum)
    end_time = time.time()
    delta = end_time - begin_time
    ns.append(len(array_to_sum))
    deltas.append(delta)

pl.plot(ns, deltas)
pl.show()
