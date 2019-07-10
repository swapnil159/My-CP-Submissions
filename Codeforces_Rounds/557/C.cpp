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
    ll n,k;
    cin>>n>>k;
    ll first[n+1],last[n+1];
    for(ll a=0;a<=n;a++)
    {
        first[a]=-1;
        last[a]=-1;
    }
    for(ll a=0;a<k;a++)
    {
        ll b;
        cin>>b;
        if(first[b]==-1)
            first[b]=a;
        last[b]=a;
    }
    ll ans=0;
    for(ll a=1;a<=n;a++)
    {
        if(first[a]==-1)
        {
            ans++;
            if(a<n)
                ans++;
            if(a>1)
                ans++;
            continue;
        }
        if(a<n and last[a+1]<first[a])
        {
            //cout<<last[a+1]<<" "<<last[a]<<" "<<a<<endl;
            ans++;
        }
        if(a>1 and last[a-1]<first[a])
            ans++;
    }
    cout<<ans<<endl;
	return 0;
}
