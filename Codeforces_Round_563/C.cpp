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
 
ll pr[1000001]={0};
void isprime()
{
    pr[0]=1;
    pr[1]=1;
    for(ll a=2;a*a<=1000001;a++)
    {
        if(!pr[a])
        {
            for(ll b=a*a;b<1000001;b+=a)
            {
                pr[b]=1;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    ll cnt=0;
    ll x[n+1];
    for(ll a=2;a<=n;a++)
    {
        if(!pr[a])
        {
            cnt++;
            x[a]=cnt;
            for(ll b=a;b<=n;b+=a)
                x[b]=cnt;
        }
        cout<<x[a]<<" ";
    }
	return 0;
}
