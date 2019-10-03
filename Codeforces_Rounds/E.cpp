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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
	ll n,m;
	cin>>n>>m;
	vc<ll> v(n+2,0);
	ll x[m];
	for(ll a=0;a<m;a++)
	{
		cin>>x[a];
	}
	for(ll a=0;a<m-1;a++)
	{
		ll l=x[a],r=x[a+1];
		if(l>r)
			swap(l,r);
		if(l==r)
			continue;
		v[1]+=(r-l);
		v[l]-=(r-l);
		v[l]+=(r-1);
		v[l+1]-=(r-1);
		v[l+1]+=(r-l-1);
		v[r]-=(r-l-1);
		v[r]+=(l);
		v[r+1]-=(l);
		v[r+1]+=(r-l);
		v[n+1]-=(r-l);
	}
	for(ll a=1;a<=n;a++)
	{
		v[a]+=v[a-1];
		cout<<v[a]<<" ";
	}
	cout<<endl;
	return 0;
}
