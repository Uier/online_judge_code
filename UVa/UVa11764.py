t = int(input())
for cs in range(0,t) :
    n = int(input())
    arr = [int(i) for i in input().split()]
    h = 0
    l = 0
    for i in range(0,n-1) :
        if arr[i] < arr[i+1] :
            h += 1
        elif arr[i] > arr[i+1] :
            l += 1
    print('Case ' + str(cs+1) + ': ' + str(h) + ' ' + str(l))
