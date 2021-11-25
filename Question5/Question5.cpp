using namespace std;
#include <string>
#include <iostream>
/*  Do not edit below code */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	string n;
	cin >> n;	
    int curr_count=0;
    int pool_1=0,pool_2=0;
    for(int i = 0 ; i<n.size();i++){
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
            if (i==n.size()-1){
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
    if (pool_1%2==0 or pool_2>pool_1/2){
    cout<<"B";
    }
    else{
    cout<<"A";
    }
}
