#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve(){
    int n , k;
    cin >> n >> k;
        int x = 1, indx = 0 ;
        while(1){
            int y = n / x ;
            if(y % 2 == 0) y--;
            int value = (( y + 1) / 2);
            if(indx + value >= k){
               int low = 1, high = (( n + 1) /x ) ;
               if(high % 2 == 0) high--;
               while(low <= high){
                   int mid = (low + high ) >> 1;
                   if(mid % 2 == 0)mid--;
                   if(indx + (( mid + 1) / 2) == k){
                    cout << (x * mid) << '\n';
                    return;
                   }else{
                      if(indx+(( mid + 1 ) / 2) < k){
                          low = mid + 1;
                          if(low % 2 == 0) low++;
                      }else{
                        high = mid - 1;
                        if(high % 2 == 0) high--;
                      }
                   }
               }
                
            }else{
                indx += value;
            } 
            x*=2;
       }
   // }
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}