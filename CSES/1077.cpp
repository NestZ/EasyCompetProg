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

vector<ll> ft_sum(200010, 0), ft_cnt(200010);

void add(ll k, ll x, vector<ll> &tree){
  while(k < 200010){
    tree[k] += x;
    k += k & -k;
  }
}

ll sum(ll k, vector<ll> &tree){
  ll res = 0;
  while(k > 0){
    res += tree[k];
    k -= k & -k;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;cin >> n >> k;
  vector<ll> arr(n);
  vector<ll> median(n);
  map<ll, ll> ind;
  for(ll i = 0;i < n;i++){
    cin >> arr[i];
    ind[arr[i]] = 0;
  }
  ll cnt = 1;
  for(auto &p : ind)p.second = cnt++;
  multiset<ll> s(arr.begin(), arr.begin() + k);
  auto ptr = next(s.begin(), (k + 1) / 2 - 1);
  median[k - 1] = *ptr;
  for(ll i = k;i < n;i++){
    s.insert(arr[i]);
    if(arr[i] < *ptr)ptr--;
    if(arr[i - k] <= *ptr)ptr++;
    s.erase(s.find(arr[i - k]));
    median[i] = *ptr;
  }
  for(ll i = 0;i < k;i++){
    add(ind[arr[i]], arr[i], ft_sum);
    add(ind[arr[i]], 1, ft_cnt);
  }
  for(ll i = k - 1;i < n;i++){
    ll med = median[i];
    ll cnt_less = sum(ind[med] - 1, ft_cnt);
    ll cnt_great = sum(200000, ft_cnt) - sum(ind[med], ft_cnt);
    ll sum_less = sum(ind[med] - 1, ft_sum);
    ll sum_great = sum(200000, ft_sum) - sum(ind[med], ft_sum);
    ll less = abs(med * cnt_less - sum_less);
    ll great = abs(med * cnt_great - sum_great);
    debug() << imie(i) imie(cnt_less) imie(cnt_great);
    debug() << imie(sum_less) imie(sum_great);
    cout << less + great << ' ';
    if(i < n - 1){
      add(ind[arr[i + 1]], 1, ft_cnt);
      add(ind[arr[i + 1]], arr[i + 1], ft_sum);
      add(ind[arr[i - k + 1]], -1, ft_cnt);
      add(ind[arr[i - k + 1]], -arr[i - k + 1], ft_sum);
    }
  }
  cout << endl;
}
