/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long  int ll;
using ld = long double;
int mod = 0;
const ll rk = 256;
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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
unordered_map<int,int> m[11];
const int N=2e5+5;
int n,k;
int x[N],len[N];
int D[11];
 
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
 
int leng(int n)
{
    int cnt=0;
    while(n)
    {
        cnt++;
        n/=10;
    }
    return cnt;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    cin>>n>>k;
    ll ans=0;
    mod=k;
    for(int i=0;i<=10;i++)
	{
		m[i].reserve(1<<15);
		m[i].max_load_factor(0.25);
	}
    for(int a=0;a<n;a++)
    {
        cin>>x[a];
        len[a]=leng(x[a]);
        x[a]%=k;
        m[len[a]][x[a]]++;
        //cout<<len<<" "<<b%k<<endl;
    }
    for(int a=0;a<11;a++)
        D[a]=fast_exp(10,a);
    for(int a=0;a<n;a++)
    {
        ll b=x[a];
        m[len[a]][b]--;
        for(int d=1;d<=10;d++)
        {
            ll p=(b*D[d])%k;
            ll req=(k-p)%k;
            ans+=m[d][req];
        }
        m[len[a]][b]++;
        //cout<<len<<" "<<b%k<<endl;
    }
    cout<<ans;
	return 0;
}
