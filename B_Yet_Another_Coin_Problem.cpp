#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v{0,1,2,1,2,3,1,2,3,2,1,2,2,2,3,1,2,3,2,3,2,2,3,3,3,2,3,3,3,4,2};
        if(n<30)
        {
            cout << v[n] <<endl;continue;
        }
        int res =( n/15)+ v[n%15];
        int x =(n-15)/15;
        int res1 = (n-15)/15 + v[n-(x*15)];
        cout << min (res,res1) << endl;
        
    }
}