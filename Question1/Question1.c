#include<stdio.h>



/* Do not edit below code */
void main() {
    int n;
    scanf("%d",&n);
    int c = (!(n%3)) ? (n/3 *2) : ((n/3)*2+1);
	printf("%d",c);
}
