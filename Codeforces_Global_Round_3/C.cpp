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

ll n,m,ta,tb,k;
vc<pll> v,v1;
set<ll> s;
ll find(ll ind1,ll ind2)
{
      if(ind1<=n/2 and ind2<=n/2)
      {
            ll po=ind2+n/2;
            v.pb({ind2,po});
            v.pb({ind1,po});
            v.pb({ind2,po});
      }
      else if(ind1>n/2 and ind2>n/2)
      {
            ll po=ind1-n/2;
            v.pb({ind2,po});
            v.pb({ind1,po});
            v.pb({ind2,po});
      }
      else
      {
            ll po1=ind1+n/2,po2=ind2-n/2;
            v.pb({po1,ind1});
            v.pb({po2,ind2});
            v.pb({po1,po2});
            v.pb({po1,ind1});
            v.pb({po2,ind2});
      }
      
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    
      cin>>n;
      ll x[n+1];
      for(ll a=1;a<=n;a++)
            cin>>x[a];
      while(1)
      {
            bool flag=false;
            for(ll a=1;a<=n;a++)
            {
                  if(x[a]!=a)
                  {
                        flag=true;
                        //cout<<a<<" "<<x[a]<<endl;
                        if(llabs(x[a]-a)>=n/2)
                        {
                              ll ind1=x[a],ind2=a;
                              v.pb({x[a],a});
                              swap(x[ind1],x[ind2]);
                        }
                        else
                        {
                              ll ind1=x[a],ind2=a;
                              if(ind1>ind2)
                                    swap(ind1,ind2);
                              find(ind1,ind2);
                              swap(x[ind1],x[ind2]);
                        }
                        
                  }
            }
            if(!flag)
                  break;
      }
      cout<<v.size()<<endl;
            for(auto y:v)
                  cout<<y.fs<<" "<<y.sec<<endl;
      
	return 0;
}
