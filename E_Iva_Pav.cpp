// #include<bits/stdc++.h>
// using namespace std;
// // policy Based ds
// #include<ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
 
// typedef tree<long long , null_type, less<long long>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// // 1.*A.find_by_order(index) 2.order_of_key(value) 3. delete using s.erase(s.find_by_order(idx))
// #define order(s, x) s.order_of_key(x);
// #define element(s ,x) s.find_by_order(x);
// //------------Defines part-------------
// #define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define int long long int
// #define yes cout<<"YES\n";
// #define no cout<<"NO\n";

// #define gcd(a,b) __gcd(a,b)
// #define lcm(a,b) ((a*b)/gcd(a,b))

// #define pb(n) push_back(n)
// #define ff first
// #define ss second
// #define ve(x) vector<int> v(x)
// #define all(x)     x.begin(),x.end() 
// #define rall(x)    x.rbegin(),x.rend()
// #define in(v)      for(auto &item:v) cin>>item;
// #define in2D(v)    for(auto &D:v)for(auto &u:D)cin>>u;
// #define inp(v)     for(auto &item:v) cin>>item.ff>>item.ss;
// #define rep(i,n)   for(int i=0;i<n;i++)
// #define sp(n)      cout<<fixed<<setprecision(n)
// #define debug(x)   cout<<#x<<'='<<' '<<x<<endl;
// const int mod = 1e9+7;
// const int inf = 1e18;
// // Big O mod Template
// int bigmod(int base,int power)
// {
//    int res=1;
//      while(power!=0)
//      {
//        if(power%2==0)
//         {
//             base*=base;
//             power/=2;
//         }
//         else
//         {
//            res*=base;
//            power--;
//          }
//        }
//     return res;
//  }
// int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
// //--------------------------------------------------------------------------------------
// //						Code start here										   
// //-------------------------------------------------------------------------------------
// void solve()
// {
//      int n;
//      cin>>n;
//      vector<int>v(n);
//      for(int i=0 ;i<n;i++){
//       cin >> v[i];
//      }
//      vector<int>g[32];
//      int mx_value = *max_element(all(v));
//      //debug(mx_value);
//      int bit = log2(mx_value);
//      //debug(bit)
//      for(int i=0;i<n;i++){
        
//         for(int j=bit;j>=0;j--){
//             int value = 1<<j;
//             if((value & v[i]) == 0){
//               //cout<<"i ="<<i<<" j= "<<j<<" "<<value<<endl;
//               g[j].push_back(i+1);
//             }
//         }
//      }
//     //  for(int i=0;i<=bit;i++){
//     //   cout<<"i= "<<i<<" ->";
//     //   // if(g[i].empty()){
//     //   //   cout<<"Empty\n";
//     //   // }
//     //   for(auto u:g[i]){
//     //     cout<<u<<" ";
//     //   }
//     //   cout<<endl;
//     //  }
//      int q;
//      cin >> q;
//      while(q--)
//      {
//         int l,k;
//         cin >> l >> k;
//        // cout<<"l= "<<l<<" k= "<<k<<endl;
//         int sum = 0,mx = n;
//         bool ok = 0;
//         if(v[l-1] < k){
//           cout<< -1 << ' ';
//           continue;
//         }else{
//           for(int i=bit;i>=0;i--){
//             int bit_value = 1 << i;
//             if(g[i].empty()){
//                 if(bit_value >= k){
//                   ok = 1;
//                 }
//                 if(ok == 1){
//                   sum = bit_value;
//                   mx = max(mx,n);
//                 }else{
//                   sum += bit_value;
//                   mx = min(mx,n);
//                 }
//                 continue;
//             }
//             auto it = lower_bound(all(g[i]),l);
//             if(it == g[i].end()){
//                if(bit_value >= k){
//                  ok=1;
//                }
//                if(ok == 1){
//                 if(*it - 1<l){
//                    continue;
//                 }
//                 mx = min(mx,(*it)-1);
//                 sum = bit_value;
//                }else{
//                  if(*it - 1<l){
//                    continue;
//                 }
//                 mx = max(mx,(*it)-1);
//                 sum += bit_value;
//                }
//             }
//             else{
//               if(bit_value >= k){
//                  ok=1;
//                }
//                if(ok == 1){
//                 if(*it - 1<l){
//                    continue;
//                 }
//                 mx = min(mx,(*it)-1);
//                 sum = bit_value;
//                }else{
//                  if(*it - 1<l){
//                    continue;
//                 }
//                 mx = max(mx,(*it)-1);
//                 sum += bit_value;
//                }
//             }
            
//           }
          
//         }
//         //if(sum>=k){
//           cout<<mx<<" ";
//        // }
        

//      }
//      cout<<endl;
// }
// int32_t main()
// {
//     fast 
//     int t=1;
//     cin>>t;
//     while(t--)
//     {
//       solve();
//     }
// }
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
     vector<int>v(n);
     for(int i=0 ;i<n;i++){
      cin >> v[i];
     }
     vector<int>g[32];
     int mx_value = *max_element(all(v));
 
     int bit = log2(mx_value);
 
     for(int i=0;i<n;i++){
        
        for(int j=bit;j>=0;j--){
            int value = 1<<j;
            if((value & v[i]) == 0){
              g[j].push_back(i+1);
            }
        }
     }
    //  for(int i=0;i<=bit;i++){
    //   cout<<"i= "<<i<<" ->";
    //   // if(g[i].empty()){
    //   //   cout<<"Empty\n";
    //   // }
    //   for(auto u:g[i]){
    //     cout<<u<<" ";
    //   }
    //   cout<<endl;
    //  }
     int q;
     cin >> q;
     while(q--){
       int l,k;
       cin >> l>> k;
        if(v[l-1]<k){
          cout<<-1<<" ";
          continue;
        }
        int sum = 0,mx = n;
        bool ok = 0;
        int bit = log2(v[l-1]);
       for(int i = bit;i>=0;i--){
           auto it = lower_bound(all(g[i]),l);
           int value = 1<<i;
            if((1<<bit)>=k){
              if(g[i].empty()){
                sum = (1<<bit);
                continue;
              }else{
                if(value>=k && it!=g[i].end()){
                 cout<<"HHH= "<<(*it-1)<<endl;
                    if(mx<*it-1 && ok==0){
                      ok=1;
                      mx = *it-1;
                    }
                }
                //mx =min(mx,*it-1);
                debug(mx);
              }
            }else{
              //cout<<"aise\n";
              if(*it-1>=l){
                sum+=v[i];
                mx = min(mx,*it-1);
              }
              
            }

       }
      //  if((1<<bit)>=k){
      //   cout<<mx<<" ";
      //  }else{
      //   if(sum >= k){
           cout<<mx<< " ";
      //   }
      //  }
       
     }cout<<endl;
       
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