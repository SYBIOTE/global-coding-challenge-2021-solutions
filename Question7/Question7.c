#include <stdio.h>


#define m 1000000007
#define MAXN 1000001
int parent[MAXN] = {};
int spf[MAXN];
int hash1[MAXN] = {};
int find(int x)
{
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);;
}
int main(){
   int n;
   scanf("%d",&n);
   int values[n];
   //seive
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&values[i]);
        parent[values[i]] = values[i];
        int x = values[i];
        while (x != 1) {
            int temp = spf[x];
            if (x % temp == 0) {
                hash1[temp]++;
                parent[temp] = temp;
                x = x/temp;
            }
            while (x % temp == 0)
                x = x / temp;
        }
   }
   // make links
   for(int i = 0 ;i<n;i++){
        int x = values[i];
        while (x != 1) {
            int temp = spf[x];
            if (x % temp == 0 && hash1[temp] > 1 && values[i]!=temp){
                  int a = values[i];
                  if (parent[a] != a){a = find(a);}
                  int b = temp;
                  if (parent[b] != b){b = find(b);}
                  if (a!=b){
                    if (a<b){
                        int temp = a;
                        a = b;
                        b = temp;
                        }
                    parent[b] = a;
                  }
                }
            while (x % temp == 0)
                x = x / temp;
        }
    }
 
   // make set
   int ans = 0;
   int hash2[MAXN] ={};
   for(int i = 0 ;i<n;i++){
      int value = find(values[i]);
      if (value < MAXN && hash2[value] == 0) {
        ans++;
        }
      hash2[value]++;
   }
   if (ans<2){
      printf("NO\n%d",0);
   }
   else{
        n = ans;
        long long a = 2;
        long long res = 1;
        while(n>0){
            if(n&1)res = (res*a)%m;
            a = (a*a)%m;
            n = n>>1;
        }
     printf("YES\n%d",res-2);
   }
   return 0;
}