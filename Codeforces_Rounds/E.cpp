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
struct vertex
{
    ll val;
    ll vis=0;
    vc<ll> adj;
    set<ll> s;
    map<ll,ll> m;
};
ll ans=0;
void dfs(vertex x[],ll sor)
{
    x[sor].vis=1;
    x[sor].s.insert(x[sor].val);
    x[sor].m[x[sor].val]++;
    for(auto it=x[sor].s.begin();it!=x[sor].s.end();it++)
    {
        ll p=((*it)*(x[sor].m[(*it)]))%mod;
        ans=(ans+p)%mod;
    }
    for(auto y:x[sor].adj)
    {
        if(!x[y].vis)
        {
            for(auto it=x[sor].s.begin();it!=x[sor].s.end();it++)
            {
                x[y].s.insert(__gcd((*it),x[y].val));
                x[y].m[__gcd((*it),x[y].val)]+=x[sor].m[(*it)];
            }
            dfs(x,y);
        }
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
    vertex x[n];
    for(ll a=0;a<n;a++)
        cin>>x[a].val;
    for(ll a=1;a<n;a++)
    {
        ll u,v;
        cin>>u>>v;
        u--,v--;
        x[u].adj.pb(v);
        x[v].adj.pb(u);
    }
    dfs(x,0);
    cout<<ans<<endl;
	return 0;
}
