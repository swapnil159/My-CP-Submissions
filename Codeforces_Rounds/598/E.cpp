/* winners never quit and quitters never win.
      #swap                                 */
      
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize ("-O3")
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
const ll inf = 1000000000000000000;
const ll rk = 256;
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define all(v) v.begin(),v.end()
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
 
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    vc<pll> x(n);
    rep(a,0,n){
        cin>>x[a].fs;
        x[a].sec=a;
    }
    sort(all(x));
    ll p=n%3;
    ll dp[n][3];
    rep(a,0,n)
        rep(b,0,3)
            dp[a][b]=inf;
    rep(a,2,n)
    {
        rep(b,0,3)
        {
            if(a>=b+2 and (a-b-2==0 or a-b-2>2))
            {
                dp[a][b]=x[a].fs-x[a-b-2].fs;
                if(a>b+2 and a-b-3>=2){
                    ll po=min({dp[a-b-3][0],dp[a-b-3][1],dp[a-b-3][2]});
                    if(po!=inf)
                        dp[a][b]+=po;
                }
            }
        }
    }
    ll ans=min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    vc<ll> v(n);
    ll cnt=0,st=n;
    rep(a,n,0)
    {
        if(a>=st)
        {
            v[x[a].sec]=cnt;
            continue;
        }
        cnt++;
        ll p=min({dp[a][0],dp[a][1],dp[a][2]});
        //cout<<a<<" "<<p<<endl;
        if(dp[a][0]==p)
        {
            st=a-2;
        }
        else if(dp[a][1]==p)
        {
            st=a-3;
        }
        else
        {
            st=a-4;
        }
        v[x[a].sec]=cnt;
    }
    sort(all(x),[] (pll a,pll b) { return a.sec<b.sec; });
    cout<<ans<<" "<<cnt<<endl;
    rep(a,0,n)
        cout<<v[x[a].sec]<<" \n"[a==n-1];
	return 0;
}
