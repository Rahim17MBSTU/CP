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
const int N = 1e6+10,M = 1415;
vector<int>v(N,0);
void calculate(){
    int sum  =0 ;
    for(int i = 1; i<=1e6;i++){
        sum +=(i*i);
        v[i] = sum;
    }
    
}
int help(int n){
    int low = 1,ans = 0,high = 1416;
    while(low<=high){
        int mid = (low+high) >> 1;
        int x = (mid*(mid+1))/2;
        if(x<n){
            ans = mid;
            low = mid+1;
        }else{    
          high = mid-1;
        }
     }
     return ans+1;
}
void solve()
{
     int n , res = 0;
     cin>>n;
     int value = help(n) ;
     int right = value * (value + 1)/2;
     int left = right - value + 1;
  
     int l = n, r = n;
     while(1){
         if(l == left && r == right){
            
            res += v[r];
            cout << res << '\n';return;
         }
         else if(r == right){
            res += (v[r] - v[l-1]);
            r = ( r - value );
            l = l - value ;

         }else if(l == left){
            res += (v[r] - v[l-1]);
            r = (r - value) + 1;
            l = (l - value) + 1;
         }else {
            res += (v[r] - v[l-1]);
            r =( r - value )+ 1;
            l = l - value ;
         }
         
        
         value--;
         right = (value * (value + 1)) >> 1;
         left = right - value + 1;
         if(l <= 0 || r<=0 || value <=0)break;
     }
     cout << res <<'\n';
}
int32_t main()
{
    fast 
    int t=1;
    calculate();
    cin>>t;
    while(t--)
    {
          solve();
    }
}