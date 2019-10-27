/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define rk 256
#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll> 
#define all(v) v.begin(),v.end()
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	ll n,k,s;
	cin>>n>>k>>s;
	ll steps=s/(n-1);
	if(s%(n-1))
	{
	    steps++;
	}
	if(steps>k || s<k)
	{
	    cout<<"NO\n";
	    exit(0);
	}
	ll s1=s;
	ll curr=n-1,next=n;
	vc<ll> v;
	while(curr<=s1)
	{
	    v.pb(next);
	    s1-=curr;
	    if(next==n)
	        next=1;
	    else
	        next=n;
	}
	if(s1)
	{
	    if(next==n)
	        v.pb(s1+1);
	    else
	        v.pb(n-s1);
	}
	    cout<<"YES\n";
	    ll rem=k-v.size();
	    for(ll a=0;a<v.size();a++)
	    {
	        if(rem)
	        {
	            if(v[a]==n)
	            {
	                ll cnt=2;
	                while(rem && cnt<n)
	                {
	                    cout<<cnt<<" ";
	                    cnt++;
	                    rem--;
	                }
	            }
	            else if(v[a]==1)
	            {
	                ll cnt=n-1;
	                while(rem && cnt>1)
	                {
	                    cout<<cnt<<" ";
	                    cnt--;
	                    rem--;
	                }
	            }
	            else
	            {
	                if(v[a-1]==n)
	                {
	                    for(ll b=n-1;b>v[a] && rem;b--,rem--)
	                    {
	                        cout<<b<<" ";
	                    }
	                }
	                else
	                {
	                    for(ll b=2;b<v[a] && rem;b++,rem--)
	                    {
	                        cout<<b<<" ";
	                    }
	                }
	            }
	        }
	        cout<<v[a]<<" ";
	    }
	    cout<<endl;
	return 0;
}
