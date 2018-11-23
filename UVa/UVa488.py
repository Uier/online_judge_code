t = int(input())
for cs in range(0,t) :
    tmp = input()
    m = int(input())
    n = int(input())
    if cs > 0 :
        print('')
    for i in range(0,n) :
        if i > 0 :
            print('')
        for j in range(0,m) :
            for k in range(0,j+1) :
                print(j+1, end='')
            print('')
        for j in range(1,m) :
            for k in range(0,m-j) :
                print(m-j, end='')
            print('')
