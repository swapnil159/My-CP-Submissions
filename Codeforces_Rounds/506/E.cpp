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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
 
struct vertex
{
    vc<ll> adj;
    ll vis=0;
    ll parent=-1;
    ll dist=0;
    bool done=false;
};
vc<ll> eu;
void dfs(vertex x[],ll sor)
{
    x[sor].vis=1;
    for(auto y:x[sor].adj)
    {
        if(!x[y].vis)
        {
            x[y].parent=sor;
            x[y].dist=x[sor].dist+1;
            dfs(x,y);
        }
    }
    if(x[sor].dist>2)
        eu.pb(sor);
    else
        x[sor].done=true;
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
    rep(a,0,n-1)
    {
        ll u,v;
        cin>>u>>v;
        u--,v--;
        x[u].adj.pb(v);
        x[v].adj.pb(u);
    }
    dfs(x,0);
    ll ans=0;
    for(auto y:eu)
    {
        if(!x[y].done)
        {
            ans++;
            ll p=x[y].parent;
            x[p].done=true;
            for(auto y1:x[p].adj)
                x[y1].done=true;
        }
    }
    cout<<ans<<endl;
	return 0;
}
