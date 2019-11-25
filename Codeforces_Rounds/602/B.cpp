/* winners never quit and quitters never win.
      #swap                                 */
      
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize ("-O3")
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
const ll inf = 1000000000000000000;
const ll rk = 256;
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
 
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
 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
 
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
/*ll ncr[5001][5001];
void coeff()
{
    for(ll a=0;a<5001;a++)
    {
        for(ll b=0;b<5001;b++)
        {
            ncr[a][b]=0;
        }
        ncr[a][0]=1;
    }
    for(ll a=1;a<5001;a++)
    {
        for(ll b=1;b<=a;b++)
        {
            ncr[a][b]=(ncr[a-1][b]+ncr[a-1][b-1])%mod;
        }
    }
}*/
ll fast_exp(ll base, ll exp1) {
    base%=mod;
    ll res=1;
    while(exp1>0) {
       if(exp1&1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp1/=2;
    }
    return res%mod;
} 
ll pr[1000001]={0};
void isprime()
{
    pr[0]=1;
    pr[1]=1;
    for(ll a=2;a*a<=1000001;a++)
    {
        if(!pr[a])
        {
            for(ll b=a*a;b<1000001;b+=a)
            {
                pr[b]=1;
            }
        }
    }
}
ll comp=1,tim=0;
struct vertex
{
    vc<ll> adj;
    ll vis=0;
    ll parent=-1;
    ll dist=0;
    ll component=0;
    ll in=0;
    ll out=0;
    ll low=0;
    ll child=0;
    ll indeg=0;
    ll outdeg=0;
    bool AP=false;
};
 
int32_t main() {
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
        vc<ll> v(n),ans(n,0);
        ll done[n+1]={0};
        rep(a,0,n)
        {
            cin>>v[a];
            if(a==0 or v[a]!=v[a-1])
            {
                ans[a]=v[a];
                done[v[a]]=1;
            }
        }
        ll b=1;
        rep(a,0,n)
        {
            if(ans[a])
                continue;
            while(done[b])
                b++;
            ans[a]=b;
            done[b]=1;
        }
        bool flag=false;
        ll maxi=0;
        rep(a,0,n)
        {
            maxi=max(maxi,ans[a]);
            if(maxi!=v[a])
                flag=true;
        }
        if(flag)
            cout<<-1<<endl;
        else
        {
            for(auto y:ans)
                cout<<y<<" ";
            cout<<endl;
        }
    }
	return 0;
}
