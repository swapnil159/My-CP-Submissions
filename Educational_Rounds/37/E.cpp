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
set<ll> ss;
struct vertex
{
    vc<ll> adj;
    ll vis=0;
    ll lvl=0;
    ll dist=0;
};
ll k=0;
void bfs(vertex x[],ll sor)
{
    x[sor].vis=1;
    queue<ll> q;
    q.push(sor);
    ss.erase(ss.find(sor));
    while(!q.empty())
    {
        ll temp=q.front();
        q.pop();
        k++;
        vector<ll> ver;
        for(auto y:x[temp].adj)
        {
            if(!x[y].vis)
            {
                ver.pb(y);
                ss.erase(ss.find(y));
            }
        }
        for(auto it=ss.begin();it!=ss.end();it++)
        {
            ll po=*it;
            x[po].vis=1;
            q.push(po);
        }
        ss.clear();
        for(auto y:ver)
            ss.insert(y);
    }
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
        ss.insert(a);
    for(ll a=0;a<m;a++)
    {
        ll u,v;
        cin>>u>>v;
        u--,v--;
        x[u].adj.pb(v);
        x[v].adj.pb(u);
    }
    vector<ll> ans;
    for(ll a=0;a<n;a++)
    {
        if(!x[a].vis)
        {
            k=0;
            bfs(x,a);
            ans.pb(k);
        }
    }
    sort(all(ans));
    cout<<ans.size()<<endl;
    for(auto y:ans)
        cout<<y<<" ";
    cout<<endl;
	return 0;
}
