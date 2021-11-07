def check(x, y):
    a = []*1000001
    a = [int(i*0) for i in range(0, 1000001)]
    for i in range(2, 1000000):
        a[i] = a[i] + i
        for j in range(i*2, 1000001, i):
            a[j] = a[j] + i
    ans = 0
    for i in range(x, y+1):
        if a[i]-i+1 > i:
            ans += 1
    return ans


if __name__ == "__main__":
    a = [int(i) for i in input().split()]
    if(len(a) == 1):
        b = [int(i) for i in input().split()]
        print(check(a[0],b[0]))
    else:
        print(check(a[0],a[1]))