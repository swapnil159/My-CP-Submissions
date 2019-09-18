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
    ll a1,a2,k1,k2,n;
	cin>>a1>>a2>>k1>>k2>>n;
	if(k1>k2)
	{
		swap(a1,a2);
		swap(k1,k2);
	}
	if(n<=a1*(k1-1)+a2*(k2-1))
	{
		cout<<"0 ";
	}
	else
	{
		cout<<n-(a1*(k1-1)+a2*(k2-1))<<" ";
	}
	ll ans=n/k1;
	n=n%k1;
	if(ans>a1)
	{
		n+=(ans-a1)*k1;
		ans=a1;
	}
	ans+=n/k2;
	cout<<ans<<endl;
	return 0;
}
