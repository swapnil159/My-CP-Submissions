/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef  int ll;
using ld = long double;
const ll mod = 1000000007;
const ll inf = 1000000000000000001;
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
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n,m;
    cin>>n>>m;
    string s[n],s1[n];
    rep(a,0,n)
    {
        cin>>s[a];
    }
    ll top[n][m],down[n][m],left[n][m],right[n][m],rows[n][m],cols[n][m];
    rep(a,0,n)
    {
        rep(b,0,m)
        {
            top[a][b]=0;
            down[a][b]=0;
            left[a][b]=0;
            right[a][b]=0;
            rows[a][b]=0;
            cols[a][b]=0;
            s1[a]+=".";
        }
    }
    
    /* TOP */
    rep(a,1,n)
    {
        rep(b,0,m)
        {
            if(s[a][b]=='*')
            {
                top[a][b]=top[a-1][b]+(s[a-1][b]=='*');
            }
        }
    }
    
    /* DOWN */
    for(ll a=n-2;a>=0;a--)
    {
        rep(b,0,m)
        {
            if(s[a][b]=='*')
            {
                down[a][b]=down[a+1][b]+(s[a+1][b]=='*');
            }
        }
    }
 
    /* LEFT */
    rep(a,0,n)
    {
        rep(b,1,m)
        {
            if(s[a][b]=='*')
            {
                left[a][b]=left[a][b-1]+(s[a][b-1]=='*');
            }
        }
    }
 
    /* RIGHT */
    rep(a,0,n)
    {
        for(ll b=m-2;b>=0;b--)
        {
            if(s[a][b]=='*')
            {
                right[a][b]=right[a][b+1]+(s[a][b+1]=='*');
            }
        }
    }
 
 
    vc<pair<pll,ll>> ans;
    rep(a,1,n)
    {
        rep(b,1,m)
        {
            if(s[a][b]=='*')
            {
                ll mini=min({top[a][b],down[a][b],left[a][b],right[a][b]});
                if(mini>0){
                    //cout<<a<<" "<<b<<" "<<mini<<endl;
                    ans.pb({{a,b},mini});
                    rows[a-mini][b]++;
                    if(a+mini+1<n)
                        rows[a+mini+1][b]--;
                    cols[a][b-mini]++;
                    if(b+mini+1<m)
                        cols[a][b+mini+1]--;
                }
            }
        }
    }
 
 
    /* CHECKING */
    rep(a,0,m)
    {
        ll p=0;
        rep(b,0,n)
        {
            p+=rows[b][a];
            if(p>0)
                s1[b][a]='*';
        }
    }
 
    rep(a,0,n)
    {
        ll p=0;
        rep(b,0,m)
        {
            p+=cols[a][b];
            if(p>0)
                s1[a][b]='*';
        }
    }
 
    bool flag=false;
    rep(a,0,n)
    {
        rep(b,0,m)
        {
            if(s[a][b]!=s1[a][b])
                flag=true;
        }
    }
    if(flag)
        cout<<-1<<endl;
    else
    {
        cout<<ans.size()<<endl;
        for(auto y:ans)
            cout<<y.fs.fs+1<<" "<<y.fs.sec+1<<" "<<y.sec<<endl;
    }
	return 0;
}
