/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long  int ll;
using ld = long double;
const ll mod = 1000000007;
const ll rk = 256;
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
    ll l;
    ll r;
    ll left=0;
    ll right=0;
    ll lind;
    ll rind;
    ll llind;
    ll rrind;
};
 
bool comp(vertex a,vertex b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
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
    vertex x[n];
    rep(a,0,n)
    {
        cin>>x[a].l>>x[a].r;
        //cout<<x[a].l<<" "<<x[a].r<<endl;
    }
    sort(x,x+n,comp);
    ll k=0,low=0,high=mod;
    rep(a,0,n)
    {
        //cout<<x[a].l<<" "<<x[a].r<<endl;
        x[a].left=max(0*1LL,high-low);
        if(x[a].left==mod)
            x[a].left=0;
        x[a].lind=low;
        x[a].rind=high;
        //cout<<low<<" "<<high<<endl;
        low=max(low,x[a].l);
        high=min(high,x[a].r);
    }
    low=0,high=mod;
    rep(a,n,0)
    {
        //cout<<x[a].l<<" "<<x[a].r<<endl;
        x[a].right=max(0*1LL,high-low);
        if(x[a].right==mod)
            x[a].right=0;
        x[a].llind=low;
        x[a].rrind=high;
        low=max(low,x[a].l);
        high=min(high,x[a].r);
    }
    ll ans=max(x[0].right,x[n-1].left);
    rep(a,1,n-1)
    {
        low=max(x[a].lind,x[a].llind);
        high=min(x[a].rind,x[a].rrind);
        ans=max(ans,high-low);
    }
    cout<<ans<<endl;
	return 0;
}
