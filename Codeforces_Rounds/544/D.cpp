/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
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
    ll n;
    cin>>n;
    map<pll,ll> m;
    ll x[n];
    for(ll a=0;a<n;a++)
        cin>>x[a];
    ll y[n];
    for(ll b=0;b<n;b++)
        cin>>y[b];
    ll poi=0;
    for(ll a=0;a<n;a++)
    {
        ll b=x[a];
        ll c=y[a];
        if(c==0 and b==0)
        {
            poi++;
            continue;
        }
        if(b==0)
            continue;
        if(c==0)
        {
            m[mp(0*1LL,0*1LL)]++;
            continue;
        }
        ll g=__gcd(b,c);
        b/=g;c/=g;
        m[mp(b,c)]++;
    }
    ll ans=0;
    for(auto it=m.begin();it!=m.end();it++)
    {
        ll po=(*it).sec;
        ans=max(ans,po);
    }
    cout<<ans+poi<<endl;
	return 0;
}
