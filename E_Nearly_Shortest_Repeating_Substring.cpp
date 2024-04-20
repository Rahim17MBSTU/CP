#include<bits/stdc++.h>
using namespace std;
bool calculate(string ss,string s){
    int cnt = 0,j=0;
    int n = s.size();
    for(int i=0;i<n;i++){
        
        if(s[i] == ss[j]){
            j++;
            
        }
        else{
            j++;
            cnt++;
        }
        if(j >= ss.size()){
            
            j = 0;
        }
        if(cnt>=2){
         
            return 0;
        }

    }
    
    return 1;
}
void solve()
{
     int n;
     cin>>n;
     string s;
     cin >> s;
     int temp = n;
     int mn = INT_MAX;
     for(int i=1;i*i<=n;i++){ 
         if(n % i == 0){
            string ss = s.substr(0,i);
            string sss = s.substr(n-i,i);   
            if(calculate(ss,s) == 1 || calculate(sss,s) == 1){
                mn = min(mn,i);
            }  
            string ss1 = s.substr(0,n/i);
            string sss1 = s.substr(n-(n/i),n/i);   
            if(calculate(ss1,s) == 1 || calculate(sss1,s) == 1){
                mn = min(mn,n/i);
            }  
            
         }
     }
     cout << mn << '\n';
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
          solve();
    }
}