/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#pragma GCC optimize ("-O3")
#define mod 998244353
#define inf 1000000000000000000
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
ll ans=0;
ll solve(vc<ll> &v)
{
    ll n=v.size();
    ll len[11]={0};
    for(ll a=0;a<n;a++)
    {
        ll p=v[a],le=0;
        while(p)
        {
            ll k=p%10;
            for(ll b=0;b<11;b++)
            {
                if(len[b]==0)
                    continue;
                ll po;
                if(b>le)
                {
                    po=(len[b]*fast_exp(10,2*le)*k)%mod;
                    ll po1=(len[b]*fast_exp(10,2*le+1)*k)%mod;
                    po=(po+po1)%mod;
                }
                else
                {
                    po=(2*len[b]*fast_exp(10,b+le)*k)%mod;
                }
                ans=(ans+po)%mod;
            }
            p/=10;
            le++;
        }
        len[le]++;
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    vc<ll> v(n);
    for(ll a=0;a<n;a++)
        cin>>v[a];
    solve(v);
    reverse(all(v));
    solve(v);
    for(ll a=0;a<n;a++)
    {
        ll cnt=0,p=v[a];
        while(p)
        {
            ll k=p%10;
            ans=(ans+fast_exp(10,cnt)*k)%mod;
            cnt++;
            ans=(ans+fast_exp(10,cnt)*k)%mod;
            p/=10;
            cnt++;
        }
    }
    cout<<ans<<endl;
	return 0;
}
