
def totalPairs(n, values):
   count = 0
   val_max = max(values)
   idx_max = values.index(val_max)
   for i in range(n):
      if idx_max == i:
          continue
      if idx_max>i:
          count+=1
      else:
          for j in range(i+1,n):
             if values[j]>=values[i]:
                count+=1
                break
      if idx_max<i:
          count+=1
      else:
          for k in range(i-1,-1,-1):
             if values[k]>=values[i]:
                count+=1
                break
   return count
if __name__ == "__main__":
    n = int(input())
    values = list(map(int, input().split()))
    answer = totalPairs(n, values)
    print(answer)