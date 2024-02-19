#include<bits/stdc++.h>
using namespace std;
// policy Based ds
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
typedef tree<long long , null_type, less<long long>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// 1.*A.find_by_order(index) 2.order_of_key(value) 3. delete using s.erase(s.find_by_order(idx))
#define order(s, x) s.order_of_key(x);
#define element(s ,x) s.find_by_order(x);
//------------Defines part-------------
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long int
#define yes cout<<"YES\n";
#define no cout<<"NO\n";

#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a*b)/gcd(a,b))

#define pb(n) push_back(n)
#define ff first
#define ss second
#define ve(x) vector<int> v(x)
#define all(x)     x.begin(),x.end() 
#define rall(x)    x.rbegin(),x.rend()
#define in(v)      for(auto &item:v) cin>>item;
#define in2D(v)    for(auto &D:v)for(auto &u:D)cin>>u;
#define inp(v)     for(auto &item:v) cin>>item.ff>>item.ss;
#define rep(i,n)   for(int i=0;i<n;i++)
#define sp(n)      cout<<fixed<<setprecision(n)
#define debug(x)   cout<<#x<<'='<<' '<<x<<endl;
const int mod = 1e9+7;
const int inf = 1e18;
// Big O mod Template
int bigmod(int base,int power)
{
   int res=1;
     while(power!=0)
     {
       if(power%2==0)
        {
            base*=base;
            power/=2;
        }
        else
        {
           res*=base;
           power--;
         }
       }
    return res;
 }
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
//--------------------------------------------------------------------------------------
//						Code start here										   
//-------------------------------------------------------------------------------------
void solve()
{
     int n;
     cin>>n;
     char trump;
     cin >> trump;
     vector<string>g[26];
     for(int i=0;i<2*n;i++){
        string s;
        cin >> s;
        g[s[1]-'A'].push_back(s);
     }
     int x = 0;
     for(int i=0;i<25;i++){
        if(g[i].size()>=1){
            sort(g[i].begin(),g[i].end());
            x += g[i].size()%2;
            // cout<<"i = "<<(char)(i+65)<<"-> ";
            // for(auto u:g[i]){
            //     cout<<u<<" ";
            // }
            // cout<<endl;
        }
     }
    
     vector<pair<string,string>>vp;
     for(int i=0;i<=25;i++){
        if(g[i].size()>=1 && i!= trump-'A'){
             while(!g[i].empty()){
                if(g[i].size()>=2){
                    string lst = g[i].back();g[i].pop_back();
                    string fst = g[i].back();g[i].pop_back();
                    vp.push_back({fst,lst});
                }else{
                    string fst = g[i].back();
                    g[i].pop_back();
                    if(g[trump-'A'].size()>=1){
                     string lst = g[trump-'A'].back();
                     g[trump-'A'].pop_back();
                     vp.push_back({fst,lst});
                    }
                    else{
                        cout <<"IMPOSSIBLE\n";
                        return;
                    }
                }
            }
            //cout<<endl;
        }
     }
     int trump_indx = trump-'A';
     if(g[trump-'A'].size()%2==0){
        while(!g[trump_indx].empty()){
            string lst = g[trump_indx].back();
            g[trump_indx].pop_back();
            string fst = g[trump_indx].back();
            g[trump_indx].pop_back();
            vp.push_back({fst,lst});
        }
     }
     for(auto u:vp){
        cout<<u.first<<" "<<u.second<<endl;
     }
     
}
int32_t main()
{
    fast 
    int t=1;
    cin>>t;
    while(t--)
    {
          solve();
    }
}