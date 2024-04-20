#include<bits/stdc++.h>
using namespace std;

void solve()
{
     int n;
     cin>>n;
     if(n == 1){
        cout << 1 <<" " <<1<<'\n';
        cout << 1 << " " << 1 << " " << 1 <<'\n';
        return;
     }
     int totol_sum = 0,cnt=1;
     for(int i=1;i<=n;i++){
        totol_sum += (i*cnt);
        cnt+=2;
     }

     cout << totol_sum << " " << 2*n<<'\n';
     for(int i=n;i>=1;i--){
        for(int type = 2; type >=1 ;type--){
            cout<<type<<" "<< i <<" ";
            for(int j=1;j<=n;j++){
            cout << j <<" ";
            }
            cout << '\n';
        }
        
     }
       
}
int32_t main()
{
    
    int t=1;
    cin>>t;
    while(t--)
    {
          solve();
    }
}