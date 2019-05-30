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
    ll n,k;
    cin>>n>>k;
    ll x[n];
    for(ll a=0;a<n;a++)
        cin>>x[a];
    sort(x,x+n);
    ll ind[n]={0};
    ll strt=n-1;
    for(ll a=n-1;a>=0;a--)
    {
        while(strt and x[a]-x[strt]<=5)
            strt--;
        ind[a]=strt+1;
        if(x[a]-x[strt]<=5)
            ind[a]=strt;
    }
    ll dp[k][n];
    for(ll a=0;a<k;a++)
    {
        for(ll b=0;b<n;b++)
        {
            dp[a][b]=0;
        }
    }
    for(ll a=0;a<n;a++)
    {
        dp[0][a]=a-ind[a]+1;
        if(a)
            dp[0][a]=max(dp[0][a-1],dp[0][a]);
    }
    for(ll a=1;a<k;a++)
    {
        for(ll b=0;b<a;b++)
            dp[a][b]=0;
        for(ll b=a;b<n;b++)
        {
            ll c=ind[b];
            if(c<a)
            {
                dp[a][b]=dp[a][b-1];
            }
            else
            {
                dp[a][b]=max(dp[a-1][c-1]+b-ind[b]+1,dp[a][b-1]);
            }
        }
    }
    ll ans=0;
    for(ll a=0;a<k;a++)
    {
        for(ll b=0;b<n;b++)
        {
            ans=max(ans,dp[a][b]);
        }
    }
    cout<<ans<<endl;
	return 0;
}
