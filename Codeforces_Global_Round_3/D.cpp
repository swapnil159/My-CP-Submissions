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

bool comp(pll a,pll b)
{
    return a.sec<b.sec;
}

 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    vc<pll> v1,v;
    map<pll,ll> m;
    for(ll a=0;a<n;a++)
    {
        ll i,j;
        cin>>i>>j;
        m[{i,j}]=a+1;
        if(i<j)
            v1.pb({i,j});
        else
            v.pb({i,j});
    }
    sort(all(v1),comp);
    sort(all(v),comp);
    if(v.size()>v1.size())
    {
        cout<<v.size()<<endl;
        for(auto y:v)
            cout<<m[y]<<" ";
    }
    else
    {
        reverse(all(v1));
        cout<<v1.size()<<endl;
        for(auto y:v1)
            cout<<m[y]<<" ";
    }
	return 0;
}
