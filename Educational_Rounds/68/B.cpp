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
    T
	{
		ll n,m;
		cin>>n>>m;
		string s[n];
		ll row[n]={0},col[m]={0};
		for(ll a=0;a<n;a++)
		{
			cin>>s[a];
			for(ll b=0;b<m;b++)
			{
				if(s[a][b]=='*')
					row[a]++,col[b]++;
			}
		}
		ll ans=n*m;
		for(ll a=0;a<n;a++)
		{
			for(ll b=0;b<m;b++)
			{
				ll p=(n-row[a])+(m-col[b]);
				if(s[a][b]=='.')
					p--;
				ans=min(ans,p);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
