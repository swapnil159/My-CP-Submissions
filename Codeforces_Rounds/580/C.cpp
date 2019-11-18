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
	if(n%2==0)
	{
		cout<<"NO\n";
		exit(0);
	}
	cout<<"YES\n";
	vc<ll> v,v1;
	ll smalle=2*n-2,bige=2*n,smallo=3,bigo=5;
	for(ll a=1;a<n;a++)
	{
		if(a&1)
		{
			if(a<=n/2)
			{
				v.pb(smalle);
				v1.pb(bige);
			}
			else
			{
				v1.pb(smalle);
				v.pb(bige);
			}
			smalle-=4;
			bige-=4;
		}
		else
		{
			if(a<=n/2)
			{
				v.pb(smallo);
				v1.pb(bigo);
			}
			else
			{
				v1.pb(smallo);
				v.pb(bigo);
			}
			smallo+=4;
			bigo+=4;
		}
	}
	cout<<1<<" ";
	for(auto y:v)
		cout<<y<<" ";
	cout<<2<<" ";
	reverse(all(v1));
	for(auto y:v1)
		cout<<y<<" ";
	return 0;
}
