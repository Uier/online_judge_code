n = int(input())
for t in range(0,n) :
    arr = [int(i) for i in input().split()]
    arr.sort()
    if arr[0] == arr[1] == arr[2] == arr[3] :
        print('square')
    elif arr[0] == arr[1] and arr[2] == arr[3] :
        print('rectangle')
    else :
        sum3 = arr[0]+arr[1]+arr[2]
        if arr[3] < sum3 :
            print('quadrangle')
        else :
            print('banana')
