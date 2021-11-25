#include<bits/stdc++.h>
using namespace std;
int memo[11][21][1025] = {{{NULL}}};
int b,c;
int g_time[11][21]={{}};
int recursion(int client,int banker,int key){
    if (memo[banker][client][key] != NULL)return memo[banker][client][key];
    if (client == c)return 0;
    int curr_min_t = INT_MAX;
    for(int j =0;j<b;j++){
        if ((key & (1<<j)) == 0 or j==banker){
            int bit = key | (1<<j);
            int a = recursion(client+1,j,bit);
            curr_min_t = min(curr_min_t,g_time[j][client] + a);
        }
    }
    memo[banker][client][key] = curr_min_t;
    return curr_min_t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>c>>b;
    for(int i = 0; i < b; i++){
        for(int j = 0;j < c;j++){
         cin>>g_time[i][j];
        }
    }
    int min_t = INT_MAX;
    for (int i=0;i<b;i++){
        int _time = recursion(0,i,0);
        min_t = min(min_t,_time);
    }
	
    // Do not remove below line
    cout << min_t << endl;
    // Do not print anything after this line
        
    return 0;
}
