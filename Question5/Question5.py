def sol(n):	
    count_max = -1	
    unopen_pools = []
    curr_count = 0
    for i in range(len(n)): 
      if n[i] =="1":
         if curr_count !=0:
               unopen_pools.append(curr_count)
         curr_count = 0
      else:
         curr_count += 1  
         if i==len(n)-1:
               unopen_pools.append(curr_count)
               break
    sorted_pools = sorted(unopen_pools,reverse=True)
    count_max=0
    count_max_2 = 0
    if len(sorted_pools)>0:
        count_max = sorted_pools[0]
        if len(sorted_pools)>=2:
            count_max_2 = sorted_pools[1]
    if count_max%2 == 0 or count_max_2>(count_max//2):
      return "B"
    else:
      return "A"
# do not edit below code
def main():
	n=input()
	print(sol(n))

if __name__ == '__main__':
    main()