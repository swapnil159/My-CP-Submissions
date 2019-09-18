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
    ll n;
	cin>>n;
	string s,s1;
	cin>>s>>s1;
	stack<ll> st,st1;
	for(ll a=0;a<n;a++)
	{
		if(s[a]=='a' and s1[a]=='b')
			st.push(a+1);
		if(s[a]=='b' and s1[a]=='a')
			st1.push(a+1);
	}
	if(((ll)st.size())%2!=((ll)st1.size())%2)
	{
		cout<<-1<<endl;
		exit(0);
	}
	vc<pll> v;
	while(st.size()>1)
	{
		ll temp=st.top();
		st.pop();
		ll po=st.top();
		st.pop();
		v.pb({temp,po});
	}
	while(st1.size()>1)
	{
		ll temp=st1.top();
		st1.pop();
		ll po=st1.top();
		st1.pop();
		v.pb({temp,po});
	}
	if(st.size()>0)
	{
		ll temp=st.top();
		st.pop();
		ll po=st1.top();
		st1.pop();
		v.pb({temp,temp});
		v.pb({temp,po});
	}
	cout<<v.size()<<endl;
	for(auto y:v)
		cout<<y.fs<<" "<<y.sec<<endl;
	return 0;
}
