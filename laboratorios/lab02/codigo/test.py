import common
import matplotlib.pyplot as pl
import time
import random
import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**31,-1))
sys.setrecursionlimit(2**30)

deltasInsertion = []
deltasInsertionRecursive = []
deltasMerge = []
ns = []
for i in range(240):
    array_to_sorta = []
    array_to_sortb = []
    array_to_sortc = []
    for i in range(10 * (i+1)):
        result = random.randint(1,300000)
        array_to_sorta.append(result);
        array_to_sortb.append(result);
        array_to_sortc.append(result);

    begin_time = time.time()
    common.insertionSort(array_to_sorta)
    end_time = time.time()
    delta = end_time - begin_time
    deltasInsertion.append(delta * 1000)

    begin_time = time.time()
    common.mergeSort(array_to_sortb)
    end_time = time.time()
    delta = end_time - begin_time
    deltasMerge.append(delta * 1000)

    begin_time = time.time()
    common.insertionSortRecursive(array_to_sortc)
    end_time = time.time()
    delta = end_time - begin_time
    deltasInsertionRecursive.append(delta * 1000)

    ns.append(len(array_to_sorta))
    print(len(array_to_sorta))

pl.scatter(ns, deltasInsertion, label='Insertion sort')
pl.legend()
pl.scatter(ns, deltasInsertionRecursive, label='Insertion sort (recursive)')
pl.legend()
pl.scatter(ns, deltasMerge, label='Merge sort')
pl.legend()
pl.show()
