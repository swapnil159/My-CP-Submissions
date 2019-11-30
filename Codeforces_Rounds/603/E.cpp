/* winners never quit and quitters never win.
      #swap                                 */
      
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize ("-O3")
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
const ll rk = 256;
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
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
 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
 
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
ll m;
 
void update_seg(vc<pll> &seg,ll lazy[],ll qlow,ll qhigh,ll val,ll low,ll high,ll pos)
{
	if(low>high)
		return;
	if(lazy[pos]!=0)
	{
		seg[pos].fs+=lazy[pos];
		seg[pos].sec+=lazy[pos];
		if(low!=high)
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(qlow>high or qhigh<low)
		return;
	
	if(qlow<=low and qhigh>=high)
	{
		seg[pos].fs+=val;
		seg[pos].sec+=val;
		if(low!=high)
		{
			lazy[2*pos+1]+=val;
			lazy[2*pos+2]+=val;
		}
		return;
	}
	ll mid=(low+high)/2;
	update_seg(seg,lazy,qlow,qhigh,val,low,mid,2*pos+1);
	update_seg(seg,lazy,qlow,qhigh,val,mid+1,high,2*pos+2);
	seg[pos].fs=max(seg[2*pos+1].fs,seg[2*pos+2].fs);
	seg[pos].sec=min(seg[2*pos+1].sec,seg[2*pos+2].sec);
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
	cin>>n;
	string s;
	cin>>s;
	m=1;
	for(auto y:s)
		m+=(y=='R');
	ll BIT[m+1]={0};
	vc<pll> seg(4*m);
	rep(a,0,4*m)
	{
		seg[a].fs=0;
		seg[a].sec=0;
	}
	ll lazy[4*m]={0};
	ll val[m]={0};
	ll ind=0,p=0;
	for(ll a=0;a<n;a++)
	{
		if(s[a]=='R')
			ind++;
		else if(s[a]=='L')
			ind--;
		else if(s[a]=='(')
		{
			if(val[ind]!=1)
			{
				ll temp=1-val[ind];
				update_seg(seg,lazy,ind,m-1,temp,0,m-1,0);
				p+=temp;
				val[ind]=1;
			}
		}
		else if(s[a]==')')
		{
			if(val[ind]!=-1)
			{
				ll temp=-1-val[ind];
				update_seg(seg,lazy,ind,m-1,temp,0,m-1,0);
				p+=temp;
				val[ind]=-1;
			}
		}
		else if(val[ind]!=0)
		{
			ll temp=0-val[ind];
			update_seg(seg,lazy,ind,m-1,temp,0,m-1,0);
			p+=temp;
			val[ind]=0;
		}
		if(p==0 and seg[0].sec==0)
		{
			cout<<seg[0].fs<<" ";
		}
		else
		{
			cout<<-1<<" ";
		}
		ind=max(ind,0*1LL);
	}
	cout<<endl;
	return 0;
}
