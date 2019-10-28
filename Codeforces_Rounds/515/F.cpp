/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;
using ld = long double;
const ll mod = 998244353;
const ll inf = 1e18;
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
    ll dist=0;
    pll fir;
    pll seco;
    ll dp1=0;
    ll dp2=0;
};
bool comp(pll a,pll b)
{
    if(max(a.fs,a.sec)==max(b.fs,b.sec))
        if(a.sec!=b.sec)
            return a.sec<b.sec;
        else
            return a.fs>b.fs;
    return max(a.fs,a.sec)<max(b.fs,b.sec);
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    vc<pll> v(n);
    rep(a,0,n)
        cin>>v[a].fs>>v[a].sec;
    sort(all(v),comp);
    vc<vertex> x;
    vertex zero;
    zero.fir=mp(0*1LL,0*1LL);
    zero.seco=mp(0*1LL,0*1LL);
    x.pb(zero);
    for(ll a=0;a<n;)
    {
        ll b=a;
        vertex tt;
        while(b<n-1 and max(v[a].fs,v[a].sec)==max(v[b+1].fs,v[b+1].sec)){
            b++;
            tt.dist+=(llabs(v[b].fs-v[b-1].fs)+llabs(v[b].sec-v[b-1].sec));
        }
        tt.fir=v[a];
        tt.seco=v[b];
        x.pb(tt);
        a=b+1;
    }
    ll m=x.size();
    for(ll a=1;a<m;a++)
    {
        //cout<<x[a].fir.fs<<" "<<x[a].fir.sec<<endl;
        x[a].dp1=x[a-1].dp2+llabs(x[a-1].fir.fs-x[a].fir.fs)+llabs(x[a-1].fir.sec-x[a].fir.sec)+x[a].dist;
        x[a].dp1=min(x[a].dp1,x[a-1].dp1+llabs(x[a-1].seco.fs-x[a].fir.fs)+llabs(x[a-1].seco.sec-x[a].fir.sec)+x[a].dist);
        x[a].dp2=x[a-1].dp1+llabs(x[a-1].seco.fs-x[a].seco.fs)+llabs(x[a-1].seco.sec-x[a].seco.sec)+x[a].dist;
        x[a].dp2=min(x[a].dp2,x[a-1].dp2+llabs(x[a-1].fir.fs-x[a].seco.fs)+llabs(x[a-1].fir.sec-x[a].seco.sec)+x[a].dist);
       // cout<<x[a].dp1<<" "<<x[a].dp2<<endl;
    }
    cout<<min(x[m-1].dp1,x[m-1].dp2)<<endl;
	return 0;
}
