#include <bits/stdc++.h>
using namespace std;
// policy Based ds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// 1.*A.find_by_order(index) 2.order_of_key(value) 3. delete using s.erase(s.find_by_order(idx))
#define order(s, x) s.order_of_key(x);
#define element(s, x) s.find_by_order(x);
//------------Defines part-------------
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define int long long int
#define yes cout << "YES\n";
#define no cout << "NO\n";

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))

#define pb(n) push_back(n)
#define ff first
#define ss second
#define ve(x) vector<int> v(x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define in(v)            \
    for (auto &item : v) \
        cin >> item;
#define in2D(v)           \
    for (auto &D : v)     \
        for (auto &u : D) \
            cin >> u;
#define inp(v)           \
    for (auto &item : v) \
        cin >> item.ff >> item.ss;
#define rep(i, n) for (int i = 0; i < n; i++)
#define sp(n) cout << fixed << setprecision(n)
#define debug(x) cout << #x << '=' << ' ' << x << endl;
const int mod = 1e9 + 7;
const int inf = 1e18;
// Big O mod Template
int bigmod(int base, int power)
{
    int res = 1;
    while (power != 0)
    {
        if (power % 2 == 0)
        {
            base *= base;
            power /= 2;
        }
        else
        {
            res *= base;
            power--;
        }
    }
    return res;
}
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
//--------------------------------------------------------------------------------------
//						Code start here
//-------------------------------------------------------------------------------------
const int N = 2e5 + 10;
int spf[N];
void spf_find()
{
    for (int i = 1; i <= N; i++)
    {
        spf[i] = i;
        if (i % 2 == 0)
        {
            spf[i] = 2;
        }
    }
    for (int i = 3; i * i <= N; i += 2)
    {
        for (int j = 2 * i; j <= N; j += i)
        {
            spf[j] = min(spf[j], i);
        }
    }
}
void solve()
{
    int n, one = 0, square = 0;
    cin >> n;
    vector<int> v(n);
    in(v);
    map<int, int> mp,mm;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
        int x = sqrt(v[i]);
        if (x * x == v[i])
            square++;
        s.insert(v[i]);
    }
    int res = (n - mp[0]) * mp[0] ;
    //debug(res);
    for (auto u : v)
    {
        if(u<1)continue;
        int mul = 1;
        int spf_value = spf[u], cnt = 0, value = u;
       
        while (spf[value] > 1)
        {
            cnt++;
            spf_value = spf[value];
            value = value / spf[value];
            if (spf_value != spf[value])
            {
                
                if (cnt % 2 == 1)
                {
                    
                    mul *= spf_value;
                }

                cnt = 0;

               
            }

            
        }
       
           res += mm[mul];
           mm[mul]++;
        
        //cout << u<<" "<<mul<<endl;
        // if (cnt % 2 == 1)
        // {
        //     mul *= spf_value;
            
        // }
        // if(mul==1){
            
        //     int x = mp[u];
        //     x = (x*(x-1))/2;
        //     res += x;

        // }
        // else{
           
        //    if(u == mul){
        //      ;
        //    }else
        //     res += mp[mul]*mp[u];
           
        // }
       
    }
    cout<<res<<endl;
}
int32_t main()
{
    fast int t = 1;
    spf_find();
    // cin>>t;
    while (t--)
    {
        solve();
    }
}