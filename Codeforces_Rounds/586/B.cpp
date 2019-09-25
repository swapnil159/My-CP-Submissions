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
    ll n;
	cin>>n;
	ll x[n][n];
	ll g=0;
	for(ll a=0;a<n;a++)
	{
		for(ll b=0;b<n;b++)
		{
			cin>>x[a][b];
			if(!a)
				g=__gcd(g,x[a][b]);
		}
	}
	ll ans[n];
	for(ll a=0;a<n;a++)
	{
		if(a)
			ans[a]=x[0][a]/g;
		else
			ans[a]=g;
	}
	ll po=1;
	if(ans[1]*ans[2]!=x[1][2])
		po=(ll)sqrt((x[1][2]/(ans[1]*ans[2])));
	for(ll a=0;a<n;a++)
	{
		if(a)
			cout<<po*ans[a]<<" ";
		else
			cout<<ans[a]/po<<" ";
	}
	return 0;
}
