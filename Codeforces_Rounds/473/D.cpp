/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#pragma GCC optimize ("-O3")
#define mod 998244353
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
 
ll pr[2000005]={0};
void isprime()
{
    for(ll a=0;a<2000005;a++)
        pr[a]=a;
    pr[0]=1;
    for(ll a=2;a*a<=2000005;a++)
    {
        if(pr[a]==a)
        {
            for(ll b=a*a;b<2000005;b+=a)
            {
                pr[b]=a;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    ll x[n];
    for(ll a=0;a<n;a++)
        cin>>x[a];
    set<ll> s;
    for(ll a=2;a<2000005;a++)
        s.insert(a);
    ll pos=0;
    for(ll a=0;a<n;a++)
    {
        bool flag=false;
        ll p=x[a];
        auto it=s.lb(p);
        ll po=(*it);
        if(po!=x[a])
        {
            flag=true;
        }
        x[a]=po;
        pos++;
        while(po>1)
        {
            ll g=pr[po];
            for(ll b=g;b<2000005;b+=g)
            {
                if(s.find(b)!=s.end())
                    s.erase(s.find(b));
            }
            while(po%g==0)
                po/=g;
        }
        if(flag)
            break;
    }
    for(ll a=pos;a<n;a++)
    {
        ll po=(*s.begin());
        x[a]=po;
        while(po>1)
        {
            ll g=pr[po];
            for(ll b=g;b<2000005;b+=g)
            {
                if(s.find(b)!=s.end())
                    s.erase(s.find(b));
            }
            while(po%g==0)
                po/=g;
        }
    }
    for(ll a=0;a<n;a++)
        cout<<x[a]<<" ";
    cout<<endl;
	return 0;
}
