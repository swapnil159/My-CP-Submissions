/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
using ll = long long;
using ld = long double;
const ll mod = 998244353;
const ll inf = 1e18;
#define rk 256
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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
ll fast_exp(ll base, ll exp1) {
    base%=mod;
    ll res=1;
    while(exp1>0) {
       if(exp1&1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp1/=2;
    }
    return res%mod;
} 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    if(n<m)
    {
        reverse(all(s1));
        while(n<m)
        {
            n++;
            s1+="0";
        }
        reverse(all(s1));
    }
    ll dp[n]={0};
    for(ll a=n-1;a>=0;a--)
    {
        if(s1[a]=='1')
        {
            dp[a]=fast_exp(2,n-1-a);
            if(a<n-1)
                dp[a]+=dp[a+1];
        }
        else if(a<n-1)
            dp[a]=dp[a+1];
        dp[a]%=mod;
    }
    reverse(dp,dp+n);
    ll ans=0;
    for(ll a=0;a<m;a++)
    {
        if(s2[a]=='1')
        {
            //cout<<m-1-a<<" "<<dp[m-1-a]<<endl;
            ans=(ans+dp[m-1-a])%mod;
        }
    }
    cout<<ans<<endl;
	return 0;
}
