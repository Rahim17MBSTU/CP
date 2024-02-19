#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n , x , y;
    cin >> n >> x >> y;
    map<pair<int,int>,int>mp;
    vector<int>v(n),v1(n),v2(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        v1[i] = v[i] % x;
        v2[i] = v[i] % y;
    }
    long long int ans = 0;
    for(int i = 0; i < n ;i++){
        int value = v1[i] ;
        if(value == 0){
            ans+=mp[{0,v2[i]}];
            ans+=mp[{x-value,v2[i]}];
        }
        else{
            ans+=mp[{x-value,v2[i]}];
        }
        mp[{v1[i],v2[i]}]++;
    }
    cout << ans <<'\n';
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}