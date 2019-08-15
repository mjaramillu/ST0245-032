<<<<<<< HEAD
from matplotlib import pyplot as pl
import time
import random

def array_sum_loops (to_sum):
    result = 0 #C1
    for n in to_sum:
        result += n #C2 * to_sum
    return result # T(to_sum) = C1 + C2 * to_sum = O(n) W

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
=======
def insertion_sort(arr, i=1):
    if(i==len(arr)):
        return arr
    elif(arr[i]>=arr[i-1]):
        return insertion_sort(arr, i+1)
    else:
        a = arr[i-1]
        arr[i-1]=arr[i]
        arr[i]=a
        if (i>1):
            return insertion_sort(arr, i-1)
        else:
            return insertion_sort(arr,i+1)
print(insertion_sort([9,76,8,5,0,2,9,1,7.2,-1,4,3]))
>>>>>>> master
