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
	ll n=0,m=0;
	cin>>n>>m;
	string s[n];
	for(ll a=0;a<n;a++)
	{
	    cin>>s[a];
	}
	vc<ll> v[m];
	for(ll a=0;a<n;a++)
	{
	    for(ll b=0;b<m;b++)
	    {
	        if(s[a][b]=='#')
	        {
	            v[b].pb(a);
	        }
	    }
	}
	bool flag=false;
	for(ll a=0;a<m && !flag;a++)
	{
	    if(v[a].size()>0)
	    {
	        ll j=v[a][0];
	        for(ll k=1;k<v[a].size() && !flag;k++)
	        {
	            ll p=v[a][k];
	            for(ll c=0;c<m;c++)
	            {
	                if(s[j][c]!=s[p][c])
	                {
	                    flag=true;
	                    break;
	                }
	            }
	        }
	    }
	}
	if(flag)
	{
	    cout<<"No\n";
	}
	else
	{
	    cout<<"Yes\n";
	}
	return 0;
}
