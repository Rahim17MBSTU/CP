#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    if(n<m){
        swap(n,m);
    }
    bool ok=0;
    int ans = abs(n-m);
    int X = 0;
    int mx_bit = log2(max({n,m,k}));
    for(int i = mx_bit; i >= 0; i--){
        int bit1 = n & (1LL << i);
        int bit2 = m & (1LL << i);
        if(bit1 >= 1 && bit2 == 0 && bit1 <= k){
            if(ok==0){
                ok=1;
                continue;
            }
          
            if(X+bit1<=k)
            X += bit1;
           
        }else{
            if(bit1!=bit2){
                ok=1;
            }
           
        }


    }
   
    int x = abs((n^X)-(m^X));
    cout << min(x,ans) <<'\n';
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
      solve();

    }
}