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
	T
	{
		ll n;
		cin>>n;
		string s,s1;
		cin>>s;
		if(n==1)
		{
			cout<<n<<endl;
			continue;
		}
		vc<ll> v[10];
		bool flag=false;
		for(ll a=0;a<n;a++)
		{
			ll val=s[a]-'0';
			v[val].pb(a);
		}
		ll p=-1,pos=-1,las=-1;
		for(ll a=0;a<10;a++)
		{
			if(v[a].size())
			{
				if(v[a][0]>p)
				{
					for(auto y:v[a])
					{
						s[y]='1';
						p=y;
						las=y;
					}
				}
				else
				{
					pos=a;
					break;
				}
			}
		}
		ll fis=n+1;
		if(pos!=-1)
		{
			ll pos2=-1;
			p=-1;
			for(ll a=pos+1;a<10;a++)
			{
				if(v[a].size())
				{
					if(v[a][0]>p)
					{
						for(auto y:v[a])
						{
							if(fis==n+1)
								fis=y;
							s[y]='2';
							p=y;
						}
					}
					else
					{
						pos2=a;
						break;
					}
				}
			}
			if(pos2!=-1)
				flag=true;
		}
		ll k1=-1;
		for(ll a=0;pos!=-1 and a<v[pos].size();a++)
		{
			if(v[pos][a]>fis)
			{
				k1=a;
				break;
			}
			s[v[pos][a]]='2';
		}
		if(k1!=-1)
		{
			for(ll a=k1;a<v[pos].size();a++)
			{
				if(v[pos][a]<las)
				{
					flag=true;
					break;
				}
				else
					s[v[pos][a]]='1';
			}
		}
		if(flag)
			cout<<"-\n";
		else
			cout<<s<<endl;
 
	}
	return 0;
}
