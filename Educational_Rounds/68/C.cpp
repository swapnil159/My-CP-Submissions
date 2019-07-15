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
 
bool is_subsequence(string s1,string s2)
{
	ll p=0;
	for(ll a=0;a<s2.length();a++)
	{
		if(s2[a]==s1[p])
			p++;
		if(p==s1.length())
			return true;
	}
	return false;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    T
	{
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		if(!is_subsequence(s1,s2))
		{
			cout<<"NO\n";
			continue;
		}
		ll x[26]={0},y[26]={0};
		bool flag=true;
		for(auto y:s3)
			x[y-'a']++;
		for(auto y:s1)
			x[y-'a']++;
		for(auto y1:s2)
			y[y1-'a']++;
		for(ll a=0;a<26;a++)
			if(x[a]<y[a])
				flag=false;
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
