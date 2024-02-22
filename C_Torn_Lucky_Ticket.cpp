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
     vector<int>odd,even; // odd length , even length of vector

     for(int i=0;i<n;i++)      {
         int x; cin >> x;
         string s = to_string(x);
         if(s.size() & 1){
            odd.push_back(x);
         }else
         even.push_back(x);
     }

     sort(all(odd));
     sort(all(even));

     int ans = 0;
     map<pair<int,int>,int>one,three,five,two,four;

     for(auto u:odd){  // all odd length of element
        string s = to_string(u);
        if(s.size() == 1){
            
            ans += one[{u,0}]; 
            ans += one[{0,u}];
            
            one[{u,0}]++;
            one[{0,u}]++;
        
        }else if(s.size() == 3){
          
            int sum = 0;
            for(int i=0;i<s.size();i++){
                sum += s[i]-'0';
            }
            
            ans += three[{sum,0}];
            ans += three[{0,sum}];
            
            three[{sum,0}]++;
            three[{0,sum}]++;

            int left = 0;
            int right = 0;

            left = (s[0]-'0') + (s[1] - '0');
            right = s[2]-'0';
            
            if(left > right){
                ans += one[{0,left-right}];
            }else if(left < right){ 
                ;
            }
        
            left = s[0]-'0' ;
            right =(s[1] - '0') + (s[2]-'0');
            
            if(left > right){
                ;
            }else if(left < right){
                ans += one[{right-left,0}];
            }
       

        }else{
            
            int sum = 0;

            for(int i=0;i<s.size();i++){
                sum += s[i]-'0';
            }
            
            ans += five[{sum,0}];
            ans += five[{0,sum}];
            
            five[{sum,0}]++;
            five[{0,sum}]++;
          
            int left = 0;
            int right = 0;

            left = (s[0]-'0') + (s[1] - '0') + (s[2]- '0') + (s[3]-'0');
            right = s[s.size()-1]-'0';
            
            if(left > right){
                ans += three[{0,left-right}];
            }else if(left < right){
                ;
            }

            left = s[0]-'0';
            right = sum - (s[0]-'0');
            
            if(left > right){
                ;
            }else if(left < right){
                ans += three[{right-left,0}];
            }

            left = s[0]-'0' + s[1]-'0' + s[2]-'0';
            right = s[3]-'0' + s[4] - '0';


            if(left > right){
                ans += one[{0,left-right}];
            }else if(left < right){
                ;
            }

            left = s[0]-'0' + s[1]-'0' ;
            right = s[2]-'0' + s[3]-'0' + s[4] - '0';

            if(left > right){
                ;
            }else if(left < right){
                ans += one[{right-left,0}];
            }
        }
     }

     for(auto u:even){
        string s = to_string(u);

        if(s.size() == 2){
            int sum = 0;
            for(auto u:s){
                sum += u-'0';
            }

            ans += two[{sum,0}];
            ans += two[{0,sum}];

            two[{sum,0}]++;
            two[{0,sum}]++;

        }else{

            int sum = 0;
            for(auto u:s){
                sum += u-'0';
            }

            ans += four[{sum,0}];
            ans += four[{0,sum}];

            four[{sum,0}]++;
            four[{0,sum}]++;

            int left = s[0]-'0' + s[1] -'0' + s[2]-'0';
            int right = s[3] - '0';
            
            if(left > right){
                ans += two[{0,left-right}];
            }else if(left < right){
                ;
            }

            left = s[0]-'0' ;
            right = s[1] -'0' + s[2]-'0' + s[3] - '0';

            if(left > right){
              
                ;
            }else if(left < right){
                ans += two[{right-left,0}];
            }
        }
     }
     ans += n;
     cout << ans <<'\n';
}
int32_t main()
{
    fast 
    int t=1;
    
    while(t--)
    {
          solve();
    }
}