#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int ans = 0;
	for(int i = 1;i < n;i++){
		if((n - i) % i == 0)ans++;
	}
	cout << ans;
}
