#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n;
   cin >> n;
   int values[n];
   cin>>values[0];
   int c1 = values[0],count = 0;
   int c1_idx = 0;
   for (int i = 1; i < n; ++i) {
        cin >> values[i];
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
    cout << count+c1_idx;
    // Do not print anything after this line
        
    return 0;
}
