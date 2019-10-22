/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    ll dp[(1<<m)];
    for(ll a=0;a<(1<<m);a++){
        dp[a]=mod;
        if(__builtin_popcount(a)<2)
            dp[a]=0;
    }
    ll cnt[m][m];
    for(ll a=0;a<m;a++)
    {
        for(ll b=0;b<m;b++)
        {
            cnt[a][b]=0;
        }
    }
    for(ll a=1;a<n;a++)
    {
        ll p=s[a]-'a',q=s[a-1]-'a';
        cnt[p][q]++;
        cnt[q][p]++;
    }
    for(ll mask=0;mask<(1<<m);mask++)
    {
        for(ll a=0;a<m;a++)
        {
            if(!(mask&(1<<a)))
            {
                ll pos=__builtin_popcount(mask);
                ll tot=0;
                for(ll b=0;b<m;b++)
                {
                    if(b==a)
                        continue;
                    if((mask&(1<<b)))
                        tot+=pos*cnt[a][b];
                    else
                        tot-=pos*cnt[a][b];
                }
                dp[(mask^(1<<a))]=min(dp[mask]+tot,dp[(mask^(1<<a))]);
            }
        }
    }
    cout<<dp[(1<<m)-1]<<endl;
	return 0;
}
