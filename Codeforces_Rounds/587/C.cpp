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
bool check(ll x,ll y,ll x1,ll y1,ll x2,ll y2)
{
	return !(x>=x1 and x<=x2 and y>=y1 and y<=y2);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
	ll x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	x1*=2,y1*=2,x2*=2,y2*=2;
	ll x3,y3,x4,y4;
	cin>>x3>>y3>>x4>>y4;
	x3*=2,y3*=2,x4*=2,y4*=2;
	ll x5,y5,x6,y6;
	cin>>x5>>y5>>x6>>y6;
	x5*=2,y5*=2,x6*=2,y6*=2;
	bool flag=false;
	for(ll a=x1;a<=x2;a++)
	{
		if(!(a>=x3 and a<=x4 and y1>=y3 and y1<=y4) and !(a>=x5 and a<=x6 and y1>=y5 and y1<=y6))
			flag=true;
		if(!(a>=x3 and a<=x4 and y2>=y3 and y2<=y4) and !(a>=x5 and a<=x6 and y2>=y5 and y2<=y6))
			flag=true;
	}
	for(ll a=y1;a<=y2;a++)
	{
		if(!(a>=y3 and a<=y4 and x1>=x3 and x1<=x4) and !(a>=y5 and a<=y6 and x1>=x5 and x1<=x6))
			flag=true;
		if(!(a>=y3 and a<=y4 and x2>=x3 and x2<=x4) and !(a>=y5 and a<=y6 and x2>=x5 and x2<=x6))
			flag=true;
	}
	if(flag)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}