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
        ll n;
        cin>>n;
        ll x[n],y[n];
        for(ll a=0;a<n;a++)
            cin>>x[a]>>y[a];
        ll dp[n][3];
        for(ll a=0;a<n;a++)
        {
            dp[a][0]=inf;
            dp[a][1]=inf;
            dp[a][2]=inf;
            if(a==0)
            {
                dp[a][0]=0;
                dp[a][1]=y[a];
                dp[a][2]=2*y[a];
            }
            else
            {
                for(ll b=0;b<3;b++)
                {
                    for(ll c=0;c<3;c++)
                    {
                        if(x[a]+b!=x[a-1]+c)
                        {
                            dp[a][b]=min(dp[a][b],dp[a-1][c]+y[a]*b);
                        }
                    }
                }
            }
        }
        cout<<min({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;
    }
	return 0;
}
