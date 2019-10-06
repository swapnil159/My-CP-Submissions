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
	ll n,k;
	cin>>n>>k;
	set<pll> q;
	set<pll,greater<pll>> q1;
	map<ll,ll> m;
	for(ll a=0;a<n;a++)
	{
		ll id;
		cin>>id;
		if(m[id]>0)
		{
			if(q.find({m[id],id})!=q.end()){
				continue;
			}
		}
		if(q.size()==k)
		{
			pll temp=(*q.begin());
			q.erase(temp);
			q1.erase(temp);
		}
		m[id]=a+1;
		q.insert({m[id],id});
		q1.insert({m[id],id});
	}
	cout<<q.size()<<endl;
	for(auto it=q1.begin();it!=q1.end();it++)
		cout<<(*it).sec<<" ";
	cout<<endl;
	return 0;
}
