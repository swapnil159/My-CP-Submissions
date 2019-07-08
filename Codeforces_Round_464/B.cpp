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
	ll n=0,k=0;
	cin>>n>>k;
	ll x[k]={0};
	ll box=0,ham=0;
	for(ll a=0;a<k;a++)
	{
	    cin>>x[a];
	    if(a)
	    {
	        if((n/x[a])*x[a]>ham*x[box-1])
	        {
	            ham=(n/x[a]);
	            box=a+1;
	        }
	    }
	    else
	    {
	        box=a+1;
	        ham=(n/x[a]);
	    }
	}
	cout<<box<<" "<<ham<<endl;
	return 0;
}
