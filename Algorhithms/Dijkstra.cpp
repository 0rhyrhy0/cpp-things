#include <iostream>
using namespace std;

#define NUMBER 6
#define MAX 2000000000
// github.dev ????
int a[6][6] = {
	{0,   2,   5,   1,   MAX, MAX},
	{2,   0,   3,   2,   MAX, MAX},
	{5,   3,   0,   3,   1,   5  },
	{1,   2,   3,   0,   1,   MAX},
	{MAX, MAX, 1,   1,   0,   2  },
	{MAX, MAX, 5,   MAX, 2,   0  }
};
bool v[6]; // visited or not
int d[6];  // distance

int getSmallIndex() {
	int min = MAX;
	int index = 0;
	for(int i=0 ; i < NUMBER ; i++) {
		if(d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for(int i=0 ; i < NUMBER ; i++) {
		d[i] = a[start][i];
	}
	v[start] = true;
	for(int i=0 ; i < NUMBER - 2 ; i++) {
		int current = getSmallIndex();
		v[current] = true;
		for(int j=0 ; j < 6 ; j++) {
			if(!v[j]) {
				if(d[current] + a[current][i] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main() {
	dijkstra(0);
	for(int i=0 ; i<NUMBER ; i++)
		cout << d[i] << ' ';
}
