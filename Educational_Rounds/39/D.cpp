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
/*ll ncr[5001][5001];
void coeff()
{
    for(ll a=0;a<5001;a++)
    {
        for(ll b=0;b<5001;b++)
        {
            ncr[a][b]=0;
        }
        ncr[a][0]=1;
    }
    for(ll a=1;a<5001;a++)
    {
        for(ll b=1;b<=a;b++)
        {
            ncr[a][b]=(ncr[a-1][b]+ncr[a-1][b-1])%mod;
        }
    }
}*/
ll fast_exp(ll base, ll exp1) {
    ll res=1;
    while(exp1>0) {
       if(exp1&1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp1/=2;
    }
    return res%mod;
} 
ll pr[1000001]={0};
void isprime()
{
    pr[0]=1;
    pr[1]=1;
    for(ll a=2;a*a<=1000001;a++)
    {
        if(!pr[a])
        {
            for(ll b=a*a;b<1000001;b+=a)
            {
                pr[b]=1;
            }
        }
    }
}
ll comp=1,tim=0;
struct vertex
{
    vc<ll> adj;
    ll vis=0;
    ll parent=-1;
    ll dist=0;
    ll component=0;
    ll in=0;
    ll out=0;
    ll low=0;
    ll child=0;
    ll indeg=0;
    ll outdeg=0;
    bool AP=false;
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n,m,k;
    cin>>n>>m>>k;
    ll dp1[n][k+1];
    for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<k+1;b++)
        {
            dp1[a][b]=mod;
        }
    }
    ll tot[n]={0};
    for(ll a=0;a<n;a++)
    {
        string s;
        cin>>s;
        for(auto y:s)
            if(y=='1')
                tot[a]++;
        for(ll c=0;c<s.length();c++)
        {
            if(s[c]=='0')
                continue;
            ll cnt=0;
            for(ll b=c;b<s.length();b++)
            {
                if(s[b]=='0')
                    continue;
                cnt++;
                ll po=tot[a]-cnt;
                if(po>k)
                    continue;
                dp1[a][po]=min(dp1[a][po],b-c+1);
            }
        }
        dp1[a][0]=max(dp1[a][0],0*1LL);
        if(tot[a]<=k)
            dp1[a][tot[a]]=0;
    }
    /*for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<=k;b++)
        {
            cout<<dp1[a][b]<<" ";
        }
        cout<<endl;
    }*/
    ll dp[n][k+1];
    for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<k+1;b++)
        {
            dp[a][b]=mod;
        }
    }
    for(ll a=0;a<=k;a++){
        dp[0][a]=dp1[0][a];
    }
    for(ll a=1;a<n;a++)
    {
        for(ll b=0;b<=k;b++)
        {
            ll ko=mod;
            for(ll c=b;c>=0;c--)
            {
                ko=min(ko,dp[a-1][c]+dp1[a][b-c]);
            }
            dp[a][b]=ko;
        }
    }
    /*for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<=k;b++)
        {
            cout<<dp[a][b]<<" ";
        }
        cout<<endl;
    }*/
    ll ans=mod;
    for(ll a=0;a<=k;a++)
        ans=min(ans,dp[n-1][a]);
    cout<<ans<<endl;
	return 0;
}
