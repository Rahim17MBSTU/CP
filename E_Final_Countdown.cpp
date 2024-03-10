#include<bits/stdc++.h>
using namespace std;
// 1 2 3 4 5 6 7 8 = 36
//   1 2 3 4 5 6 7 = 28
//     1 2 3 4 5 6 = 21
//       1 2 3 4 5 = 15 
//         1 2 3 4 = 10
//           1 2 3 = 6
//             1 2 = 3
//               1 = 1
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    while(s.back()=='0'){
        s.pop_back();
    }
    n = s.size();
    vector<int>v,res;
    reverse(s.begin(),s.end());
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += s[i]-'0';
        v.push_back(sum);
    }
    sum = 0;
    while(!v.empty()){
        sum += v.back();
        v.pop_back();
        int rem = sum % 10;
        sum/=10;
        res.push_back(rem);
    }
    if(sum!=0){
        res.push_back(sum);
    }
    reverse(res.begin(),res.end());
    for(auto u:res)cout << u;
    cout<<'\n';

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}