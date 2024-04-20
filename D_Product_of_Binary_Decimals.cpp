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
const int N = 1e7+10;
vector<bool>b(N,0);
void solve()
{
     int n;
     string s;
     cin >> s;
     vector<int>v({10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111,10000,10001,10010,10011,10100,10101,10110,10111,11000,11001,11010,11011,11100,11101,11110,11111});
     n = stoi(s);
     bool ok=0;
     for(int i=0;i<s.size();i++){
        if((s[i]-'0')>=2){
            ok=1;
            break;
        }
     }
     if(ok==0){
        cout<<"YES\n";
     }else{
          
          for(auto u:v){
              
             while(n%u==0){

             
             if(n%u==0){
               
                string ss=to_string(n/u);
                bool okk=0;
              
                for(int i=0;i<ss.size();i++){
                    if(ss[i]-'0'>=2){
                        okk=1;
                        break;
                    }
                }
                n/=u;
                if(okk==0){
                    cout<<"YES\n";
                    return;
                }
                }
             }
          }
          cout<<"NO\n";
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