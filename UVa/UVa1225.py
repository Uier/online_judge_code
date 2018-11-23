t = int(input())
for cs in range(0,t) :
    arr = [0]*10
    n = int(input())
    for i in range(1,n+1) :
        j = int(i)
        while j > 0 :
            arr[j%10] += 1
            j = j//10
    for i in range(0,9) :
        print(arr[i], end=' ')
    print(arr[9])
