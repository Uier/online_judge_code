#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int edge[3];
	cin >> edge[0] >> edge[1] >> edge[2];
	sort(edge, edge+3);
	cout << edge[0] << ' ' << edge[1] << ' ' << edge[2] << '\n';
	if ( edge[0]+edge[1] <= edge[2] ) {
		cout << "No\n";
	} else if ( edge[0]*edge[0]+edge[1]*edge[1] < edge[2]*edge[2] ) {
		cout << "Obtuse\n";
	} else if ( edge[0]*edge[0]+edge[1]*edge[1] == edge[2]*edge[2] ) {
		cout << "Right\n";
	} else {
		cout << "Acute\n";
	}
	return 0;
}

