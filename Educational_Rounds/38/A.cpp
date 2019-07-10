
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
	string s;
	cin>>s;
	ll pos=0;
	cout<<s[0];
	for(ll a=1;a<n;a++)
	{
	    if((s[a]=='a' || s[a]=='e'|| s[a]=='i'|| s[a]=='o'|| s[a]=='u'|| s[a]=='y') &&( s[pos]=='a'|| s[pos]=='e' || s[pos]=='i'|| s[pos]=='o' || s[pos]=='u' || s[pos]=='y'))
	    {
	        ll b=pos;
	        pos=b;
	    }
	    else
	    {
	        cout<<s[a];
	        pos=a;
	    }
	}
	return 0;
}
