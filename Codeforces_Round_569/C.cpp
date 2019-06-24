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
    ll n,m;
    cin>>n>>m;
    ll x[n];
    deque<ll> q;
    for(ll a=0;a<n;a++)
    {
        cin>>x[a];
        q.push_back(x[a]);
    }
    ll k=-1,maxi=*max_element(x,x+n);
    for(ll a=0;a<n;a++)
        if(x[a]==maxi){
            k=a;
            break;
        }
    vc<pll> ans;
    while(1)
    {
        ll p=q.front();
        q.pop_front();
        ll pp=q.front();
        q.pop_front();
        ans.pb({p,pp});
        if(p>pp)
            q.push_front(p),q.push_back(pp);
        else
            q.push_front(pp),q.push_back(p);
        if(q.front()==x[k])
            break;
    }
    ll g1=q.front();q.pop_front();ll g2=q.front();q.pop_front();
    ans.pb({g1,g2});
    if(g1>g2)
        q.push_front(g1),q.push_back(g2);
    else
        q.push_front(g2),q.push_back(g1);
    ll po=ans.size()-1;
    while(1)
    {
        ll p=q.front();
        q.pop_front();
        ll pp=q.front();
        q.pop_front();
        ans.pb({p,pp});
        if(p>pp)
            q.push_front(p),q.push_back(pp);
        else
            q.push_front(pp),q.push_back(p);
        p=q.front();
        q.pop_front();
        pp=q.front();
        q.pop_front();
        q.push_front(pp);
        q.push_front(p);
        //cout<<p<<" "<<pp<<endl;
        if(ans[po].fs==p and ans[po].sec==pp)
        {
            break;
        }
    }
    vc<ll> v;
    while(!q.empty())
    {
        ll p=q.front();
        q.pop_front();
        v.pb(p);
    }
    while(m--)
    {
        ll op;
        cin>>op;
        if(op<ans.size())
        {
            ll p=ans[op-1].fs,pp=ans[op-1].sec;
            cout<<p<<" "<<pp<<endl;
        }
        else
        {
            op-=ans.size();
            op%=(n-1);
            if(op==0)
                op=n-1;
            cout<<v[0]<<" "<<v[op]<<endl;
        }
    }
	return 0;
}
