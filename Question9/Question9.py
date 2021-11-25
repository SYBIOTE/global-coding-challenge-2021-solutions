import itertools
memo = None
def recursion(client,mask,banker,t):
    if memo[banker][client][mask] != -1:
        return memo[banker][client][mask]
    if client == len(t[0]):
        return 0
    min_cost = float("Inf")
    #print("\nb -> ",banker,"c->",client,"bin ",bin(mask))
    for j in range(len(t)):#banker loop
        if (mask & (1<<j) == 0 or j==banker):
        #print(client,j,mask,len(memo),len(memo[0]),len(memo[0][0]))
            bit = mask | (1 << j)
            a = recursion(client+1,bit,j,t)
            min_cost = min(min_cost,t[j][client] + a)
        #print(t[j][client],end = " ") 
    memo[banker][client][mask] = min_cost
    return min_cost
            
def assignment(cost):
    min_cost = float('inf')
    for i in range(len(cost)):
        #print("banker ",i)
        time = recursion(0,0,i,cost)
        #print(time)
        min_cost = min(min_cost,time)
    return min_cost

def BankerAndClients(c, b, t):
    global memo
    memo =[[[-1 for i in range(pow(2,b)+1)]for j in range(c+1)]for k in range(b+1)]
    min_time = assignment(t)
    return min_time
	# Participants code will be here


if __name__ == "__main__":
	abc=list(map(int,input().split()))
	client=abc[0]
	banker=abc[1]
	time=[[0 for i in range(20)] for j in range(10)]
	time = [list(map(int, input().split())) for y in range(banker)]
	result = BankerAndClients(client, banker, time)
	# Do not remove below line
	print(result)    
	# Do not print anything after this line# your code goes here