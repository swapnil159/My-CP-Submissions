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
	ll n=0,u=0;
	cin>>n>>u;
	ll x[n]={0};
	for(ll a=0;a<n;a++)
	{
	    cin>>x[a];
	}
	double ans=-1;
	for(ll a=0;a<n-2;a++)
	{
	    ll j=lb(x,x+n,x[a]+u)-x;
	    if(j>n-1 || x[j]!=x[a]+u)
	    {
	        j--;
	    }
	    if(j==a+1)
	    {
	        continue;
	    }
	    double r=((double)x[j]-(double)x[a+1])/((double)x[j]-(double)x[a]);
	    if(ans<r)
	    {
	        ans=r;
	    }
	}
	double j=-1;
	if(ans!=j)
	{
	    cout<<fixed<<setprecision(10)<<ans<<endl;
	}
	else
	{
	    cout<<"-1\n";
	}
	return 0;
}
