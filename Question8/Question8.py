# Participants may update the following function parameters
import itertools
def getMaximizedReturn(n, k, d, m, dailyReturns):
    og_ret = dailyReturns.copy()
    choices = k
    chosen = [False]*n 
    while choices>0:
        possible_loss = [0]*n
        profit_gained = [0]*n
        net=[0]*n
        max_net  = -float("inf")
        max_net_index = -1
        prefix_sum = []
        sum = 0
        for i in range(n):
            if dailyReturns[i]//m == og_ret[i] and dailyReturns[i]!=og_ret[i]:
                sum+= 0
            else:
                sum += dailyReturns[i]
            prefix_sum.append(sum)
        
        for i in range(n):
            if not chosen[i]: #available for selction 
               multiplier = max(0,(min([(k-1),d,i])))
               possible_loss[i] = (og_ret[i]*multiplier*m)# calc possible loss 
               profit_gained[i] = (prefix_sum[min(i+d,n-1)]-prefix_sum[i])*m
               net[i] = profit_gained[i]-possible_loss[i]-dailyReturns[i]
            if net[i]>max_net and not chosen[i]:
                max_net = net[i]
                max_net_index = i

        dailyReturns[max_net_index] = 0
        chosen[max_net_index] = True
        #print(min(max_net_index+1,n-1),min(max_net_index+d,n-1))
        for i in range(min(max_net_index+1,n-1),min(max_net_index+d,n-1)+1):
            if dailyReturns[i]//m != og_ret[i]:
                dailyReturns[i] *= m
        choices-=1
        
       # print("PS",prefix_sum)
       # print("OG",og_ret)
       # print("PL",possible_loss)
       # print("PG",profit_gained)
      #  print("NG",net)
       # print("choose",max_net_index)
       # print(dailyReturns)
       # print("next ")
   # print("final ",dailyReturns)
    sum = 0
    for i in dailyReturns:
        sum+=i
    return sum

def main():
    firstLine = input().split(" ")
    secondLine = input().split(" ")

    n = int(firstLine[0])
    k = int(firstLine[1])
    d = int(firstLine[2])
    m = int(firstLine[3])
    dailyReturns = list(map(int, secondLine))

    # Participants may update the following function parameters
    answer = getMaximizedReturn(n, k, d, m, dailyReturns)

    # Please do not remove the below line.
    print(answer)
    # Do not print anything after this line

if __name__ == '__main__':
    main()