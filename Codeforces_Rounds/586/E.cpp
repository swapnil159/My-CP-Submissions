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
    vc<ll> adj;
    ll vis=0;
    ll parent=-1;
    ll weight=0;
    ll dp=0;
};
ll loop=0,path=0;
bool dfs(vertex x[],ll sor)
{
    x[sor].vis=1;
    bool isloop=false;
    x[sor].dp=x[sor].weight;
    for(auto y:x[sor].adj)
    {
        if(!x[y].vis)
        {
            x[y].parent=sor;
            isloop|=dfs(x,y);
            x[sor].dp=max(x[sor].dp,x[sor].weight+x[y].dp);
        }
        else if(y!=x[sor].parent)
            isloop=true;
    }
    if(isloop)
        loop+=x[sor].weight;
    else
        path=max(path,x[sor].dp);
    return isloop;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n,m;
    cin>>n>>m;
    vertex x[n];
    for(ll a=0;a<n;a++)
        cin>>x[a].weight;
    for(ll a=0;a<m;a++)
    {
        ll u,v;
        cin>>u>>v;
        u--,v--;
        x[u].adj.pb(v);
        x[v].adj.pb(u);
    }
    ll sor=0;
    cin>>sor;
    dfs(x,sor-1);
    cout<<path+loop<<endl;
	return 0;
}
