//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<int> splitStringToInt(const string& str, char delim) {
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string firstLine;
    getline(cin, firstLine);

    vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
    int n = firstLineVec[0];
    int k = firstLineVec[1];
    int d = firstLineVec[2];
    int m = firstLineVec[3];

    string return_;
    getline(cin, return_);

    vector<int> returns = splitStringToInt(return_, ' ');
    int result = 0;
    vector<int> og_ret = returns;
    bool *chosen = new bool[n];
    for(int i = 0;i<n;i++){
        chosen[i] = false;
    }
    while(k>0){
        int pl[n];
        int pg[n];
        int net[n];
        int max_net = -__INT_MAX__;
        int mni = -1;
        int ps[n];
        int sum = 0;
        for(int i = 0;i<n;i++){
            if(og_ret[i]*m == returns[i] and og_ret[i] != returns[i]){
                sum+=0;
            }
            else{
                sum+=returns[i];
            }
            ps[i] = sum;
        }
        for(int i = 0;i<n;i++){
            if (!chosen[i]){
                int multiplier = min(i,(min(k-1,d)));
                pl[i] = og_ret[i]*multiplier*m;
                pg[i] = (ps[min(i+d,n-1)]-ps[i])*m;
                net[i] = pg[i]-(pl[i]+returns[i]);
                
            if(net[i]>max_net){
                max_net = net[i];
                mni = i;
                }
            }
        }
        returns[mni] = 0;
        chosen[mni] = true;
        for(int i = mni+1;i<=min(mni+d,n-1);i++){
            if(og_ret[i]*m!=returns[i] and !chosen[i]){
                returns[i]*= m;
           }
        }
    k--;
    }
    for(int i = 0 ;i <n;i++){
        result+=returns[i];
    } 
    // Do not remove below line
    cout << result;
    // Do not print anything after this line
    return 0;
}