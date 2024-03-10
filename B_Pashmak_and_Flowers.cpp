#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    map<int,int>mp;
    for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    int mn_value = mp.begin()->first;
    int mx_value = mp.rbegin()->first;
    int mn_fre = mp.begin()->second;
    int mx_fre = mp.rbegin()->second;
    if(mp.size() == 1){
        cout << 0 <<" " << (1LL*mx_fre * (mx_fre-1))/2 << '\n';
    }else{
        cout << mx_value - mn_value <<" "<< (1LL*mx_fre * mn_fre) << '\n';
    }
}