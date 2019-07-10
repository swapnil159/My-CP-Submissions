/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    ll x[n][m];
    ll ans[n];
    for(ll a=0;a<n;a++)
    {
        ans[a]=0;
        for(ll b=0;b<m;b++)
        {
            cin>>x[a][b];
            if(b==0)
                sum=(sum^x[a][b]);
        }
    }
    if(sum>0)
    {
        cout<<"TAK\n";
        for(ll a=0;a<n;a++)
            cout<<ans[a]+1<<" ";
        cout<<endl;
    }
    else
    {
        for(ll a=0;a<n and sum==0;a++)
        {
            for(ll b=0;b<m;b++)
            {
                ll p=(sum^x[a][ans[a]])^x[a][b];
                if(p>0)
                {
                    sum=p;
                    ans[a]=b;
                    break;
                }
            }
        }
        if(sum==0)
        {
            cout<<"NIE\n";
        }
        else
        {
            cout<<"TAK\n";
            for(ll a=0;a<n;a++)
                cout<<ans[a]+1<<" ";
            cout<<endl;
        }
    }
    
	return 0;
}
