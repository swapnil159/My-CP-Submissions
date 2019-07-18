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
    ll x[n],y[n];
    for(ll a=0;a<n;a++)
        cin>>x[a];
    for(ll b=0;b<n;b++)
        cin>>y[b];
    ll dp[n][2];
    for(ll a=0;a<n;a++)
    {
        dp[a][0]=0;
        dp[a][1]=0;
    }
    dp[0][0]=x[0],dp[0][1]=y[0];
    for(ll a=1;a<n;a++)
    {
        ll p=x[a]+dp[a-1][1];
        ll p1=y[a]+dp[a-1][0];
        if(a>1)
        {
            p=max(p,max(dp[a-2][0],dp[a-2][1])+x[a]);
            p1=max(p1,max(dp[a-2][0],dp[a-2][1])+y[a]);
        }
        dp[a][0]=p;
        dp[a][1]=p1;
    }
    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
	return 0;
}
