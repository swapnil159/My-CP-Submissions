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
    string s;
    cin>>s;
    ll n=s.length();
 
    ll dp[(1<<20)]={0},f[(1<<20)]={0};
    for(ll a=0;a<n;a++)
    {
        ll temp=0;
        for(ll b=a;b<n;b++)
        {
            if((temp&(1<<(s[b]-'a'))))
                break;
            temp|=(1<<(s[b]-'a'));
            f[temp]=1;
        }
    }
    f[0]=1;
    for(ll a=0;a<(1<<20);a++)
        if(f[a])
            dp[a]=__builtin_popcount(a);
    for(ll a=0;a<20;a++)
    {
        for(ll mask=0;mask<(1<<20);mask++)
        {
            if((mask&(1<<a)))
                dp[mask]=max(dp[mask],dp[(mask^(1LL<<a))]);
        }
    }
    ll ans=0;
    for(ll a=0;a<(1<<20);a++)
    {
        if(f[a])
        {
            ans=max(ans,__builtin_popcount(a)+dp[(1<<20)-1-a]);
        }
    }
    cout<<ans<<endl;
	return 0;
}
