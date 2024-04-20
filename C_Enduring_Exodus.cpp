#include<bits/stdc++.h>
using namespace std;


int Binary_search(int l,int r, string s,deque<int>&dq){
   int left = l;
   int right = r;
   int ans = right - left;
   int low = 0, high = dq.size()-1;
   while(low <= high){
      int mid = (low + high ) >> 1;
      int x = abs(dq[mid] - left);
      int y = abs(right - dq[mid]);
      if(x >= y){
         ans = min(ans,max(x,y));
         high = mid - 1;
      }else{
         ans = min(ans,y);
         low = mid + 1;
      }
   }
   return ans; 
}


void solve(){
   int n, k;
   cin >> n >> k;
   string s;
   cin >> s;
   deque<int>dq;
   int i=0 ,cnt = 0, left_indx = -1 , right_index = -1;
   bool ok = 0;
   // apply in sliding window and find k+1 th zero or blank room 
   for(i = 0;i< n; i++){ /// this is my first window 
      if(cnt == k+1)break;
      if(s[i] == '0'){
         cnt ++ ;
         dq.push_back(i);
         
      }
      
   }
   left_indx = dq.front();
   right_index = dq.back();
   int ans = right_index - left_indx;
   ans = min(ans, Binary_search(left_indx ,right_index , s,dq) ); // search for first window
   
   for(;i<n;i++){ // 
      if(s[i] == '0'){
         dq.pop_front();
         dq.push_back(i);
         left_indx = dq.front();
         right_index = dq.back();
         ans = min(ans, Binary_search(left_indx ,right_index , s,dq) );
        
      }
   }
   cout << ans << '\n';
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int t = 1;
   while(t--){
      solve();
   }
}