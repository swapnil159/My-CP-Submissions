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
vc<ll> solve(string s)
{
    ll n=s.length();
    ll cnt=1;
    vc<ll> ans;
    for(ll a=1;a<n;a++)
    {
        if(s[a]==s[a-1])
            cnt++;
        else
        {
            ans.pb(cnt);
            cnt=1;
        }
        
    }
    ans.pb(cnt);
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n,M;
    cin>>n>>M;
    ll x[n],dp[n];
    pq<ll> q;
    pq<ll,vc<ll>,greater<ll>> q1; 
    for(ll a=0;a<n;a++)
    {
        cin>>x[a];
        dp[a]=x[a];
        if(a)
            dp[a]+=dp[a-1];
    }
    ll y[101];
    for(ll a=0;a<=100;a++)
        y[a]=0;
    for(ll a=0;a<n;a++)
    {
        if(dp[a]<=M)
        {
            cout<<0<<" ";
            y[x[a]]++;
            continue;
        }
        ll ans=0,diff=dp[a]-M;
        for(ll b=100;b>0 and diff>0;b--)
        {
            if(y[b]==0)
                continue;
            ll g=diff/b;
            if(diff%b)
                g++;
            ll temp=min(g,y[b]);
            ans+=temp;
            diff-=temp*b;
        }
        cout<<ans<<" ";
        y[x[a]]++;
    }
    cout<<endl;
	return 0;
}
