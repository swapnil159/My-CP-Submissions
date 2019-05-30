/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define inf 1000000000000000000
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
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define all(v) v.begin(),v.end()
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n,k;
    cin>>n>>k;
    map<ll,ll> m;
    ll x[n];
    for(ll a=0;a<n;a++)
    {
        ll b;
        cin>>b;
        x[a]=b%k;
        m[b%k]++;
    }
    ll ans=(m[0]/2)*2;
    if(k&1)
    {
        for(ll a=1;a<=k/2;a++)
        {
            ll b=m[a];
            ll c=m[k-a];
            ans+=min(b,c)*2;
        }
    }
    else
    {
        ans+=(m[k/2]/2)*2;
        for(ll a=1;a<k/2;a++)
        {
            ll b=m[a];
            ll c=m[k-a];
            ans+=min(b,c)*2;
        }
    }
    cout<<ans<<endl;
	return 0;
}
