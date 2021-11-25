#include <map>
#include <cmath>
#include <unordered_set>
#include <ctime>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <unordered_map>

#define m 1000000007
#define MAXN 1000001
using namespace std;
int parent[MAXN] = {};
int spf[MAXN];
int hash1[MAXN] = {};
int n,ans = 0;
int hash2[MAXN] ={};
int find(int x)
{
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   cin >> n;
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
    for (int* i = values; i< values+n; i++) {
        cin >> *i;
        parent[*i] = *i;
        int x = *i;
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
   for(int* i = values; i< values+n; i++){
        int x = *i;
        while (x != 1) {
            int temp = spf[x];
            if (x % temp == 0 && hash1[temp] > 1 && *i!=temp){
                  int a = *i;
                  if (parent[a] != a){a = find(a);}
                  int b = temp;
                  if (parent[b] != b){b = find(b);}
                    if (a<b){
                        swap(a,b);
                        }
                    parent[b] = a;
                }
            while (x % temp == 0)
                x = x / temp;
        }
    }
 
   // make set
   for(int* i = values; i< values+n; i++){
      int value = find(*i);
      if (value < MAXN && hash2[value] == 0) {
        ans++;
        }
      hash2[value]++;
   }
   if (ans<2){
      cout<<"NO"<<"\n"<<0;
   }
   else{
        long long a = 2;
        long long res = 1;
        while(ans>0){
            if(ans&1)res = (res*a)%m;
            a = (a*a)%m;
            ans = ans>>1;
        }
      cout<<"YES"<<"\n"<< res-2;
   }
   return 0;
}