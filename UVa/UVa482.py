t = int(input())
a = 1
for cs in range(0,t) :
    tmp = input()
    arr = [int(i) for i in input().split()]
    data = input().split()
    sz = len(arr)
    ans = [0]*sz
    for i in range(0,sz) :
        ans[arr[i]-1] = data[i]
    if a == 0 :
        print('')
    a = 0
    for i in range(0,sz) :
        print(ans[i])
