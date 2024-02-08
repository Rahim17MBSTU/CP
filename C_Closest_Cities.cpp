#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int>v(n),dif1,dif2,res1,res2;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    dif1.push_back(1e9);
    dif2.push_back(1e9);
    for(int i=1;i<n;i++){
        dif1.push_back(abs(v[i]-v[i-1]));
    }
    res1.push_back(0);
    res2.push_back(0);
    for(int i=1;i<n;i++){
        if(dif1[i]<=dif1[i-1]){
            res1.push_back(1);
        }else{
            res1.push_back(dif1[i]);
        }
    }
    dif1.push_back(1e9);
    for(int i=n-1;i>=1;i--){
        if(dif1[i]<=dif1[i+1]){
            res2.push_back(1);
        }else{
            res2.push_back(dif1[i]);
        }
    }
    reverse(res2.begin(),res2.end());
    int a[n+2],b[n+2];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++){
        a[i+1] = res1[i] + a[i];
    }
    for(int i=0;i<n;i++){
        b[i+1] = res2[i] + b[i];
    }
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        if(l<=r){
            cout<<a[r]-a[l]<<"\n";
        }
        if(l> r){
            cout << b[l-1] - b[r-1] <<'\n';
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}