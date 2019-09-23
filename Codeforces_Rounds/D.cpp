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
struct vertex
{
    ll val;
    ll ans;
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    vertex x[n];
    for(ll a=0;a<n;a++)
        cin>>x[a].val;
    for(ll a=0;a<n;a++)
        cin>>x[a].ans;
    map<ll,ll> m,m1;
    for(ll a=0;a<n;a++)
    {
        if(m1[x[a].val])
            continue;
        for(ll b=a+1;b<n;b++)
        {
            if(x[a].val==x[b].val)
            {
                m1[x[a].val]=1;
                if(m[x[a].val]==0)
                    m[x[a].val]=x[a].ans+x[b].ans;
                else
                    m[x[a].val]=x[a].ans;
            }
        }
    }
    if(m.size()==0)
        cout<<0<<endl;
    else
    {
        ll ans=0;
        bool done[n]={false};
        for(auto it=m.begin();it!=m.end();it++)
        {
            ll po=0,val=(*it).fs;
            for(ll a=0;a<n;a++)
            {
                if((x[a].val&val)==x[a].val and !done[a]){
                    po+=x[a].ans;
                    done[a]=true;
                }
            }
            ans+=po;
        }
        cout<<ans<<endl;
    }
	return 0;
}
