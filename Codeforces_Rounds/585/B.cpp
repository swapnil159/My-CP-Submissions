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
	vc<ll> v;
	ll dp[n][2];
	ll ans=0;
	for(ll a=0;a<n;a++)
	{
		ll b;
		cin>>b;
		dp[a][0]=0;
		dp[a][1]=0;
		if(a==0)
		{
			if(b<0)
				dp[a][0]=1;
			else
				dp[a][1]=1;
		}
		else
		{
			if(b<0)
			{
				dp[a][0]=dp[a-1][1]+1;
				dp[a][1]=dp[a-1][0];
			}
			else
			{
				dp[a][0]=dp[a-1][0];
				dp[a][1]=dp[a-1][1]+1;
			}
		}
		ans+=dp[a][0];
	}
	cout<<ans<<" "<<(n*(n+1))/2-ans<<endl;
	return 0;
}
