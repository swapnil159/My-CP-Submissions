/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    ll n;
    cin>>n;
    ll ans=0,po=0;
    while(n/10>0)
    {
        n++;
        ll k=(10-(n%10))%10;
        //cout<<n<<" "<<k<<endl;
        ans+=(k+1);
        n+=k;
        while(n%10==0 and n>0)
            n/=10;
    }
    cout<<ans+9<<endl;
	return 0;
}
