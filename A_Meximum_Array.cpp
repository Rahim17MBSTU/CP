#include<bits/stdc++.h>
using namespace std;
const int N  = 2e5+10;
vector<int>fre(N,0),fre1(N,0);
void solve(){
    int n;
    cin >> n;
    vector<int>suffix_mex(n+5,-1),v(n),res;
    for(int i = 0 ;i < n; i++){
        cin >> v[i];
    }
    int mex = 0;
    for(int i = n-1; i >= 0; i--){
        fre[v[i]]++;
        if(fre[mex]>=1){
             while(fre[mex]>=1){
                mex++;
             }
             suffix_mex[i] = mex;
        }else{
            suffix_mex[i] = mex;
        }
       
    }

     int find_mex = suffix_mex[0];
      mex = 0;
    map<int,int>mp;
    int search_mex = suffix_mex[0];
    for(int i=0;i<n;i++){
        if(search_mex == mex ){
            
                    res.push_back(search_mex);
                    search_mex = suffix_mex[i+1];
                    mp.clear();
                    mex = 0;
                   
            }
        mp[v[i]]++;
        if(mp[mex]>=1){
            bool ok=0;
            while(mp[mex]>=1){
                mex++;
                if(search_mex == mex){
                  
                    res.push_back(search_mex);
                    search_mex = suffix_mex[i+1];
                    mex = 0;
                    mp.clear();
                    ok=1;
                    break;
                }
            }
            if(search_mex == mex && ok==0){
               
                    res.push_back(search_mex);
                    search_mex = suffix_mex[i+1];
                    mp.clear();
                    mex = 0;
                    break;
            }
        }else{
            
            
        }
    }
    
    if(search_mex == mex ){
                    res.push_back(search_mex);
                   
                    mp.clear();
                    mex = 0;
                   
            }
   
    cout << res.size() <<'\n';
    for(auto u:res){
        cout << u << " ";
    }
    cout << '\n';

    for(int i=0;i<N;i++){
        fre[i] = 0;
    }
    
    
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}