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
 
int main()
{
      ll n;
      cin>>n;
      ll dp[51]={0};
      for(ll a=1;a<=50;a++)
            dp[a]=2LL*dp[a-1]+(1LL<<(a-1));
      n--;
      ll ans=0;
      for(ll a=0;a<=50;a++)
      {
            if((n&(1LL<<a)))
                  ans+=(dp[a]+(1LL<<a));
      }
      cout<<ans<<endl;
      return 0;
}
