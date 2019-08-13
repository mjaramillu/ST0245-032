def insertion_sort(arr, i=0):
    if(i==len(arr)-1):
        return arr
    if(arr[i+1]>=arr[i]):
        return insertion_sort(arr, i+1)
    else
        a = arr[i]
        arr[i]=arr[i+1]
        arr[i+1]=a
        return insertion_sort(arr, i)
print(insertion_sort([6,4,2,3,1,8,7]))
