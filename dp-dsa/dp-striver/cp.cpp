#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long

#define p_b push_back
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
const int mod = 1'000'000'007;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pl;
typedef vector<int>     vi;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef vector<vl>      vvl;

void input_arr(int arr[], int n) {
    for(int i = 0; i < n; i++) cin>>arr[i];
}
void print_arr(int arr[], int n) {
    for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
    cout << "\n";
}
void print_vec(vector<int> v) {
    int n = v.size();
    for(int i = 0; i < n; i++) cout<<v[i]<<" ";
    cout << "\n";
}


void solve(){
     
    // int a;
    // long long int b;
    // char c;
    // float d;
    // double e;
       

    // cin>>a>>b>>c>>d>>e;
    // cout<< a<<'\n'<< b<<'\n'<< c<<'\n'<< d<<'\n'<< e<<'\n'<<endl;
    

//  scanf("%d %lld %c %f %lf",&a,&b,&c,&d,&e);

//  printf("%d\n%lld\n%c\n%f\n%lf",a,b,c,d,e);

// ll a,b,c,d;

// cin>>a>>b>>c>>d;
// cout<<"Difference = "<<(a*b)-(c*d)<<endl;
// cout << fixed << setprecision(9);
// double a;
// cin>>a;
// cout<<(3.141592653*a*a);

// ll a,b;
// cin>>a>>b;

//  a=a%10;
//  b=b%10;
// cout<<a+b;
ll n ;
cin>>n;
vector<ll> dp(n+1);
dp[0]=0;
for(int i =1;i<=n;i++){
    dp[n]=dp[0]+dp[i];
}
cout<<dp[n];



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin>>tc;
    
    solve();
    return 0;
}