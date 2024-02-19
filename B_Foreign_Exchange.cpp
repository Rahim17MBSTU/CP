// #include<bits/stdc++.h>
// using namespace std;
// // policy Based ds
// #include<ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
 
// typedef tree<pair<long long,long long> , null_type, less<pair<long long,long long>>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// // 1.*A.find_by_order(index) 2.order_of_key(value) 3. delete using s.erase(s.find_by_order(idx))
// struct CompareBySecond {
//     bool operator()(const pair<long long, long long>& a, const pair<long long, long long>& b) const {
//         return a.second > b.second;
//     }
// };

// // Define ordered_set with custom comparator
// typedef tree<pair<long long, long long>, null_type, CompareBySecond, rb_tree_tag, tree_order_statistics_node_update> ordered_set_by_second;
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
// typedef pair<int, int> pi; 
// //--------------------------------------------------------------------------------------
// //						Code start here										   
// //-------------------------------------------------------------------------------------
// void solve()
// {
//      int n;
//      cin>>n;
//      ordered_set pq;
//      vector<int>v(n);in(v);
//      int q=n-1;
//      vector<pair<int,int>>vp(n-1);
//      for(int i=0;i<n-1;i++){
//         int x,y;
//         cin >> x >> y;
//         vp[i] = make_pair(x,y);
//      }
//      for(int i=0;i<n;i++){
//         pq.insert({i,v[i]});
//      }
//     for(auto u:pq){
//         cout<<u.first<<" "<<u.second<<endl;
//     }
//     //  while(1){
//     //     auto it = pq.end();
        
//     //     it--;
//     //     pq.erase(it);
//     //     int indx = it->second;
//     //     int value = it->first;
//     //     if(indx == n-2){
//     //         auto it1 = pq.end();
//     //         it1--;
//     //         int result = it->first + vp[indx].second;
//     //         cout << result << '\n';
//     //         return ;
//     //     }else{
//     //         int add_value =  value - vp[indx].first;
//     //         int new_indx = indx;
            
//     //         pq.erase(s.find_by_order(idx));
//     //     }
//     //  }
    


// }
// int32_t main()
// {
//     fast 
//     int t=1;
//     //cin>>t;
//     while(t--)
//     {
//           solve();
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
bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;

    }
    else{
        return p1.second<p2.second;
    }
}
void solve()
{
     int n;
     cin>>n;
     vector<int>v(n);
     in(v);
     vector<pair<int,int>>vp,pq;
     for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        vp.push_back({x,y});
     }
     for(int i=0;i<n;i++){
        pq.push_back({i,v[i]});
     }
     sort(all(pq),comp);
     for(auto u:pq){
        cout<<u.first<<" "<<u.second<<endl;
     }
     while(1){
        int indx = pq.back().first;//1
        int value = pq.back().second;// 7
        int v1 = vp[indx].first;//4
        int v2 = vp[indx].second;//3
        pq.pop_back();
        pq.push_back({indx,value - v1});

        auto it = find(pq.begin(),pq.end(),indx+1);
        int val = it->second;
        int ind = it->first;
        it->second += v2;
        pq[indx].second -= v1;
        pq[indx+1].second += v2; 
        if(indx == n-1){
            cout << pq[indx+1].ss << '\n';
            return;
        }
        sort(all(pq),comp);
     }
}
int32_t main()
{

    fast 
    int t=1;
   // cin>>t;
    while(t--)
    {
          solve();
    }
}