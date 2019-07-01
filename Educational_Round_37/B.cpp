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
	    ll n=0;
	    cin>>n;
	    vc< pair<ll,ll> > v;
	    for(ll a=0;a<n;a++)
	    {
	        ll l=0,r=0;
	        cin>>l>>r;
	        v.pb(mp(l,r));
	    }
	    ll time=1;
	    ll x[n]={0};
	    for(ll a=0;a<n;a++)
	    {
	        if(time>v[a].sec)
	        {
	            x[a]=0;
	            continue;
	        }
	        if(time<=v[a].fs)
	        {
	            time=v[a].fs;
	                x[a]=time;
	                time++;
	        }
	        else
	        {
	            x[a]=time;
	            time++;
	        }
	    }
	    for(ll a=0;a<n;a++)
	    {
	        cout<<x[a]<<" ";
	    }
	    cout<<endl;
	    v.clear();
	}
	return 0;
}
