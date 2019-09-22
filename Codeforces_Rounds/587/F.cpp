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
 
void build(ll seg[],ll dp[],ll low,ll high,ll pos)
{
	if(low==high)
	{
		seg[pos]=dp[low];
		return;
	}
	ll mid=(low+high)/2;
	build(seg,dp,low,mid,2*pos+1);
	build(seg,dp,mid+1,high,2*pos+2);
	seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
 
void update(ll seg[],ll qlow,ll qhigh,ll low,ll high,ll pos,ll val)
{
	if(low>high or qlow>high or qhigh<low)
		return;
	
	if(low==high)
	{
		seg[pos]=val;
		return;
	}
 
	ll mid=(low+high)/2;
	update(seg,qlow,qhigh,low,mid,2*pos+1,val);
	update(seg,qlow,qhigh,mid+1,high,2*pos+2,val);
	seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
 
ll query(ll seg[],ll qlow,ll qhigh,ll low,ll high,ll pos)
{
	if(qlow<=low and qhigh>=high)
		return seg[pos];
	if(qlow>high or qhigh<low)
		return inf;
	ll mid=(low+high)/2;
	return min(query(seg,qlow,qhigh,low,mid,2*pos+1),query(seg,qlow,qhigh,mid+1,high,2*pos+2));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vc<pll> v[n];
	ll dp[n+1];
	dp[0]=0;
	for(ll a=0;a<n;a++)
	{
		dp[a+1]=inf;
		if(s[a]=='1')
			v[min(n-1,a+k)].pb({max(0*1LL,a-k),a});
		else
			v[a].pb({a,a});
	}
	ll seg[4*n];
	build(seg,dp,0,n,0);
	for(ll a=0;a<n;a++)
	{
		ll po=inf;
		for(auto y:v[a])
		{
			//cout<<a<<" "<<y.sec<<" "<<y.fs<<endl;
			po=min(po,query(seg,y.fs,a,0,n,0)+y.sec+1);
		}
		update(seg,a+1,a+1,0,n,0,po);
		//cout<<a<<" "<<po<<endl;
		dp[a+1]=po;
	}
	cout<<dp[n]<<endl;
	return 0;
}
