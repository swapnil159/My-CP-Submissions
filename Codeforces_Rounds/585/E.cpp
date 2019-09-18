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
	ll cnt[20][20];
	for(ll a=0;a<20;a++)
	{
		for(ll b=0;b<20;b++)
		{
			cnt[a][b]=0;
		}
	}
	vc<ll> col[20];
	ll n;
	cin>>n;
	for(ll a=0;a<n;a++)
	{
		ll p;
		cin>>p;
		col[p-1].pb(a);
	}
	for(ll a=0;a<20;a++)
	{
		for(ll b=0;b<20;b++)
		{
			ll po=0;
			if(a==b or col[a].size()==0 or col[b].size()==0)
				continue;
			for(auto y:col[a])
			{
				while(po<col[b].size() and col[b][po]<y)
					po++;
				cnt[a][b]+=po;
			}
		}
	}
	
	ll dp[(1<<21)];
	for(ll a=0;a<(1<<20);a++)
		dp[a]=inf;
	dp[0]=0;
	ll ans=0;
	for(ll mask=0;mask<(1<<20);mask++)
	{
		vc<ll> v;
		for(ll a=0;a<20;a++)
		{
			if((mask&(1<<a)))
				v.pb(a);
		}
		for(ll a=0;a<20;a++)
		{
			if(not (mask&(1<<a)))
			{
				ll sum=0;
				for(auto y:v)
					sum+=cnt[y][a];
				
				dp[mask+(1<<a)]=min(dp[mask+(1<<a)],dp[mask]+sum);
			}
		}
	}
	cout<<dp[(1<<20)-1]<<endl;
	return 0;
}
