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
    string s,s1;
    cin>>s>>s1;
    ll y=0;
    ll n=s.length();
    ll pre[n]={0};
    for(ll a=1;a<n;a++)
    {
        pre[a]=pre[a-1];
        if(s[a]!=s[a-1])
            pre[a]++;
    }
    ll m=s1.length();
    for(ll a=0;a<m;a++)
        if(s[a]!=s1[a])
            y++;
    y%=2;
    ll ans=(y==0);
    for(ll a=m;a<n;a++)
    {
        ll diff=(pre[a]-pre[a-m])%2;
        y=(y^diff);
        ans+=(y==0);
    }
    cout<<ans<<endl;
	return 0;
}
