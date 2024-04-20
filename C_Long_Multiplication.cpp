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
//#define int long long int
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
    
     string s1,s2;cin>>s1>>s2;
     int mx1=0,mx2=0;bool ok=0;
     for(int i=0;i<s1.size();i++){
        if(s1[i] == s2[i]){
            
            continue;
        }
        else{
            
            if(mx1>mx2){
                int mn = min(s1[i]-'0',s2[i]-'0');
                int mx = max(s1[i]-'0',s2[i]-'0');
                s1[i] = mn + '0';
                s2[i] = mx + '0';
                continue;
            }if(mx1<mx2){
                int mn = min(s1[i]-'0',s2[i]-'0');
                int mx = max(s1[i]-'0',s2[i]-'0');
                s2[i] = mn + '0';
                s1[i] = mx + '0';
                continue;
            }
            mx1 = max(mx1,s1[i]-'0');
            mx2 = max(mx2,s2[i]-'0');
            ok = 1;

        }
     }
       cout<<s1<<'\n';
       cout<<s2<<'\n';
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