#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  while(t--){
    ll n;cin >> n;
    ll ans = 0;
    vector<ll> arr(n), cnt(n + 10);
    for(ll i = 0;i < n;i++)cin >> arr[i];
    for(ll i = 0;i < n;i++){
      ll tmp = cnt[i];
      if(tmp < arr[i] - 1){
        ans += arr[i] - 1 - tmp;
        tmp += arr[i] - 1 - tmp;
      }
      cnt[i + 1] += tmp - arr[i] + 1;
      if(i + 2 < n){
        for(ll j = i + 2;j < min(n, i + arr[i] + 1);j++)
          cnt[j]++;
      }
    }
    cout << ans << endl;
  }
}
