#include <iostream>
#include <vector> 
using namespace std;
vector<double> maxheap({0}), minheap({0});
inline void insert_update() {
	int i = maxheap.size()-1, j = minheap.size()-1;
	while ( i != 1 && maxheap[i] > maxheap[i/2] ) {
		swap(maxheap[i],maxheap[i/2]);
		i /= 2;
	}
	while ( j != 1 && minheap[j] < minheap[j/2] ) {
		swap(minheap[j],minheap[j/2]);
		j /= 2;
	}
}
inline void del_max() {
	maxheap[1] = maxheap.back();
	maxheap.pop_back();
	int i = 1;
	while ( 1 ) {
		if ( ((i*2 < maxheap.size() && maxheap[i] >= maxheap[i*2]) 
				|| i*2 >= maxheap.size())
		  && ((i*2+1 < maxheap.size() && maxheap[i] >= maxheap[i*2+1]) 
				|| i*2+1 >= maxheap.size()) )
			   break;
		if ( maxheap[i] < maxheap[i*2] ) {
			if ( i*2+1 < maxheap.size() && maxheap[i] < maxheap[i*2+1] ) {
				if ( maxheap[i*2] >= maxheap[i*2+1] ) {
					swap(maxheap[i],maxheap[i*2]);
					i *= 2;
				} else {
					swap(maxheap[i],maxheap[i*2+1]);
					i = i*2+1;
				}
			} else {
				swap(maxheap[i],maxheap[i*2]);
				i *= 2;
			}
		}
		else if ( i*2+1 < maxheap.size() && maxheap[i] < maxheap[i*2+1] ) {
			swap(maxheap[i],maxheap[i*2+1]);
			i = i*2+1;
		}
	}
}
inline void del_min() {
	minheap[1] = minheap.back();
	minheap.pop_back();
	int i = 1;
	while ( 1 ) {
		if ( ((i*2 < minheap.size() && minheap[i] <= minheap[i*2]) 
				|| i*2 >= minheap.size())
		  && ((i*2+1 < minheap.size() && minheap[i] <= minheap[i*2+1]) 
				|| i*2+1 >= minheap.size()) )
			   break;
		if ( minheap[i] > minheap[i*2] ) {
			if ( i*2+1 < minheap.size() && minheap[i] > minheap[i*2+1] ) {
				if ( minheap[i*2] <= minheap[i*2+1] ) {
					swap(minheap[i],minheap[i*2]);
					i *= 2;
				} else {
					swap(minheap[i],minheap[i*2+1]);
					i = i*2+1;
				}
			} else {
				swap(minheap[i],minheap[i*2]);
				i *= 2;
			}
		}
		else if ( i*2+1 < minheap.size() && minheap[i] > minheap[i*2+1] ) {
			swap(minheap[i],minheap[i*2+1]);
			i = i*2+1;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double n, x;
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		cin >> x;
		if ( maxheap.size() == 1 || maxheap[1] > x )
			maxheap.emplace_back(x);
		else
			minheap.emplace_back(x);
		insert_update();
		if ( i%2 == 0 ) {
			if ( maxheap.size() > minheap.size() ) {
				minheap.emplace_back(maxheap[1]);
				del_max();
			} else if ( maxheap.size() < minheap.size() ) {
				maxheap.emplace_back(minheap[1]);
				del_min();
			}
			insert_update();
			printf("%.6lf\n", (minheap[1]+maxheap[1])/2);
		} else if ( maxheap.size() < minheap.size() )
			printf("%.6lf\n", minheap[1]);
		else
			printf("%.6lf\n", maxheap[1]);
	}
	return 0;
}
