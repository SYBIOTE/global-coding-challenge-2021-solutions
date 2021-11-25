//#include <bits/stdc++.h>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<unordered_map>
using namespace std;

int *parent;
int find(int x)
{
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

vector<string> split_string(string);
int main()
{   ios::sync_with_stdio(false);
    cin.tie(NULL);
    //string inputdata_temp;
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);
    unordered_map<string,int> emp_dep;// dep info 
    unordered_map<string,int> emp_index;// link index to emp
    string emp[n];
    int g_size[n];
    int dep[n][3] ={{}};
    int m_d[3] = {f,s,t} ;
    int bgs=0;
    parent = new int[n];
    for(int i = 0;i<n;i++){
        string n;
        int d; 
        cin>>n>>d;
        emp_dep[n] = d;
        emp_index[n]= i;
        emp[i] = n;
        parent[i] = i;
        g_size[i] = 1;
        dep[i][emp_dep[n]-1] = 1;
    }
    // requests input 
    for(int i = 0;i<m;i++){
        string f_n,s_n;
        cin>>f_n>>s_n;
        int f=emp_index[f_n],s = emp_index[s_n];
        int f_root = find(f);
        int s_root = find(s);
        // size condition
        if(f_root==s_root){// already in same set
          continue;
        }
        if(g_size[f_root]+g_size[s_root] >b){
            continue;
        }
        // dep size condition
        if (dep[f_root][0]+dep[s_root][0]>m_d[0]
            or dep[f_root][1]+dep[s_root][1]>m_d[1]
            or dep[f_root][2]+dep[s_root][2]>m_d[2]){
            continue;
            }
        // both conditions fulfilled
        if (g_size[f_root] < g_size[s_root]){swap(f_root, s_root);}
        parent[s_root] = f_root;
        g_size[f_root] += g_size[s_root];
        dep[f_root][0] += dep[s_root][0];
        dep[f_root][1] += dep[s_root][1];
        dep[f_root][2] += dep[s_root][2];
        
        if (g_size[f_root]>bgs){
            bgs = g_size[f_root];  
        }
    }
    if(bgs<a){
        cout<<"no groups";
    }
    else{
    set<string> ans;    
    for(int i = 0;i<n;i++){
        int value = find(i);
        if(g_size[value]==bgs){
            ans.insert(emp[i]);
        }
    }
    for(auto i = ans.begin();i!=ans.end();++i){
        cout<<*i<<endl;
        }
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}