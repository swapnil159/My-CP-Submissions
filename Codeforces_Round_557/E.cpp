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
    ll n;
    cin>>n;
    ll x[n];
    for(ll a=0;a<n;a++)
        cin>>x[a];
    sort(x,x+n);
    if(x[0]==x[n/2])
        cout<<"Bob\n";
    else
        cout<<"Alice\n";
	return 0;
}
