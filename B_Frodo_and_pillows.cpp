#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n, pillows, Fadro_pos;
    cin >> n >> pillows >> Fadro_pos ;
    int low = 0, high = 1e9 + 10, mid , ans ;
    if( n == pillows ){
        cout << 1 << '\n';
        return;
    }
    auto checked = [&](int mid){
        
        int left_ans = 0, right_ans = 0, minimum_need = 0;
    
        int left_interval = Fadro_pos;//Fadro pos
        int right_interval = n - Fadro_pos ;// n - Fedro pos
        int sum = 0;
        if(mid >= left_interval) {
            sum = (mid * (mid+1)) >> 1;
            int x = mid - left_interval ;
            sum -= ((x * (x + 1))  >> 1 ) ;
        }else{
            sum = (mid * (mid+1)) >> 1;
            int left_remaining = Fadro_pos - mid ;
            sum += left_remaining;
        }
        left_ans = sum ; 
        
        sum = 0;
        if(mid > right_interval) {
            sum = (mid * (mid-1)) >> 1;
            int x = mid - right_interval ;
            sum -= ((x * (x - 1))  >> 1 ) ;
        }else{
            sum = (mid * (mid - 1)) >> 1;
            int right_remaining = right_interval - (mid - 1) ;
            sum += right_remaining;
        }
        right_ans = sum ;
        int total = left_ans + right_ans;
        
        return total <= pillows;
    };
    while(low <= high){
        mid = (low + high) >> 1;
        if(checked(mid)){
            ans = mid ; 
            low = mid + 1;

        }else{
            high = mid - 1;
        }
    } 
    cout << ans <<'\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
}