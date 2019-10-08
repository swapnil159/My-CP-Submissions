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
    T
    {
        ll n;
        cin>>n;
        ll x[n];
        ll st[n],fn[n];
        for(ll a=0;a<n;a++)
        {
            st[a]=-1;
            fn[a]=-1;
            cin>>x[a];
        }
        for(ll a=0;a<n;a++)
        {
            if(st[x[a]-1]==-1)
                st[x[a]-1]=a;
            fn[x[a]-1]=a;
        }
        sort(x,x+n);
        ll dp[n]={0};
        dp[0]=1;
        ll cnt=1;
        for(ll a=1;a<n;a++)
        {
            if(x[a]==x[a-1])
            {
                dp[a]=dp[a-1];
                continue;
            }
            cnt++;
            if(fn[x[a-1]-1]<st[x[a]-1])
                dp[a]=dp[a-1]+1;
            else
                dp[a]=1;
        }
        cout<<cnt-*max_element(dp,dp+n)<<endl;
    }
	return 0;
}
