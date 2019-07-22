/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#pragma GCC optimize ("-O3")
#define mod 998244353
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
ll fast_exp(ll base, ll exp1) {
    base%=mod;
    ll res=1;
    while(exp1>0) {
       if(exp1&1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp1/=2;
    }
    return res%mod;
} 
ll pr[2001]={0};
void isprime()
{
    pr[0]=1;
    pr[1]=1;
    for(ll a=2;a*a<=2001;a++)
    {
        if(!pr[a])
        {
            for(ll b=a*a;b<2001;b+=a)
            {
                pr[b]=1;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    ll adj[n][n];
    for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<n;b++)
        {
            adj[a][b]=0;
        }
    }
    for(ll a=0;a<n-1;a++)
    {
        adj[a][a+1]=1;
    }
    adj[0][n-1]=1;
    ll sum=n;
    ll curr=0;
    while(pr[sum])
    {
        adj[curr][curr+n/2+n%2]=1;
        curr++;
        sum++;
    }
    cout<<sum<<endl;
    for(ll a=0;a<n;a++)
    {
        for(ll b=a+1;b<n;b++)
        {
            if(adj[a][b]==1)
                cout<<a+1<<" "<<b+1<<endl;
        }
    }
	return 0;
}
