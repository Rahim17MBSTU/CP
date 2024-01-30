#include<bits/stdc++.h>
using namespace std;
void solve()
{
     int n;
     cin>>n;
     vector<int>v1(n),v2(n);
     for(auto &u:v1)cin>>u;
     for(auto &u:v2)cin>>u;
     vector<pair<int,int>>vp;
     for(int i=0;i<n;i++){
        vp.push_back({v1[i],v2[i]});
     }
     sort(vp.begin(),vp.end());
     for(auto u:vp)
     cout<<u.first<<" ";
     cout<<'\n';
     for(auto u:vp){
        cout<<u.second<< " ";
     }
     cout<<'\n';
       
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
          solve();
    }
}