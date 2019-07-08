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
bool func(ll a,ll b,ll x[])
{
    if(x[b]==a)
    {
        return false;
    }
    ll c=x[b];
    if(a==x[c])
    {
        //cout<<a<<" "<<b<<" "<<c<<endl;
        return true;
    }
    else
    {
        return false;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
	ll n=0;
	cin>>n;
	ll x[n]={0};
	for(ll a=0;a<n;a++)
	{
	    cin>>x[a];
	    x[a]--;
	}
	bool flag=false;
	for(ll a=0;a<n && !flag;a++)
	{
	    ll b=x[a];
	    flag=func(a,b,x);
	}
	if(flag)
	{
	    cout<<"YES\n";
	}
	else
	{
	    cout<<"NO\n";
	}
	return 0;
}
