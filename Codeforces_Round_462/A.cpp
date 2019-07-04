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
	ll n=0,m=0;
	cin>>n>>m;
	ll x[n]={0},y[m]={0};
	for(ll a=0;a<n;a++)
	{
	    cin>>x[a];
	}
	for(ll a=0;a<m;a++)
	{
	    cin>>y[a];
	}
	ll prod[n][m],maxi=0,pos=0;
	for(ll a=0;a<n;a++)
	{
	    for(ll b=0;b<m;b++)
	    {
	        prod[a][b]=x[a]*y[b];
	        if(a==0 && b==0)
	        {
	            maxi=prod[a][b];
	        }
	        else if(prod[a][b]>maxi)
	        {
	            maxi=prod[a][b];
	            pos=a;
	        }
	    }
	}
	bool flag=false;
	maxi=0;
	for(ll a=0;a<n;a++)
	{
	    if(a==pos)
	    {
	        continue;
	    }
	    for(ll b=0;b<m;b++)
	    {
	        if(!flag)
	        {
	            maxi=prod[a][b];
	            flag=true;
	        }
	        else if(prod[a][b]>maxi)
	        {
	            maxi=prod[a][b];
	        }
	    }
	}
	cout<<maxi<<endl;
	return 0;
}
