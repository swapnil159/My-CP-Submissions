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
bool comp(ll a,ll b)
{
    return a>b;
}
ll pr[2800000]={0};
void isprime()
{
    pr[0]=1;
    pr[1]=1;
    for(ll a=2;a*a<=2800000;a++)
    {
        if(!pr[a])
        {
            for(ll b=a*a;b<2800000;b+=a)
            {
                pr[b]=1;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   
	isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    vc<ll> prime;
    for(ll a=0;a<2800000;a++)
    {
        if(!pr[a])
            prime.pb(a);
    }
    ll div[2800000];
    div[1]=1;
    for(ll a=2;a<2800000;a++)
    {
        if(!pr[a])
            div[a]=1;
        for(ll b=2*a;b<2800000;b+=a){
            div[b]=a;
        }
    }
    ll n;
    cin>>n;
    ll x[2*n];
    multiset<ll> s;
    for(ll a=0;a<2*n;a++)
    {
        cin>>x[a];
        s.insert(x[a]);
    }
    sort(x,x+2*n,comp);
    vc<ll> ans;
    for(ll a=0;a<2*n;a++)
    {
        if(s.find(x[a])==s.end())
            continue;
            if(s.find(div[x[a]])!=s.end())
            {
                ans.pb(x[a]);
                s.erase(s.find(x[a]));
                s.erase(s.find(div[x[a]]));
            }
    }
    for(ll a=0;a<2*n;a++)
    {
        if(s.find(x[a])!=s.end())
        {
            if(x[a]<=199999)
            {
                if(s.find(prime[x[a]-1])!=s.end())
                {
                    ans.pb(x[a]);
                    s.erase(s.find(x[a]));
                    s.erase(s.find(prime[x[a]-1]));
                }
            }
        }
    }
    for(auto y:ans)
        cout<<y<<" ";
    cout<<endl;
	return 0;
}
