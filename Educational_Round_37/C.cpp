/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define inf 100000000000000000
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
#define all(v) v.begin(),v.end()
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
/*ll ncr[5001][5001];
void coeff()
{
    for(ll a=0;a<5001;a++)
    {
        for(ll b=0;b<5001;b++)
        {
            ncr[a][b]=0;
        }
        ncr[a][0]=1;
    }
    for(ll a=1;a<5001;a++)
    {
        for(ll b=1;b<=a;b++)
        {
            ncr[a][b]=(ncr[a-1][b]+ncr[a-1][b-1])%mod;
        }
    }
}*/
ll fast_exp(ll base, ll exp1) {
    ll res=1;
    while(exp1>0) {
       if(exp1&1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp1/=2;
    }
    return res%mod;
} 
ll pr[1000001]={0};
void isprime()
{
    pr[0]=1;
    pr[1]=1;
    for(ll a=2;a<1000001;a++)
    {
        if(!pr[a])
        {
            for(ll b=a*2;b<1000001;b+=a)
            {
                pr[b]=1;
            }
        }
    }
}
ll comp=1,tim=0;
struct vertex
{
    vc<ll> adj;
    ll vis=0;
    ll parent=-1;
    ll dist=0;
    ll component=0;
    ll in=0;
    ll out=0;
    ll low=0;
    ll child=0;
    ll indeg=0;
    ll outdeg=0;
    bool AP=false;
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	ll n;
	cin>>n;
	vc<pll> v;
	for(ll a=0;a<n;a++)
	{
	    ll b;
	    cin>>b;
	    v.pb(mp(b,a));
	}
	string s;
	cin>>s;
	ll comp[n]={0};
	comp[n-1]=1;
	ll last=0;
	for(ll a=n-2;a>=0;a--)
	{
	    if(s[a]=='1')
	    {
	        comp[a]=comp[a+1];
	    }
	    else
	    {
	        comp[a]=comp[a+1]+1;
	    }
	}
	sort(all(v));
	bool k=true;
	for(ll a=0;a<n;a++)
	{
	    if(comp[a]!=comp[v[a].sec])
	    {
	        k=false;
	    }
	}
	if(k)
	    cout<<"YES\n";
	else
	    cout<<"NO\n";
	return 0;
}
