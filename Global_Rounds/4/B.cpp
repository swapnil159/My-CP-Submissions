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
    ll dp[n]={0};
    ll cnt=0;
    for(ll a=0;a<n;a++)
    {
        if(s[a]=='v')
        {
            cnt++;
            if(a)
                dp[a]=dp[a-1];
        }
        else
        {
            dp[a]=max(cnt-1,0*1LL);
            if(a)
                dp[a]+=dp[a-1];
            cnt=0;
        }
    }
    cnt=0;
    ll ans=0,prev=0;
    for(ll a=n-1;a>=0;a--)
    {
        if(s[a]=='v')
        {
            cnt++;
        }
        else
        {
            prev+=max((cnt-1),0*1LL);
            ans+=dp[a]*prev;
            cnt=0;
        }
        
    }
    cout<<ans<<endl;
	return 0;
}
