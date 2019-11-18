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
        ll x[n];
        rep(a,0,n)
            cin>>x[a];
        ll m;
        cin>>m;
        vc<pll> v(m);
        ll max_pow=0;
        rep(a,0,m){
            cin>>v[a].fs>>v[a].sec;
            max_pow=max(max_pow,v[a].fs);
        }
        if(max_pow<*max_element(x,x+n))
        {
            cout<<-1<<endl;
            continue;
        }
        sort(all(v));
        ll ans=0,b=0,maxi=0;
        ll p[m];
        p[m-1]=v[m-1].sec;
        for(ll a=m-2;a>=0;a--)
        {
            p[a]=max(v[a].sec,p[a+1]);
        }
        for(ll a=0;a<n;)
        {
            maxi=0;
            while(b<n)
            {
                maxi=max(maxi,x[b]);
                ll k=lb(all(v),mp(maxi,b-a+1))-v.begin();
                //cout<<a<<" "<<" "<<b<<" "<<maxi<<" "<<p[k]<<endl;
                if(k==m or p[k]<b-a+1)
                    break;
                b++;
            }
            //cout<<a<<" "<<b<<endl;
            ans++;
            a=b;
        }
        cout<<ans<<endl;
    }
	return 0;
}
