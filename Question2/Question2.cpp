#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
 ios::sync_with_stdio(false);
    cin.tie(NULL);
int z;
cin>>z;
vector<int> input_data;
string buffer;
int data;
getline(cin, buffer);
getline(cin, buffer);
istringstream iss(buffer);

while (iss >> data)
    input_data.push_back(data);
int n= input_data.size();
int security_value[n];
for (int i = 0; i < n; i++) {
    security_value[i] = input_data[i];
}
    int no_of_stocks=0;
    map<int,int> best_value;
    for(int i = 0;i<n;i++){
        best_value[security_value[i]] += i+1;
    }
    int _sum  = 0;
    for(auto i = best_value.begin();i!=best_value.end();++i){
        _sum = (i->first)*(i->second);
        if (_sum<z){
            z-=_sum;
            no_of_stocks += i->second;
        }
        else{
            no_of_stocks += z/i->first;
            break;
        }
    }
    
cout << no_of_stocks;
 
 
 
}
 
 
