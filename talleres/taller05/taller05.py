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
