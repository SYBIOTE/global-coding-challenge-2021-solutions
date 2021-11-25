
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x;
    cin >> n >> m >> x;

    int a[n];
    int b[m];

    for(int* i = a; i< a+n; i++) {
        cin >> *i;
    }

    for (int* i = b; i< b+m; i++) {
        cin >> *i;
    }
    int sum=0,count=0,i=0,j=0;        
    while(i<n && sum+a[i]<=x){    
        sum+=a[i];
        i++;
    }
    count=i;        
    while(j<m && i>=0){            
        sum+=b[j];             
        j++;
        while(sum>x && i>0){
            i--;
            sum-=a[i];
        }
        if(sum<=x && i+j>count)
            count=i+j;
    }
    cout << count;
    return 0;
}