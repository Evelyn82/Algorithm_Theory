#include <iostream>
#include <vector>

using namespace std;

vector<long long> fw;

long long sum(int pos) {

	long long ret = 0;
	while (pos > 0) {
		ret += fw[pos];
		pos -= (pos & -pos);
		// pos &= (pos - 1);
	}
	return ret;
}

void update(int pos, long long diff) {
	
	while (pos < fw.size()) {
		fw[pos] += diff;
		pos += (pos & -pos);
	}
}
