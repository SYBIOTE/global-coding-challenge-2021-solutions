#include <stdio.h>

int memo[16][32][2048] = {{{NULL}}};
int b,c;
int g_time[16][32];
int recursion(int client,int banker,int key){
    if (memo[banker][client][key] != NULL)return memo[banker][client][key];
    if (client == c)return 0;
    int curr_min_t = 2147483647;
    for(int j =0;j<b;j++){
        if ((key & (1<<j))==0 || j==banker){
            int bit = key | (1<<j);
            int a = recursion(client+1,j,bit);
            if((g_time[j][client] + a)<curr_min_t){
                 curr_min_t = g_time[j][client] + a;
            }
        }
    }
    memo[banker][client][key] = curr_min_t;
    return curr_min_t;
}
int main(){
    scanf("%d %d", &c, &b);
    for (int i=0; i<b; i++){
        for(int j = 0;j < c;j++){
          scanf("%d",&g_time[i][j]);
        }
    }
	int min_t = 2147483647;
    for (int i=0;i<b;i++){
        int _time = recursion(0,i,0);
        if(min_t>_time){
            min_t = _time;
        }
    }
    // Do not remove below line
    printf("%d",min_t);
    // Do not print anything after this line
}
