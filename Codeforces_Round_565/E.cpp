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
set<ll> s;
struct vertex
{
    vc<ll> adj;
    ll vis=0;
    ll dist=0;
};
void dfs(vertex x[],ll sor)
{
    x[sor].vis=1;
    if(x[sor].dist&1)
        s.insert(sor);
    for(auto y:x[sor].adj)
    {
        if(!x[y].vis)
        {
            x[y].dist=(x[sor].dist^1);
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
    T
    {
        s.clear();
        ll n,m;
        cin>>n>>m;
        vertex x[n];
        for(ll a=0;a<m;a++)
        {
            ll i,j;
            cin>>i>>j;
            i--,j--;
            x[i].adj.pb(j);
            x[j].adj.pb(i);
        }
        dfs(x,0);
        bool flag=false;
        ll po=s.size();
        ll ans=po;
        if(s.size()>n/2)
            flag=true,ans=n-po;
        cout<<ans<<endl;
        for(ll a=0;a<n;a++)
        {
            if(flag)
            {
                if(s.find(a)==s.end())
                    cout<<a+1<<" ";
            }
            else
            {
                if(s.find(a)!=s.end())
                    cout<<a+1<<" ";
            }
        }
        cout<<endl;
    }
	return 0;
}
