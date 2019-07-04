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
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    ll x[n];
    for(ll a=0;a<n;a++)
        cin>>x[a];
    ll dp[4][n+1];
    dp[0][0]=0,dp[1][0]=0,dp[2][0]=0,dp[3][0]=0;
    for(ll a=1;a<=n;a++)
    {
        dp[0][a]=dp[0][a-1]+(ll)(x[a-1]==1);
        dp[1][a]=max(dp[1][a-1],dp[0][a-1])+(ll)(x[a-1]==2);
        dp[2][a]=max(dp[2][a-1],dp[1][a-1])+(ll)(x[a-1]==1);
        dp[3][a]=max(dp[3][a-1],dp[2][a-1])+(ll)(x[a-1]==2);
    }
    cout<<max({dp[0][n],dp[1][n],dp[2][n],dp[3][n]})<<endl;
	return 0;
}
