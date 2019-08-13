#!/usr/bin/python
import random
from matplotlib import pyplot as pl
import time
import sys

sys.setrecursionlimit(50000)

# Add the elements in the list
def array_sum(array, index = 0):
    if len(array) == 0:
        return
    if index == len(array): #C1
        return 0
    else:
        return array[index] + array_sum(array, index + 1) #C2 + T(n-1)

# Determine if an array of volumes can fit into a target volume
def volume_group_sum (array, target, start = 0):
    if start == len(array):
        return target == 0 #C1
    else:
        return volume_group_sum(array, target - array[start], start + 1) or volume_group_sum(array, target, start + 1) #C2 + T(n-1) + T(n-1)

# Obtain fibonacci at position n
def fib(n):
    if n <= 2:
        return n
    else:
        return fib(n-1) + fib(n-2)


deltas = []
ns = []
array_to_sum = []
for i in range(20):
    for i in range(500):
        array_to_sum.append(random.randint(1,10))
    begin_time = time.time()
    array_sum(array_to_sum)
    end_time = time.time()
    delta = end_time - begin_time
    ns.append(len(array_to_sum))
    deltas.append(delta)

pl.plot(ns, deltas)
pl.show()

deltas = []
ns = []
array_to_sum = []
for i in range(20):
    array_to_sum.append(random.randint(1,1000))
    result = random.randint(1, 1000000)
    begin_time = time.time()
    volume_group_sum(array_to_sum, result)
    end_time = time.time()
    delta = end_time - begin_time
    ns.append(len(array_to_sum))
    deltas.append(delta)

pl.plot(ns, deltas)
pl.show()

deltas = []
ns = []
for i in range(20):
    begin_time = time.time()
    fib(i)
    end_time = time.time()
    delta = end_time - begin_time
    ns.append(i)
    deltas.append(delta)

pl.plot(ns, deltas)
pl.show()
