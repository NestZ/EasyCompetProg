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

  int t;cin >> t;
  while(t--){
    int n, k;cin >> n >> k;
    bool valid = true;
    vector<int> arr(n), mx(n), mn(n);
    for(int i = 0;i < n;i++)cin >> arr[i];
    mn[0] = mx[0] = arr[0];
    mn[n - 1] = mx[n - 1] = arr[n - 1];
    for(int i = 1;i < n;i++){
      if(i < n - 1){
        mn[i] = max(arr[i], mn[i - 1] + 1 - k);
        mx[i] = min(mx[i - 1] + k - 1, arr[i] + k - 1);
      }
      if(mn[i] > mx[i - 1] - 1 + k)valid = false;
      if(k + mx[i] < mn[i - 1] + 1)valid = false;
    }
    if(valid)cout << "YES";
    else cout << "NO";
    cout << endl;
  }
}
