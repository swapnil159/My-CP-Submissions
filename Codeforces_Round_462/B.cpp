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
	ll k=0;
	cin>>k;
	if(k>36)
	{
	    cout<<"-1\n";
	}
	else
	{
	    for(ll a=0;a<(k/2);a++)
	    {
	        cout<<"8";
	    }
	    for(ll a=0;a<(k%2);a++)
	    {
	        cout<<"6";
	    }
	    cout<<endl;
	}
	return 0;
}
