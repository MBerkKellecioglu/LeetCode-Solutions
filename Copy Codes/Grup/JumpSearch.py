def JumpSearch(arr, target):
    
    j = int(len(arr)**1/2)
    prev = 0
    lst = []
    
    for i in range(0, len(arr), j):
        if arr[i] > target:
            lst = arr[prev:i]
            break
        
        prev = i
    
    if len(lst) == 0:
        lst = arr[prev: len(lst)] 
    
    for i in range(len(lst)):
        if lst[i] == target:
            return i
    
    return -1


print(JumpSearch([1,2,3,4,5,6,7,8,9,10], 1))

    
        
        