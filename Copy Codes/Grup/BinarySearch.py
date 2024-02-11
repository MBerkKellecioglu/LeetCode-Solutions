def BinarySearch(arr, target):
    
    arr.sort()
    
    l = 0
    r = len(arr)
    
    while l <= r:
        
        mid = (l + r) // 2
        
        if arr[mid] > target:
            r = mid - 1
        
        elif arr[mid] < target:
            l = mid + 1
        
        else:
            return mid
    
    return -1


print(BinarySearch([48,26,32,2,6,7], 6)) # [2, 6, 7, 26, 32, 48]
            
    