#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		sort(arr.begin(), arr.end());
		int ans = INT_MAX;
		for(int i = 1;i < n;i++)ans = min(ans, arr[i] - arr[i - 1]);
		cout << ans << endl;
	}
}
