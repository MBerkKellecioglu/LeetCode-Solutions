def MinMax(arr):
    
    if len(arr) == 1 or len(arr) == 2:
        if len(arr) == 1:
            return [arr[0], arr[0]]
        
        if len(arr) == 2:
            return [min(arr), max(arr)]
        
    l = len(arr)
    
    lst1 = MinMax(arr[:l // 2]) # [0 dan l / 2 ' ye kadar)
    lst2 = MinMax(arr[l // 2:]) # [l / 2 den, size)
    
    return [min(lst1[0], lst2[0]), max(lst1[1], lst2[1])]


print(MinMax([31,6,8,69,11,23,47]))

   