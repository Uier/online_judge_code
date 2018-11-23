tcase = int(input())
for t in range(0,tcase) :
    n = int(input())
    arr = [int(i) for i in input().split()]
    arr.sort()
    print((arr[n-1]-arr[0])*2)
