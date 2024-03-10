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
int countPaths(const vector<string>& grid, const string& path) {
    int n = grid[0].size();
    int m = grid.size();

    
    vector<vector<int>> dp(m, vector<int>(n, 0));

   
    dp[0][0] = (grid[0][0] == path[0]) ? 1 : 0;

    
    for (int j = 1; j < n; ++j) {
        if (grid[0][j] == path[j] && dp[0][j - 1] > 0)
            dp[0][j] = 1;
    }

   
    for (int i = 1; i < m; ++i) {
        if (grid[i][0] == path[i] && dp[i - 1][0] > 0)
            dp[i][0] = 1;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

   
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == path[i + j] && (dp[i - 1][j] > 0 || dp[i][j - 1] > 0))
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    
    return dp[m - 1][n - 1];
}
void solve()
{
     int n;
     cin>>n;
     
     vector<string>a(2);
     string s="";
      for (int i = 0; i < 2; ++i) {
        cin >> a[i];
    }

     s+=a[0][0];
     int row0= 0,row1=1;
     for(int i=1;i<n;i++){
         if(a[row0][i]<=a[row1][i-1]){
            s+=a[row0][i];
            
         }else{
            s+=a[row1][i-1];
            for(int j=i;j<n;j++){
                s+=a[row1][j];
                
                
            }
            cout<<s<<'\n';
            cout<<countPaths(a,s)<<'\n';
            return;
         }
     }
     s+=a[1][n-1];
     cout<<s<<endl;
     cout<<countPaths(a,s)<<'\n';
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