#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c;cin >> a >> b >> c;
	cout << min((a + b + c) / 3, min(a + b, min(a + c, b + c)));
}
