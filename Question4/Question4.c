#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int values[n];
    scanf("%d", &values[0]);
    int c1 = values[0],count = 0,c1_idx;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &values[i]);
        if (values[i]>c1){
            c1 = values[i];
            c1_idx = i;
        }
        else{
            count++;
        }
    }
    int c2=values[n-1];
    for(int j = n-2;j>c1_idx;j--){
        if (values[j]>c2){
            c2 = values[j];
        }
        else{
            count++;
        }
    }
    // Do not remove below line
    printf("%d",count+c1_idx);
}

