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
vc<ll> solve(string s)
{
    ll n=s.length();
    ll cnt=1;
    vc<ll> ans;
    for(ll a=1;a<n;a++)
    {
        if(s[a]==s[a-1])
            cnt++;
        else
        {
            ans.pb(cnt);
            cnt=1;
        }
        
    }
    ans.pb(cnt);
    return ans;
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
    vc<pll> v;
    for(ll a=0;a<n;a++)
    {
        ll b;
        cin>>b;
        v.pb({b,a+1});
    }
    sort(all(v));
    if(n==2)
    {
        cout<<1<<endl;
        exit(0);
    }
    bool flag=false;
    for(ll a=2;a<n;a++)
    {
        if(v[a].fs-v[a-1].fs!=v[2].fs-v[1].fs)
            flag=true;
    }
    if(!flag)
    {
        cout<<v[0].sec<<endl;
        exit(0);
    }
    flag=false;
    for(ll a=1;a<n-1;a++)
    {
        if(v[a].fs-v[a-1].fs!=v[n-2].fs-v[n-3].fs)
            flag=true;
    }
    if(!flag)
    {
        cout<<v[n-1].sec<<endl;
        exit(0);
    }
    ll d=v[n-1].fs-v[0].fs;
    d/=(n-2);
    if(v[n-1].fs!=v[0].fs+d*(n-2))
    {
        cout<<-1<<endl;
        exit(0);
    }
    ll pos=-1;
    for(ll a=1;a<n;a++)
    {
        ll p=a,p1=a-1;
        if(p1==pos)
            p1--;
        if(v[p].fs-v[p1].fs!=d)
        {
            if(pos==-1)
                pos=a;
            else
            {
                cout<<-1<<endl;
                exit(0);
            }
        }
    }
    cout<<v[pos].sec<<endl;
	return 0;
}
