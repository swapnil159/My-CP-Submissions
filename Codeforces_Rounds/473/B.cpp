/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
long long fastexp(long long a,long long int n)
{
    int ans=1;
    a%=mod;
    while(n>0)
    {
        if(n&1)
            ans=(ans*a*1LL)%mod;
        n>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
void isprime(ll pr[])
{
    pr[0]=1;
    pr[1]=1;
    for(ll a=2;a<1000001;a++)
    {
        if(!pr[a])
        {
            for(ll b=2*a;b<1000001;b+=a)
            {
                pr[b]=1;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
	ll pr[1000001]={0};
	//isprime(pr);
	ll n=0,k=0,m=0;
	cin>>n>>k>>m;
	vc< pair<string,ll> > name;
	for(ll a=0;a<n;a++)
	{
	    string s;
	    cin>>s;
	    name.pb(mp(s,a));
	}
	ll cost[n]={0};
	for(ll a=0;a<n;a++)
	{
	    cin>>cost[a];
	}
	ll y[n]={0};
	ll group[k];
	for(ll a=0;a<k;a++)
	{
	    ll b=0;
	    cin>>b;
	    for(ll j=0;j<b;j++)
	    {
	        ll h=0;
	        cin>>h;
	        h--;
	        y[h]=a;
	        if(j)
	        {
	            group[a]=min(group[a],cost[h]);
	        }
	        else
	        {
	            group[a]=cost[h];
	        }
	    }
	}
	sort(name.begin(),name.end());
	ll v=0,ans=0;
	vc<string> gol;
	for(ll a=0;a<m;a++)
	{
	    string s;
	    cin>>s;
	    gol.pb(s);
	}
	sort(gol.begin(),gol.end());
	for(ll a=0;a<m;a++)
	{
	    ll i=0;
	    for(;v<n;v++)
	    {
	        if(gol[a]==name[v].fs)
	        {
	            i=name[v].sec;
	            i=y[i];
	            i=group[i];
	            break;
	        }
	    }
	    ans+=i;
	}
	cout<<ans<<endl;
	return 0;
}
