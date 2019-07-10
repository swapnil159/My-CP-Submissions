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
#define endl '\n'
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
    vc<ll> di;
    for(ll a=1;a<=(ll)sqrt(n);a++)
    {
        if(n%a==0)
        {
            di.pb(a);
            if(a*a!=n)
                di.pb(n/a);
        }
    }
    sort(all(di));
    vc<ll> v[n];
    for(ll a=0;a<m;a++)
    {
        ll i,j;
        cin>>i>>j;
        i--,j--;
        if(i>j)
            swap(i,j);
        v[i].pb(j);
        v[j].pb(i+n);
    }
    for(ll a=0;a<n;a++)
        sort(all(v[a]));
    bool flag=false;
    for(auto y:di)
    {
        if(y==n)
            break;
        //cout<<y<<endl;
        bool ko=true;
        for(ll a=0;a<n and ko;a++)
        {
            ll ini=a,fin=(a+y)%n;
            ll b=v[ini].size(),c=v[fin].size();
            //cout<<y<<" "<<ini<<" "<<fin<<" "<<b<<" "<<c<<endl;
            if(b!=c)
            {
                ko=false;
                break;
            }
            for(ll p=0;p<b;p++)
            {
                //cout<<y<<" "<<v[ini][p]<<" "<<v[fin][p]<<" "<<ini<<" "<<fin<<endl;
                if(v[ini][p]-ini!=v[fin][p]-fin)
                {
                    ko=false;
                    break;
                }
            }
        }
        flag=(flag | ko);
        if(flag){
            break;
        }
    }
    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";
	return 0;
}
