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
struct ele
{
    string s;
    ll cnts=0;
    ll cnth=0;
};
void eval(ele &x)
{
    for(auto y:x.s)
    {
        if(y=='s')
            x.cnts++;
        else
            x.cnth++;
    }
}
bool comp(ele a,ele b)
{
    return a.cnts*b.cnth > b.cnts*a.cnth;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    ele x[n];
    for(ll a=0;a<n;a++)
        cin>>x[a].s;
    for(ll a=0;a<n;a++)
        eval(x[a]);
    sort(x,x+n,comp);
    ll ans=0,p=0;
    for(ll a=0;a<n;a++)
    {
        for(auto y:x[a].s)
        {
            if(y=='s')
                p++;
            else
                ans+=p;
        }
    }
    cout<<ans<<endl;
	return 0;
}
