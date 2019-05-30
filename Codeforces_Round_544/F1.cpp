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

ll comp=1,tim=0;
struct vertex
{
    ll parent=-1;
    ll deg=0;
    ll size=1;
};
ll find(struct vertex x[],ll sor)
{
    if(x[sor].parent==-1)
        return sor;
    x[sor].parent=find(x,x[sor].parent);
    return x[sor].parent;
}
void join(struct vertex x[],ll u,ll v)
{
    ll uset=find(x,u);
    ll vset=find(x,v);
    if(x[uset].size>=x[vset].size)
    {
        x[vset].parent=uset;
        x[uset].size+=x[vset].size;
    }
    else
    {
        x[uset].parent=vset;
        x[vset].size+=x[uset].size;
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
    struct vertex x[n];
    vc<pll> v;
    for(ll a=0;a<m;a++)
    {
        ll b,c;
        cin>>b>>c;
        b--;c--;
        v.pb(mp(b,c));
        x[b].deg++;
        x[c].deg++;
    }
    ll sor=0,lo=0;
    for(ll a=0;a<n;a++)
    {
        if(lo<x[a].deg)
        {
            lo=x[a].deg;
            sor=a;
        }
    }
    vc<pll> ans;
    for(ll a=0;a<m;a++)
    {
        if(v[a].fs==sor or v[a].sec==sor)
        {
            ans.pb(v[a]);
            join(x,v[a].fs,v[a].sec);
        }
    }
    for(ll a=0;a<m;a++)
    {
        if(find(x,v[a].fs)!=find(x,v[a].sec))
        {
            ans.pb(v[a]);
            join(x,v[a].fs,v[a].sec);
        }
    }
    for(auto y:ans)
        cout<<y.fs+1<<" "<<y.sec+1<<endl;
	return 0;
}
