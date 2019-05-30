/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
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
    string s;
    cin>>s;
    vc<char> v;
    v.pb(s[0]);
    char last=s[0];
    for(ll a=1;a<s.length();a++)
    {
        if(last!=s[a])
        {
            last=s[a];
            v.pb(last);
        }
    }
    n=v.size();
    ll dp[n][n];
    for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<n;b++)
        {
            dp[a][b]=0;
        }
    }
    for(ll a=0;a<n;a++)
        dp[a][a]=1;
    for(ll gap=1;gap<n;gap++)
    {
        for(ll j=gap;j<n;j++)
        {
            ll i=j-gap;
            ll k=mod;
            for(ll c=i;c<j;c++)
            {
                if(v[c]==v[j])
                {
                    k=min(k,dp[i][c]+dp[c+1][j-1]);
                }
                else
                {
                    k=min(k,dp[i][c]+dp[c+1][j]);
                }
            }
            dp[i][j]=k;
        }
    }
    cout<<dp[0][n-1]<<endl;
	return 0;
}
