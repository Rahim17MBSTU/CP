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
     cin >> n;
     vector<pair<int,int>>vp;
     for(int i = 0;i< n; i++){
        int x , y;
        cin >> x >> y;
        vp.push_back({x,y});
     }
     int low = 0,high = 1e9+10,mid ,ans;
     auto f = [&](int mid){
        int indx = 0;
        for(int i=0;i<n;i++){
            int x = vp[i].first;
            int y = vp[i].second;
            if(x>=indx){
                indx+=mid;
                if(indx>=x && indx<=y){
                    continue;
                }else{
                    return false;
                }
            }else{
                indx -=mid;
                int xx = vp[i-1].first;
                int yy = vp[i-1].second;
                if(abs(xx-x)<=mid){
                    indx = x;
                    continue;
                }
                else if(abs(yy-y)<=mid){
                    indx = (x+y)/2;
                }
                else{
                    return false;
                }
                
            }
        }
        return true;
     };
     while(low <= high){
        mid = (low + high ) >> 1;
        if(f(mid)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
     }
    cout << ans << '\n';
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