#include<bits/stdc++.h>
using namespace std;
// policy Based ds
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
typedef tree<long long , null_type, less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
     ordered_set os1,os2;
     vector<pair<int,int>>vp;
     while(n--){
        char ch;
        cin >> ch;
        if(ch == 'D'){
            int l,r;
            cin >> l >> r;
            os1.insert(l);
            os2.insert(r);
            vp.push_back({l,r});
        }else if(ch == 'Q'){
            int l, r;
            cin >> l >> r;
            int total_full_segment =os1.order_of_key(r+1) - os1.order_of_key(l);
            int end_point = os2.order_of_key(r+1)- os2.order_of_key(l);//debug(total_full_segment);
            //debug(end_point);
            cout<<(end_point+total_full_segment)<<endl;
            //int y = os2.size()-os2.order_of_key(l-1);
            // int front_value = os1.order_of_key(l+1)-os2.order_of_key(r);// (point+1) ar age koita start point ase - point ar age koita end point ase
            // int end_value =(os2.size()-os2.order_of_key(l-1))-(os1.size()-os1.order_of_key(r+1));
            // int x = os2.order_of_key(l+1) - os2.order_of_key(l);
            // int y = os1.order_of_key(r+1)-os1.order_of_key(r);
            //debug(x);debug(y);
           // cout<<min(front_value,end_value)+x+y<<'\n';
        }else{
            int indx ;
            cin >> indx;
            int first = vp[indx-1].first ;
            int second = vp[indx-1].second;
           // vp.erase(vp.begin() + indx-1); 
            //os1.erase(os1.find_by_order(os1.order_of_key(first)));
            os1.erase(os1.upper_bound(first));
            os2.erase(os2.upper_bound(second));
           // os2.erase(os2.find_by_order(os2.order_of_key(second)));
            // for(auto u:os1)cout<<u<<" ";
            // cout<<endl;
            // cout<<endl;
            // for(auto u:os2)cout<<u<<" ";
            // cout<<endl;

        }
     }
}
int32_t main()
{
    fast 
    int t=1;
    //cin>>t;
    while(t--)
    {
          solve();
    }
}