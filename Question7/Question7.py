m = 1000000007
MAXN = 1000001

parent = [0]*(MAXN)
spf = [i for i in range(MAXN)]
hash1 = [0 for i in range(MAXN)]
def sieve():
    for i in range(4, MAXN, 2):
        spf[i] = 2
    for i in range(3, MAXN):
        if i * i >= MAXN:
            break
        if (spf[i] == i):
            for j in range(i * i, MAXN, i):
                if (spf[j] == j):
                    spf[j] = i
def getFactorization(x):
    while (x > 1):
        temp = spf[x]
        if (x % temp == 0):
            hash1[spf[x]] += 1
            parent[temp] = temp
        while (x % temp == 0):
            x = x // temp
def make(x):
    num = x 
    while (x > 1):
        temp = spf[x]
        if (x % temp == 0 and hash1[temp] > 1):
            if num!= temp:
                connect(temp,num)    
        while (x % temp == 0):
            x = x //temp
def root(a) :
    if (a == parent[a]):       
        return a
    parent[a] = root(parent[a])
    return parent[a]
def connect(a, b):
    a = root(a)
    b = root(b)
    if a!=b:
        if a<b:
            a,b = b,a
        parent[b] = a
    
def connectedComponents(values) :
    s = set()
    for i in values:
        s.add(root(parent[i]))
    return len(s)
def countStablePartitions(n, values):
    global parent
    parent = [0]*MAXN
    global hash1
    hash1 = [0]* MAXN
    sieve()
    for i in values:
        getFactorization(i)
        parent[i] = i
    #print(parent)
    for i in values:
        make(i)
    #print(parent)          
    connected = connectedComponents(values)
    if connected < 2:
        print("NO")
        print(0)
    else:
        print("YES")
        print((pow(2,connected)-2)%m)
        

if __name__ == "__main__":
    n = int(input())
    values = list(map(int, input().split()))
    countStablePartitions(n, values)