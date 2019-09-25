/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#pragma GCC optimize ("-O3")
#define mod 1000000007
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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n,k;
    cin>>n>>k;
    vc<pll> v;
    ll x[7]={0};
    vc<ll> ed[7];
    for(ll a=0;a<k;a++)
    {
        ll u,v;
        cin>>u>>v;
        u--,v--;
        ed[u].pb(v);
        ed[v].pb(u);
        x[u]++,x[v]++;
    }
    for(ll a=0;a<7;a++)
    {
        v.pb({x[a],a});
    }
    sort(all(v));
    ll ans=0;
    for(ll a=1;a<7;a++)
        ans+=v[a].fs;
    ans-=v[0].fs;
    ans/=2;
    ll po=ans+v[0].fs;
    for(ll a=0;a<7;a++)
    {
        for(ll b=a+1;b<7;b++)
        {
            ll p=0;
            for(auto y:ed[v[a].sec])
            {
                for(auto y1:ed[v[b].sec])
                {
                    if(y==y1)
                    {
                        p++;
                    }
                }
            }
            ans=max(ans,po-p);
        }
    }
    cout<<ans<<endl;
	return 0;
}
