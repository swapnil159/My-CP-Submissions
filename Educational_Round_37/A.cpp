#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
 
int main() {
    ios_base::sync_with_stdio(false);
	ll t=0;
	cin>>t;
	while(t--)
	{
	    ll n=0,k=0;
	    cin>>n>>k;
	    ll x[k]={0};
	    for(ll a=0;a<k;a++)
	    {
	        cin>>x[a];
	    }
	    sort(x,x+k);
	    ll ans=x[0];
	    ll y[n+1]={0},pos=1;
	    for(ll a=x[0]+1;a<=n;a++)
	    {
	        if(a==x[pos])
	        {
	            pos++;
	            continue;
	        }
	        if(pos<k)
	        {
	            y[a]=min(a-x[pos-1]+1,x[pos]-a+1);
	            ans=max(ans,y[a]);
	        }
	        else
	        {
	            ans=max(ans,llabs(a-x[k-1])+1);
	        }
	        //cout<<a<<" "<<y[a]<<endl;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
