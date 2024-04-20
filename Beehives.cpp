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
const int N = 1e3+10;
vector<int>g[N];
int res = INT_MAX;
int col[N],par[N];
bool vis[N+5];
void dfs(int source,int p=-1){
    vis[source]=true;
    for(auto child:g[source]){
        if(!vis[child]){
            par[child] = source;
            dfs(child,source);
        }else if(child!= p){
            //cout<<"aise "<<source<<" " <<child<< " "<<p<<endl;
            int cnt = 1;
            int value = source;
            //cout<<par[source]<< " "<<par[1]<<endl;
            if(source == 0){
                continue;
            }
            while(child!=value && value!=0){
                value = par[value];cnt++;
                //debug(value);
               // debug(cnt);
                
            }
            res = min(res,cnt);
            //debug(res);
        }
    }
}
void solve()
{
     int n;
     cin>>n;
     int m;
     cin >> m;
     while(m--){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        sort(all(g[x]));
        sort(all(g[y]));
     }
    //  cout<<endl;
    //  for(int i=0;i<=4;i++)
    //  {
    //     cout<<"i="<<i<<"-> ";
    //     for(auto u:g[i]){
    //         cout<<u<<" ";
    //     }
    //     cout<<endl;
    //  }
    
     dfs(0,-1);
     if(res == INT_MAX){
        cout<<"impossible\n";

     }else{
        cout<<res<<'\n';
     }
     for(int i=0;i<N;i++){
        g[i].clear();
        col[i] = 0;
        par[i] = 0;
     }
     res = 0;

     
       
}
int32_t main()
{
    fast 
    int t=1,tc=0;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<++tc<<": ";
          solve();
    }
}