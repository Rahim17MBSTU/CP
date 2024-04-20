#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector <int> v;
    string s; cin >> s;
    char last  = '0';
    for(int i = 0; i < n  ; i += 2){
        if(s[i]!=s[i+1]){
          if(last != s[i]){
            v.push_back(i+1);
            last = s[i];
          }
          else {
            v.push_back(i+2);
            last = s[i+1];
          }
        }
    }
    cout << v.size() <<'\n';
    for(auto u:v){
        cout << u << ' ';
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