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
    string s;
    cin>>s;
    ll x[10];
    x[0]=0;
    for(ll a=1;a<10;a++)
        cin>>x[a];
    ll pos=-1;
    for(ll a=0;a<n;a++)
        if(x[s[a]-'0']>(s[a]-'0'))
        {
            pos=a;
            break;
        }
    if(pos!=-1)
    {
        while(pos<n and x[s[pos]-'0']>=(s[pos]-'0'))
        {
            s[pos]=(char)(x[s[pos]-'0']+'0');
            pos++;
        }
    }
    cout<<s<<endl;
	return 0;
}
