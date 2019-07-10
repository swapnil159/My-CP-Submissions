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
ll i1=1,i2=1,j=1,j2=1;
ll one=0,two=1;
ll n,m;
void func1()
{
    if(one&1)
    {
        i1--;
        if(i1==0)
            one^=1,i1=1,j++;
    }
    else
    {
        i1++;
        if(i1==n+1)
            one^=1,i1=n,j++;
    }
    
}
void func2()
{
    if(two&1)
    {
        i2--;
        if(i2==0)
            two^=1,i2=1,j2--;
    }
    else
    {
        i2++;
        if(i2==n+1)
            two^=1,i2=n,j2--;
    }
    
}

int main() {
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    scanf("%lld %lld",&n,&m);
    i2=n,j2=m;
    ll cnt=n*m,p=0;
    for(ll a=0;a<cnt;a++)
    {
        if(p&1)
        {
            printf("%lld %lld\n",i2,j2);
            func2();
        }
        else
        {
            printf("%lld %lld\n",i1,j);
            func1();
        }
        p^=1;
    }
	return 0;
}
