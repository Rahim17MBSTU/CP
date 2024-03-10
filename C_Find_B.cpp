#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
  int n,q;
  cin >> n >> q;
  vector<int>v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  vector<int>pre(n+5,0),one_cnt(n+5,0);
  pre[1] = v[0];
  one_cnt[1] = (v[0] == 1 ? 1 : 0);
  for(int i = 1; i < n ; i++){
    pre[i+1]  = pre[i] + v[i];
    one_cnt[i+1] = one_cnt[i] + (v[i] == 1 ? 1 : 0);
  }
    while(q--){
      int l,r;
      cin >> l >> r;
      if( r == l){
        cout << "NO\n";
        continue;
      }
      int sum = pre[r] - pre[l-1] ; 
      int one_count = one_cnt[r] - one_cnt[l-1];
      int slot = r - l + 1;
      sum -= (2 * one_count );
      slot -= one_count;
      if(sum < slot){
        cout <<"NO\n";
      }else{
        cout <<"YES\n";
      }
    }
}
int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}