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
 
ll calc(ll mid)
{
	ll p=1,r=0,pos=0;
	while(r<=mid)
	{
		pos+=(((mid-r)*(mid-r+1))/2);
		r=(ll)pow(10,p)-1;
		p++;
	}
	return pos;
}
ll calc2(ll mid)
{
	ll len=1,ini=0,tot=0;
	while(ini<=mid)
	{
		tot+=(mid-ini);
		ini=(ll)pow(10,len)-1;
		len++;
	}
	return tot;
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
		ll k;
		cin>>k;
		ll low=0,high=mod-7;
		while(low<=high)
		{
			ll mid=(low+high)/2,pos=0;
			pos=calc(mid);
			if(pos<=k)
				low=mid+1;
			else
				high=mid-1;
		}
		ll p=calc(high);
		if(p!=k)
		{
			ll low1=1,high1=high+1;
			while(low1<=high1)
			{
				ll mid=(low1+high1)/2;
				ll tot=calc2(mid);
				if(tot+p<=k)
					low1=mid+1;
				else
					high1=mid-1;
			}
			p+=calc2(high1);
			high=high1;
			while(p<k)
			{
				ll next=high1+1,rev=0;
				while(next)
				{
					rev=rev*10+next%10;
					next/=10;
				}
				while(p<k)
				{
					high=rev%10;
					rev/=10;
					p++;
				}
			}
		}
		cout<<high%10<<endl;
	}
	return 0;
}
