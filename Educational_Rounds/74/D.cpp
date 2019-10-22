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
        string s;
        cin>>s;
        reverse(all(s));
        ll a=-1,b=-1,ans=0,tota=0,totb=0;
        ll dp[n][2];
        for(ll a=0;a<n;a++)
        {
            dp[a][0]=0;
            dp[a][1]=0;
        }
        for(ll c=0;c<n;c++)
        {
            if(s[c]=='A')
            {
                if(tota==0)
                {
                    tota++;
                    a=c;
                    dp[c][0]=tota;
                    dp[c][1]=totb;
                    continue;
                }
                ans+=tota;
                ans+=(max(0*1LL,dp[a][1]-1));
                if(dp[a][1] and dp[a][1]!=totb)
                {
                    ans++;
                }
                tota++;
                a=c;
                dp[c][0]=tota;
                dp[c][1]=totb;
            }
            else
            {
                if(totb==0)
                {
                    totb++;
                    b=c;
                    dp[c][0]=tota;
                    dp[c][1]=totb;
                    continue;
                }
                ans+=totb;
                ans+=max(0*1LL,dp[b][0]-1);
                if(dp[b][0] and dp[b][0]!=tota)
                {
                    ans++;
                }
                totb++;
                b=c;
                dp[c][0]=tota;
                dp[c][1]=totb;
            }
        }
        cout<<ans<<endl;
 
	return 0;
}
