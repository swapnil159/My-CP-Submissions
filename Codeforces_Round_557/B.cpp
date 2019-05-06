Copy
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
    ll n,m;
    cin>>n>>m;
    ll x[n][m],y[n][m];
    for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<m;b++)
        {
            cin>>x[a][b];
        }
    }
    for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<m;b++)
        {
            cin>>y[a][b];
        }
    }
    for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<m;b++)
        {
            if(x[a][b]>y[a][b])
                swap(x[a][b],y[a][b]);
        }
    }
    bool flag=false;
    for(ll a=0;a<n;a++)
    {
        for(ll b=1;b<m;b++)
        {
            if(x[a][b]<=x[a][b-1])
            {
                if(y[a][b]>x[a][b-1])
                    swap(x[a][b],y[a][b]);
            }
        }
    }
    for(ll a=1;a<n;a++)
    {
        for(ll b=0;b<m;b++)
        {
            if(x[a][b]<=x[a-1][b])
            {
                if(y[a][b]>x[a-1][b])
                    swap(x[a][b],y[a][b]);
            }
        }
    }
    for(ll a=0;a<n;a++)
    {
        for(ll b=1;b<m;b++)
        {
            if(x[a][b]<=x[a][b-1] or y[a][b]<=y[a][b-1])
            {
                flag=true;
            }
        }
    }
    for(ll a=1;a<n;a++)
    {
        for(ll b=0;b<m;b++)
        {
            if(x[a][b]<=x[a-1][b] or y[a][b]<=y[a-1][b])
            {
                flag=true;
            }
        }
    }

    if(flag)
        cout<<"Impossible\n";
    else
        cout<<"Possible\n";
	return 0;
}
