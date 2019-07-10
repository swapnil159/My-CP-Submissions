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
        ll m;
        cin>>m;
        if(m==0)
        {
            cout<<"1 1"<<endl;
            continue;
        }
        ll k1=-1,k2=-1;
        for(ll n=2;n<100000 and k1==-1;n++)
        {
            ll low=2,high=n;
            while(low<=high)
            {
                ll mid=(low+high)/2;
                ll po=n*n-(n/mid)*(n/mid);
                if(po==m)
                {
                    k1=n,k2=mid;
                    break;
                }
                if(po>m)
                    high=mid-1;
                else
                    low=mid+1;
            }
        }
        if(k1==-1)
            cout<<-1<<endl;
        else
            cout<<k1<<" "<<k2<<endl;
    }
	return 0;
}
