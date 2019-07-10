/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
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

pll fin(pll a,pll b)
{
    return mp(max(a.fs,b.fs),min(a.sec,b.sec));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n,m;
    cin>>n>>m;
    vc<pll> v(m);
    ll st[n+1]={0},en[n+1]={0};
    for(ll a=0;a<m;a++)
    {
        cin>>v[a].fs>>v[a].sec;
        st[v[a].fs]++;
        en[v[a].sec]--;
    }
    ll x[n+1]={0},p=0;
    ll tot=0;
    for(ll a=0;a<=n;a++)
    {
        p+=st[a];
        x[a]=p;
        p+=en[a];
        if(x[a])
            tot++;
    }
    ll one[n+1]={0},two[n+1]={0};
    for(ll a=1;a<=n;a++)
    {
        if(x[a]==1)
        {
            one[a]=one[a-1]+1;
        }
        else
            one[a]=one[a-1];
        if(x[a]==2)
            two[a]=two[a-1]+1;
        else
            two[a]=two[a-1];
    }
    ll ans=0;
    for(ll a=0;a<m;a++)
    {
        for(ll b=a+1;b<m;b++)
        {
            ll cnt=tot;
            cnt-=(one[v[a].sec]-one[v[a].fs-1]);
            //cout<<a<<" "<<b<<" "<<cnt<<endl;
            cnt-=(one[v[b].sec]-one[v[b].fs-1]);
            //cout<<a<<" "<<b<<" "<<cnt<<endl;
            pll temp=fin(v[a],v[b]);
            //cout<<temp.fs<<" "<<temp.sec<<endl;
            if(temp.sec>=temp.fs)
                cnt-=(two[temp.sec]-two[temp.fs-1]);
            //cout<<a<<" "<<b<<" "<<cnt<<endl;
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
	return 0;
}
