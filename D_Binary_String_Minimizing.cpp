#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int>one_position;
    for(int i = 0; i < n;i++){
        if(s[i] == '0')one_position.push_back(i);
    }
    if(one_position.empty()){
        cout << s << '\n';
        return ;
    }
    reverse(one_position.begin(),one_position.end());
    for(int i=0;i<n;i++){
        if(one_position.empty())break;
        if(s[i]!=0){
            int value = one_position.back()-i;
            if(value <= k && value != -1){
                swap(s[i],s[one_position.back()]);
                one_position.pop_back();
                k-=value;
            }
            else{
                continue;
            }
        }
    }
    cout << s << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}