/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#pragma GCC optimize ("-O3")
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
    T
    {
        ll h,n;
        cin>>h>>n;
        ll x[n];
        for(ll a=0;a<n;a++)
            cin>>x[a];
        ll ans=0;
        for(ll a=1;a<n;)
        {
            ll b=a+1;
            while(b<n and x[b]==x[a]-1)
                b++;
            ll cnt=b-a;
            if(b==n and x[n-1]==1)
                break;
            if(cnt&1)
                ans++;
            a=b;
        }
        cout<<ans<<endl;
    }
	return 0;
}
