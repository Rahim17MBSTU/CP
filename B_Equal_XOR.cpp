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
     int n,k;
     cin>>n >> k;
     n=2*n;
     k = 2*k;
     vector<int>v(n);in(v);
     vector<int>g1[n+2],g2[n+2];
     if(k==n/2){
        for(int i=0;i<n;i++){
            if(i<n/2){
                cout<<v[i]<<" ";
                

            }
            if(i==n/2){
                cout<<'\n';
            }
            if(i>=n/2){
                
                cout<<v[i]<<" ";
            }
        }
        cout<<endl;
        return;
     }
     map<int,int>mp1,mp2,res1,res2,v1,v2;
     set<int>s1,s2;
     for(int i=0;i<n;i++){
        if(i<n/2){
            //cout<<v[i]<<" ";
            s1.insert(v[i]);mp1[v[i]]++;
            g1[v[i]].push_back(i);
        }
        else{
            s2.insert(v[i]);
            mp2[v[i]]++;
            g2[v[i]].push_back(i);
        }
     }
    // debug(s1.size());
    // debug(s2.size());
     //vector<int>v1,v2;
     //vector<pair<int,int>>vp1,vp2;
    
     for(auto u:s1){
       // cout<<u<<" ";
        if(mp1[u]==2){
            v1[u]++;
            //cout<<u<<" ";
        }
     }
     for(auto u:s2){
        if(mp2[u]==2){
            v2[u]++;
        }
     }
     if(2*v1.size()>=k){
        int cnt =0;
        vector<bool>vv1(n,0),vv2(n,0);
        for(int i=0;i<n/2;i++){

            if(v1[v[i]]>=1&&vv1[v[i]]==0){
                //cout<<"aise\n";
               // cout<<v[i]<< " ";
                // int y = g1[v[i]].back();
                // g1[v[i]].pop_back();
                // int x = g2[v[i]].back();
                // g1[v[i]].pop_back();
                cnt++; cnt++;
                vv1[v[i]]=1;
                //cout<<x<<" "<<y
            }
            if(cnt>=k)break;
            
        }
        cnt=0;
        //cout<<"IDIS\n";
        //for(auto u:vv1)cout<<u<<" ";
        for(int i=0;i<n/2;i++){
            if(vv1[v[i]]==1){
                cout<<v[i]<<" ";
            }
        }
        cout<<endl;
        for(int i=n/2;i<n;i++){
            if(v2[v[i]]>=1&&vv2[v[i]]==0){
                //cout<<v[i]<<" "<<v[i]<<" ";
                cnt++;
                cnt++;
                 vv2[v[i]]=1;
            }
            if(cnt>=k)break;
            
        }
        
        //for(auto u:vv2)cout<<u<<" ";
       for(int i=n/2;i<n;i++){
            if(vv2[v[i]]==1){
                cout<<v[i]<<" ";
            }
        }
        cout<<endl;
        return;
     }
    // cout<<v1.size()<<endl;
     for(int i=0;i<n/2;i++){
        
        if(mp1[v[i]]==1 && mp2[v[i]]==1){
            // v1.push_back(v[i]);
            // v2.push_back(v[i]);
            res1[v[i]]++;
            res2[v[i]]++;
            //continue;
        }
        // if(mp1[v[i]]==2 && mp2[v[i]]==2){
        //      v1.push_back(v[i]);
        //     // v2.push_back(v[i]);
        //     res1[v[i]]++;
        //     res2[v[i]]++;
        //     //  v1.push_back(v[i]);
        //     // v2.push_back(v[i]);
        //     res1[v[i]]++;
        //     res2[v[i]]++;
        //     //continue;
        // }
        if(res1.size()==k){
           for(int j=0;j<n/2;j++){
                if(res1[v[j]]>=1)
                cout<<v[j]<< " ";
            }
            cout<<endl;
            for(int j=n/2;j<n;j++){
                if(res2[v[j]]>=1)cout<<v[j]<< " ";
            }
            cout<<endl;
            return;
        }
     }

     






    //     vector<bool>vv1(n,0),vv2(n,0);
    //     for(int i=0;i<n/2;i++){

    //         if(v1[v[i]]>=1&&vv1[v[i]]==0){
    //             cnt++; cnt++;
    //             vv1[v[i]]=1;
                
    //         }
    //         if(cnt>=k)break;
            
    //     }
    //     cnt=0;
    //     //cout<<"IDIS\n";
    //     //for(auto u:vv1)cout<<u<<" ";
    //     for(int i=0;i<n/2;i++){
    //         if(vv1[v[i]]==1){
    //             cout<<v[i]<<" ";
    //         }
    //     }
    //     cout<<endl;
    //     for(int i=n/2;i<n;i++){
    //         if(v2[v[i]]>=1&&vv2[v[i]]==0){
    //             //cout<<v[i]<<" "<<v[i]<<" ";
    //             cnt++;
    //             cnt++;
    //              vv2[v[i]]=1;
    //         }
    //         if(cnt>=k)break;
            
    //     }
        
    //     //for(auto u:vv2)cout<<u<<" ";
    //    for(int i=n/2;i<n;i++){
    //         if(vv2[v[i]]==1){
    //             cout<<v[i]<<" ";
    //         }
    //     }
    //     cout<<endl;
    int cnt = 0;
    for(auto u:v1){
        cout<<u.ff<<" "<<u.ff<<" ";
        cnt+=2;
    }
    
    for(auto u:res1){
        if(cnt>=k)break;
        cout<<u.first<<" ";
        cnt++;
        //if(cnt>=k)break;
    }
    cout<<endl;
    cnt=0;
     for(auto u:v2){
        cout<<u.ff<<" "<<u.ff<<" ";
        cnt+=2;
    }
    
    for(auto u:res1){
        if(cnt>=k)break;
        cout<<u.first<<" ";
        cnt++;
        //if(cnt>=k)break;
    }
cout<<endl;
     


       
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