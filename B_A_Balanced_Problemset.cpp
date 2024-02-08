#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n,m;
    cin >> n >> m;
    set<int>s;
    int mx = 1;
    for(int i = 1; 1LL*i*i <= n; i++){
        if(n % i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    for(auto u:s){
       
        int value = m * u;// overflow kore 
        if(value > n){
            continue;
        }
        else{
            
            int rem = n - value;
            if(rem % u ==  0){
                mx = max(mx,u);
            }
        }

    }
    cout << mx << '\n';
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}