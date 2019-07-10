/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#pragma GCC optimize ("-O3")
#define mod 1000000007
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=mod;
    for(ll a=0;a<n-3;a++)
    {
        ll po=0;
        ll b=s[a]-'A';
        po+=min(b,26-b);
        b=s[a+1]-'A';
        b=min(llabs(b-2),26-llabs(b-2));
        po+=b;
        b=s[a+2]-'A';
        b=min(llabs(b-19),26-llabs(b-19));
        po+=b;
        b=s[a+3]-'A';
        b=min(llabs(b-6),26-llabs(b-6));
        po+=b;
        ans=min(ans,po);
    }
    cout<<ans;
	return 0;
}
