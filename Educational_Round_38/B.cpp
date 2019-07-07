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
 
int main() {
    ios_base::sync_with_stdio(false);
	ll n=0;
	cin>>n;
	ll x[n]={0};
	for(ll a=0;a<n;a++)
	{
	    cin>>x[a];
	}
	sort(x,x+n);
	ll ans1=0,ans2=0,ans=0;
	for(ll a=0;a<n;a++)
	{
	    ans1=llabs(x[a]-1);
	    ans2=llabs(1000000-x[a]);
	    ans=max(ans,min(ans1,ans2));
	}
	cout<<ans<<endl;
	return 0;
}
