#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[10] = {1,2,3,1,2,3,1,2,3,4}, n;
	cin >> n;
	cout << arr[(n-1)%10] << '\n';
	return 0;
}

