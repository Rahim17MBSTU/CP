#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n , k;
    cin >> n  >> k;
    n = 2 * n;
    k = 2 * k;
    vector<int>v(n);
    map<int,int>mp1,mp2;
    set<int>s1,s2;
    for(int i = 0; i < n ; i++){
        cin >> v[i];
        if(i<n/2){
            s1.insert(v[i]);
            mp1[v[i]]++;
        }
        else{
            s2.insert(v[i]);
            mp2[v[i]]++;
        }
    }
    if(k == n/2){
        for(int i = 0 ; i <n ; i++){
            if(i<n/2){
                cout << v[i] << " ";
            }

            else{
                if(i == n/2) cout << '\n';
                cout << v[i]<<" ";
            }
        }
        cout <<'\n';
        return;
    }
    vector<int>v1,v2,res1,res2;
    for(auto u:s1){
        if(mp1[u] == 2){
            v1.push_back(u);
        }
    }
    for(auto u:s2){
        if(mp2[u] == 2){
            v2.push_back(u);
        }
    }
    
    if(k<=v1.size()*2){
        
       int cnt = 0;
       for(auto u:v1){
          cout << u << " " << u << ' ';
          cnt+=2;
          if(cnt >= k)break;
       }
       cout << '\n';
       cnt  = 0;
       for(auto u:v2){
        cout << u << " " << u << " ";
        cnt += 2;
        if(cnt >= k)break;
       }
       cout << '\n';
       return;
    }
    for(auto u:s1){
        if(mp1[u] == 1 && mp2[u]==1){
            res1.push_back(u);
        }
    }
    int cnt = 0;
   
    for(auto u:v1){
        cout << u <<" " << u << " ";
        cnt+=2;
        
    } for(auto u:res1){
        cout << u << ' ';
        cnt++;if(cnt >= k)break;
    }
    cnt = 0;
    cout<<"\n";
    
    for(auto u:v2){
        cout << u <<" " << u << " ";
        cnt+=2;
        
    }
    for(auto u:res1){
        cout << u << ' ';
        cnt++;if(cnt >= k)break;
    }
    cout << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}