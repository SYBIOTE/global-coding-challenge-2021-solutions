#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100000 
int main(void) {
	char *n=(char*)malloc(max*sizeof(char));
	scanf("%s",n);
    int curr_count=0;
    int pool_1=0,pool_2=0;
    for(int i = 0 ; i<strlen(n);i++){
        if(n[i] == '1'){
            if (curr_count !=0){
                if (curr_count>pool_1/2){
                    pool_2 = curr_count;
                }
                if (curr_count>=pool_1){
                    pool_2 =pool_1;
                    pool_1 = curr_count;
                }
            }
        curr_count = 0;
        }
        else{
            curr_count+=1;
            if (i==strlen(n)-1){
                if (curr_count>pool_1/2){
                    pool_2 = curr_count;
                }
                if (curr_count>=pool_1){
                    pool_2 =pool_1;
                    pool_1 = curr_count;
                }
               break;
            }
        }

    }
    if (!(pool_1%2) || pool_2>pool_1/2){
    printf("B");
    }
    else{
    printf("A");
    }
	return 0;
}
