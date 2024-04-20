#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define inf 1e19
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int N = 5e5+10;
struct Node{
    int mx1,mx2,mn1,mn2;

}tree[4*N];
int a[N];
// Node marge(Node l, Node r){
//     if(l.mn1 == inf)return r;
//     if(r.mx1 == inf)return l;
//     Node demo;// left child [-1,2] [1,4]
//     demo.mx1 = max(l.mx1,r.mx1);
//     demo.mn1 = min(l.mn1,r.mn1);
//     demo.mx2 = min(max(l.mx1, r.mx2), max(l.mx2, r.mx1));

//     // Finding second minimum value
//     demo.mn2 = max(min(l.mn1, r.mn2), min(l.mn2, r.mn1));
//     //demo.mx2 = min(l.mx1,r.mx1);//min(min(l.mx1,r.mx1),max(l.mx2,r.mx2));
//     //demo.mn2 = max(max(l.mn1,r.mn1),min(l.mn2,r.mn2));
//     // if(demo.mx1 == r.mx1){
//     //     demo.mx2 = l.mx2;
//     // }else{
//     //     demo.mx2 = min(l.mx1,r.mx1);
//     // }
//     // if(l.mn2 == r.mn2){
//     //     demo.mn2 = l.mn2;
//     // }else{
//     //     demo.mn2 = max(l.mn2,r.mn2);
//     // }
//     // if(l.mn2 != r.mn2){
//     //     demo.mn2 = max(l.mn2,r.mn2) == demo.mx1 ? min(l.mn2,r.mn2): max(l.mn2,r.mn2);
//     // }else{
//     //     demo.mn2 = l.mn2;
//     // }
//     //demo.mn2 = min(max(l.mn2,r.mn2),min(l.mn2,r.mn2));
//     //demo.mn2 = min(l.mn2,r.mn2);
//     return demo;
// }
Node marge(Node l, Node r){
    if(l.mn1 == inf) return r;
    if(r.mx1 == inf) return l;
    
    Node demo;
    // demo.mx1 = max(l.mx1, r.mx1); // First maximum value
    // demo.mn1 = min(l.mn1, r.mn1); // First minimum value
    
    //  demo.mx1 = max(l.mx1, r.mx1);
    //  demo.mx2 = (l.mx1 == r.mx1) ? r.mx1 : max({ min(l.mx1, r.mx1), l.mx2, r.mx2 });
    //  demo.mn1 = min(l.mn1, r.mn1);
    //  demo.mn2 = (l.mn1 == r.mn1) ? r.mn1 : min({ max(l.mn1, r.mn1), l.mn2, r.mn2 });




    set<int>s;
    
    
    s.insert(l.mx1);s.insert(l.mx2);
    s.insert(l.mn1);s.insert(l.mn2);
    s.insert(r.mx1);s.insert(r.mx2);
    s.insert(r.mn1);s.insert(r.mn2);
    auto it = s.rbegin();
    
    int value = 0,cnt = 0,sz = s.size();
    for(auto u:s){
        cnt++;
        value = u;

        if(cnt == 2)break;
    }
    if(sz == 1){
        demo.mn2 = demo.mx2 = value;
    }
    if(sz == 2){
       
        demo.mn2 = value;
         it--;
        demo.mx2 = *it;
    }
    else if(sz == 3){
        demo.mn2 = value;
      it--;
        demo.mx2 = *it;
    }
    else {
        demo.mn2 = value;
       it--;
        demo.mx2 = *it;
    }
    return demo;
}

void build(int node,int l,int r){
    if(l == r){
        tree[node].mx1 = tree[node].mx2 =tree[node].mn1 = tree[node].mn2 = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    int left = 2 * node;
    int right = 2 * node + 1;
    build(left , l ,mid);
    build(right, mid+1,r);
    tree[node] = marge(tree[left],tree[right]);
}
Node query(int node,int b,int e,int l,int r){
    // b---e l----r b----e
    if(e<l || r<b){
        Node k; 
        k.mx1 = k.mx2 = k.mn1 = k.mn2 = inf;
         return k;
    }
   
    if(l<=b && e<=r){
        return tree[node];
    }
    int mid = (l + r) >> 1;
    int left = 2  * node;
    int right = 2 * node + 1;
    query(left,b,e,l,mid);
    query(right,b,e,mid+1,r);
    return marge(tree[left],tree[right]);
}
void solve()
{
     int n,k;
     cin >> n >> k;
     for(int i = 1; i <= n; i++)   {
        cin >> a[i];
     }
     build(1,1,n);
     for(int i=1;i<14;i++){
        cout <<"i= "<<i<<"-> ";
        cout << tree[i].mx1 <<" "<< tree[i].mx2 <<" "<<tree[i].mn1 << " " << tree[i].mn2 << endl;
     }
     while(k--){
        int l,r;
        cin >> l >> r;//l++;r--;
        Node ans = query(1,l,r,1,n);
        int mx1 = ans.mx1;
        int mx2 = ans.mx2;
        int mn1 = ans.mn1;
        int mn2 = ans.mn2;
        long long int res = mx1 * mx2 * mn1 * mn2 ;
        cout << res << '\n';
     }
}
int32_t main()
{
    fast 
    int t=1;
  //   cin>>t;
    while(t--)
    {
          solve();
    }
}