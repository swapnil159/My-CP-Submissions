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
ll n,m;
ll row[26],col[26],type[26],maxr[26],maxc[26];
void initialize(string s[])
{
    for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<m;b++)
        {
            if(s[a][b]!='.')
            {
                ll p=s[a][b]-'a';
                if(row[p]==-1 and col[p]==-1)
                    row[p]=a,col[p]=b;
            }
        }
    }
}
bool check(ll ind,string s[])
{
    if(row[ind]==-1 or col[ind]==-1)
        return true;
    ll ro=0,coll=0,po=0;
    for(ll a=0;a<n;a++)
    {
        for(ll b=0;b<m;b++)
        {
            if(s[a][b]-'a'==ind)
            {
                maxr[ind]=max(maxr[ind],a);
                maxc[ind]=max(maxc[ind],b);
                if(a==row[ind])
                    ro++;
                if(b==col[ind])
                    coll++;
                if(a!=row[ind] and b!=col[ind])
                    po=1;
            }
        }
    }
    if(po==1 or (coll>1 and ro>1))
        return false;
    if(coll==1)
        type[ind]=1;
    else
        type[ind]=0;
    return true;
}
bool double_checkh(string s[],ll ind)
{
    ll r=row[ind],c1=col[ind],c2=maxc[ind];
    for(ll a=c1;a<=c2;a++)
        if(s[r][a]=='.' or s[r][a]-'a'<ind)
            return false;
    return true;
}

bool double_checkv(string s[],ll ind)
{
    ll c=col[ind],r1=row[ind],r2=maxr[ind];
    for(ll a=r1;a<=r2;a++)
        if(s[a][c]=='.' or s[a][c]-'a'<ind)
            return false;
    return true;
} 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    T
    {
        cin>>n>>m;
        string s[n];
        for(ll a=0;a<n;a++)
            cin>>s[a];
        for(ll a=0;a<26;a++)
            row[a]=-1,col[a]=-1,type[a]=-1,maxr[a]=-1,maxc[a]=-1;
        initialize(s);
        bool flag=true;
        for(ll a=0;a<26;a++)
            flag=(flag & check(a,s));
        for(ll a=0;a<26;a++)
        {
            if(type[a]==1)
                flag=(flag & double_checkh(s,a));
            else if(type[a]==0)
                flag=(flag & double_checkv(s,a));
        }
        if(!flag)
        {
            cout<<"NO\n";
            continue;
        }
        flag=false;
        vc<pair<pll,pll>> ans;
        for(ll a=25;a>=0;a--)
        {
            if(type[a]==-1)
            {
                if(flag)
                {
                    ans.pb(ans[ans.size()-1]);
                }
                continue;
            }
            flag=true;
            if(type[a]==1)
            {
                ans.pb({{row[a]+1,col[a]+1},{row[a]+1,maxc[a]+1}});
            }
            else
            {
                ans.pb({{row[a]+1,col[a]+1},{maxr[a]+1,col[a]+1}});
            }
        }
        cout<<"YES\n";
        cout<<ans.size()<<endl;
        reverse(all(ans));
        for(auto y:ans)
        {
            cout<<y.fs.fs<<" "<<y.fs.sec<<" "<<y.sec.fs<<" "<<y.sec.sec<<endl;
        }
    }
	return 0;
}
