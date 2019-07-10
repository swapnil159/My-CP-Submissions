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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n,m;
    cin>>n>>m;
    string s[n];
    for(ll a=0;a<n;a++)
        cin>>s[a];
    bool flag=false;
    ll low[n][m],right[n][m],top[n][m],left[n][m];
    for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<m;b++)
        {
            low[a][b]=0;
            right[a][b]=0;
            top[a][b]=0;
            left[a][b]=0;
        }
    }
    for(ll a=n-1;a>0;a--)
    {
        for(ll b=0;b<m;b++)
        {
            if(s[a][b]=='*')
                low[a-1][b]+=low[a][b]+1;
        }
    }
    for(ll a=m-1;a>0;a--)
    {
        for(ll b=0;b<n;b++)
        {
            if(s[b][a]=='*')
                right[b][a-1]+=right[b][a]+1;
        }
    }
    for(ll a=0;a<n-1;a++)
    {
        for(ll b=0;b<m;b++)
        {
            if(s[a][b]=='*')
                top[a+1][b]+=top[a][b]+1;
        }
    }
    for(ll a=0;a<m-1;a++)
    {
        for(ll b=0;b<n;b++)
        {
            if(s[b][a]=='*')
                left[b][a+1]+=left[b][a]+1;
        }
    }
    ll cnt=0;
    for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<m;b++)
        {
            if(s[a][b]=='*')
                cnt++;
        }
    }
    for(ll a=1;a<n-1;a++)
    {
        for(ll b=1;b<m-1;b++)
        {
            if(s[a][b]=='*' and top[a][b] and left[a][b] and right[a][b] and low[a][b] and top[a][b]+low[a][b]+right[a][b]+left[a][b]+1==cnt)
            {
                cout<<"YES\n";
                exit(0);
            }
        }
    }
            cout<<"NO\n";
	return 0;
}
