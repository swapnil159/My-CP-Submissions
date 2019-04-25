/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#pragma GCC optimize ("-O3")
#define mod 1000000007

ll solve(ll k)
{
    if(k==0)
        return 0;
    ll odd=0,even=0,p=1,tot=0,last=0;
    while(tot+p<k)
    {
        if(last==1)
        {
            even+=p;
            last=0;
        }
        else
        {
            odd+=p;
            last=1;
        }
        tot+=p;
        p*=2;
    }
    if(last==1)
		even+=(k-tot);
	else
		odd+=(k-tot);

    odd%=mod;
    even%=mod;
    ll ans=(odd*odd)%mod;
    ans+=(even*even)%mod;
    ans=(ans+even)%mod;
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    ll l,r;
    cin>>l>>r;
    cout<<(solve(r)-solve(l-1)+mod)%mod<<endl;
	return 0;
}
