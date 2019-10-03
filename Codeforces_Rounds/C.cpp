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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
	T
	{
		ll n;
		cin>>n;
		string s[2];
		cin>>s[0]>>s[1];
		ll i=1,j=n-1;
		bool flag=false;
		ll ans=0;
		while(i>=0 and j>=0)
		{
			ll b=s[i][j]-'0';
			if(b<3)
			{
				if(b==2)
					ans++;
				s[i][j]='2';
			}
			else
			{
				ll c=s[(i^1)][j]-'0';
				if(c<3)
				{
					flag=true;
					break;
				}
				if(i==1)
				{
					ans+=(b!=4)+(c!=6);
					s[i][j]='4';
					s[(i^1)][j]='6';
				}
				else
				{
					ans+=(b!=3)+(c!=5);
					s[i][j]='4';
					s[(i^1)][j]='6';
				}
				i^=1;
			}
			j--;
		}
		if(flag or i!=0)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}
