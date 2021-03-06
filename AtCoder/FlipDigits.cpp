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

  ll n;cin >> n;
  string s, t;cin >> s >> t;
  queue<ll> q;
  ll ans = 0;
  for(ll i = 0;i < n;i++){
    if(s[i] == '1' && t[i] == '1'){
      if(!q.empty()){
        ans += i - q.front();
        q.pop();
        q.push(i);
      }
    }
    else if(s[i] == '1' && t[i] == '0'){
      if(!q.empty()){
        ans += i - q.front();
        q.pop();
      }
      else q.push(i);
    }
    else if(s[i] == '0' && t[i] == '1'){
      q.push(i);
    }
  }
  if(!q.empty())cout << -1;
  else cout << ans;
  cout << endl;
}
