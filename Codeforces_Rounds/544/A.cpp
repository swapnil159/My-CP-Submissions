/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
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
    string s1,s2;
    cin>>s1>>s2;
    ll h1=(s1[0]-'0')*10+(s1[1]-'0');
    ll h2=(s2[0]-'0')*10+(s2[1]-'0');
    ll m1=(s1[3]-'0')*10+(s1[4]-'0');
    ll m2=(s2[3]-'0')*10+(s2[4]-'0');
    ll tot=(h2-h1)*60+(m2-m1);
    tot/=2;
    ll h=tot/60;
    ll min=tot%60;
    min+=m1;
    if(min>=60)
    {
        min%=60;
        h++;
    }
    h+=h1;
    if(h<10)
        cout<<0<<h<<":";
    else
        cout<<h<<":";
    if(min<10)
        cout<<0<<min;
    else
        cout<<min;
	return 0;
}
