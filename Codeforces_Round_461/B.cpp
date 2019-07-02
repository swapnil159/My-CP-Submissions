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
	ll n=0;
	cin>>n;
	ll ans=0;
	for(ll a=1;a<=n-2;a++)
	{
	    for(ll b=a+1;b<=n-1;b++)
	    {
	        ll c=a^b;
	        if(c<=n && c>b && (a+b>c) && (a+c>b) && (c+b>a))
	        {
	            ans++;
	            //cout<<a<<" "<<b<<" "<<c<<endl;
	        }
	    }
	}
	cout<<ans<<endl;

