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
ll adj[65][65];
struct vertex
{
	vc<ll> adj;
	ll k;
    ll vis=0;
	ll dist=0;
	ll parent=-1;
	ll count=0;
};
ll ans=-1;
 
void bfs(vertex x[],ll sor)
{
	queue<ll> q;
	q.push(sor);
	x[sor].vis=1;
	while(!q.empty())
	{
		ll temp=q.front();
		q.pop();
		x[temp].vis=1;
		for(auto a:x[temp].adj)
		{
				if(x[a].vis==0)
				{
					x[a].parent=temp;
					x[a].dist=x[temp].dist+1;
					q.push(a);
				}
				else if(a!=x[temp].parent)
				{
					if(ans==-1)
						ans=x[temp].dist+1+x[a].dist;
					else
						ans=min(ans,x[temp].dist+1+x[a].dist);
				}
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
    ll zero=0;
	vertex x[n];
	for(ll a=0;a<n;a++)
	{
		cin>>x[a].k;
        if(x[a].k==0)
            zero++;
	}
	if(n-zero>128)
	{
		cout<<3<<endl;
		exit(0);
	}
    vc<ll> v;
    for(ll a=0;a<n;a++)
    {
        if(x[a].k)
            v.pb(a);
    }
	for(ll a=0;a<v.size();a++)
	{
		for(ll b=a+1;b<v.size();b++)
		{
			if(x[v[a]].k&x[v[b]].k)
			{
				x[v[a]].adj.pb(v[b]);
				x[v[b]].adj.pb(v[a]);
			}
		}
	}
	for(ll a=0;a<v.size();a++)
	{
		for(ll b=0;b<v.size();b++)
		{
			x[v[b]].vis=0;
			x[v[b]].dist=0;
			x[v[b]].parent=-1;
		}
		bfs(x,v[a]);
	}
	cout<<ans<<endl;
	return 0;
}
