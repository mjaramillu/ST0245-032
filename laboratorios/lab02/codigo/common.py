# Complejidad: O(n^2)
def insertionSortRecursive(arr, i=1):
    if(i==len(arr)): # Not worse case
        return arr
    elif(arr[i]>=arr[i-1]): # T(n-1)
        return insertionSortRecursive(arr, i+1)
    else:
        a = arr[i-1] #C1
        arr[i-1]=arr[i] #C2
        arr[i]=a #C3
        if (i>1): #C4
            return insertionSortRecursive(arr, i-1) # T(n+1)
        else:
            return insertionSortRecursive(arr,i+1)

def insertionSort(arr):
    for i in range(1, len(arr)):
        temp = arr[i]
        lastj = -2
        for j in range (i - 1, -2, -1):
            lastj = j
            if temp > arr[j]:
                break;
            arr[j + 1] = arr[j]
        if lastj != -2:
            arr[lastj+1] = temp

def mergeSort(arr):
    if len(arr) >1:
        middle = len(arr)//2
        Left = arr[:middle]
        Right = arr[middle:]
        mergeSort(Left)
        mergeSort(Right)
        i = j = k = 0
        while i < len(Left) and j < len(Right):
            if Left[i] < Right[j]:
                arr[k] = Left[i]
                i+=1
            else:
                arr[k] = Right[j]
                j+=1
            k+=1
        while i < len(Left):
            arr[k] = Left[i]
            i+=1
            k+=1
        while j < len(Right):
            arr[k] = Right[j]
            j+=1
            k+=1
