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
    vc<pll> adj;
    ll dist=0;
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n,m;
    cin>>n>>m;
    vertex x[n];
    for(ll a=0;a<m;a++)
    {
        ll i,j,w;
        cin>>i>>j>>w;
        i--,j--;
        w*=2;
        x[i].adj.pb({j,w});
        x[j].adj.pb({i,w});
    }
    set<pll> s;
    for(ll a=0;a<n;a++){
        cin>>x[a].dist;
        s.insert({x[a].dist,a});
    }
    
    while(!s.empty())
    {
        pll temp=*s.begin();
        s.erase(s.begin());
        ll sor=temp.sec;
        for(auto y:x[sor].adj)
        {
            if(x[y.fs].dist>x[sor].dist+y.sec)
            {
                if(s.find({x[y.fs].dist,y.fs})!=s.end())
                    s.erase(s.find({x[y.fs].dist,y.fs}));
                x[y.fs].dist=x[sor].dist+y.sec;
                s.insert({x[y.fs].dist,y.fs});
            }
        }
    }
    for(ll a=0;a<n;a++)
        cout<<x[a].dist<<" ";
	return 0;
}
