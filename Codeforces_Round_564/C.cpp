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
    ll n;
    cin>>n;
    ll x[n],y[n],cnt=0;
    for(ll a=0;a<n;a++)
    {
        cin>>x[a];
        if(x[a])
            cnt++;
    }
    ll pos=-1,po=0;
    for(ll a=0;a<n;a++)
    {
        cin>>y[a];
        if(y[a]==1)
            pos=a;
    }
    while(pos>=0 and pos<n and y[pos]==po+1)
        po++,pos++;
    if(pos!=n)
        po=0;
    if(po+cnt==n)
        cout<<cnt<<endl;
    else
    {
        pos-=po;
        bool flag=false;
        if(pos>=0 and po)
        {
            for(ll a=0;a<pos;a++)
            {
                if(y[a] and (y[a]-po<=a+1 or y[a]-po==1))
                    flag=true;
            }
        }
        if(not flag and po)
        {
            cout<<n-po<<endl;
            exit(0);
        }
        ll p=n;
        for(ll a=0;a<n;a++)
        {
            if(y[a])
            {
                p=max(n+a+2-y[a],p);
            }
        }
        cout<<p<<endl;
    }
    
	return 0;
}
