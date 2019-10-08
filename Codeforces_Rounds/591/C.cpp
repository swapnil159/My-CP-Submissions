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
 
    T
    {
        ll n;
        cin>>n;
        ll x[n];
        for(ll a=0;a<n;a++)
            cin>>x[a];
        sort(x,x+n,greater<ll>());
        ll pre[n];
        for(ll a=0;a<n;a++)
        {
            pre[a]=x[a];
            if(a)
                pre[a]+=pre[a-1];
        }
 
        ll X,A,Y,B;
        cin>>X>>A>>Y>>B;
        if(X<Y)
        {
            swap(X,Y);
            swap(A,B);
        }
 
        ll lcm=(A*B)/__gcd(A,B);
        ll k;
        cin>>k;
        ll low=0,high=n;
        while(low<=high)
        {
            ll mid=(low+high)/2;
            ll xy=mid/lcm;
            ll tot=0,last=-1;
            if(xy)
            {
                tot+=(pre[xy-1]/100*1LL)*(X+Y);
                last=xy-1;
            }
            ll xx=last+(mid/A-xy);
            if(xx>=0)
            {
                ll pp=pre[xx];
                if(last!=-1)
                    pp-=pre[last];
                tot+=(pp/100*1LL)*X;
                last=xx;
            }
            ll yy=last+(mid/B-xy);
            if(yy>=0)
            {
                ll pp=pre[yy];
                if(last!=-1)
                    pp-=pre[last];
                tot+=(pp/100*1LL)*Y;
                last=yy;
            }
            if(tot<k)
                low=mid+1;
            else
                high=mid-1;
        }
        if(low==n+1)
            cout<<-1<<endl;
        else
            cout<<low<<endl;
 
    }
	return 0;
}
