/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
vc<vc<ll>> seg(400005,vc<ll>(26,0));
string s;
 
void update(ll qlow,ll qhigh,ll low,ll high,ll pos,ll val)
{
	if(low>high or qlow>high or qhigh<low)
		return;
	if(qlow<=low and qhigh>=high)
	{
		for(ll a=0;a<26;a++)
			if(seg[pos][a])
				seg[pos][a]=0;
		seg[pos][val]=1;
		return;
	}
	ll mid=(low+high)/2;
	update(qlow,qhigh,low,mid,2*pos+1,val);
	update(qlow,qhigh,mid+1,high,2*pos+2,val);
	for(ll a=0;a<26;a++)
	{
		seg[pos][a]=seg[2*pos+1][a]+seg[2*pos+2][a];
	}
}
 
vc<ll> query(ll qlow,ll qhigh,ll low,ll high,ll pos)
{
	vc<ll> v(26,0);
	if(low>high or qlow>high or qhigh<low)
		return v;
	if(qlow<=low and qhigh>=high)
	{
		return seg[pos];
	}
	ll mid=(low+high)/2;
	vc<ll> v1=query(qlow,qhigh,low,mid,2*pos+1);
	vc<ll> v2=query(qlow,qhigh,mid+1,high,2*pos+2);
	for(ll a=0;a<26;a++)
	{
		v[a]=v1[a]+v2[a];
	}
	return v;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
	cin>>s;
	ll n=s.length();
	for(ll a=0;a<n;a++)
	{
		update(a,a,0,n-1,0,s[a]-'a');
	}
	T
	{
		ll type,l,r;
		cin>>type;
		if(type==1)
		{
			ll pos;
			char c;
			cin>>pos>>c;
			pos--;
			ll val=c-'a';
			update(pos,pos,0,n-1,0,val);
		}
		else{
			cin>>l>>r;
			l--,r--;
			vc<ll> v=query(l,r,0,n-1,0);
			ll ans=0;
			for(auto y:v)
				ans+=(y!=0);
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
