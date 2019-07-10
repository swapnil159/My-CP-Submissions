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
    ll x[n+1];
    x[0]=0;
    for(ll a=1;a<=n;a++)
        cin>>x[a];
    ll ans=0;
    for(ll a=1;a<=n;a++)
        if(x[a]<x[a-1])
            ans+=(x[a])*(x[a-1]-x[a]);
        else if(x[a]>x[a-1])
            ans+=(x[a]-x[a-1])*(n-x[a]+1);
    
    cout<<ans<<endl;
	return 0;
}
