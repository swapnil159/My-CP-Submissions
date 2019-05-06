/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n,m,h;
    cin>>n>>h>>m;
    ll x[n+1];
    for(ll a=0;a<=n;a++)
        x[a]=h;
    for(ll a=0;a<m;a++)
    {
        ll l,r,t;
        cin>>l>>r>>t;
        for(ll b=l;b<=r;b++)
            x[b]=min(x[b],t);
    }
    ll ans=0;
    for(ll a=1;a<=n;a++){
        //cout<<x[a]<<endl;
        ans+=(x[a]*x[a]);
    }
    cout<<ans<<endl;
	return 0;
}
