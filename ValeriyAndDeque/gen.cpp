#include "testlib.h"
#include <string>
#include <iostream>

#define LL long long

using namespace std;

void printIntVector(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            printf("%d ", v[i]);
        } else {
            printf("%d\n", v[i]);
        }
    }
}

void printLongVector(vector<LL> &v) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		printf("%lld\n", v[i]);
	}
}

const int maxX = 1000 * 1000 * 1000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int tl = atoi(argv[1]);
    int tr = atoi(argv[2]);
    int nl = atoi(argv[3]);
    int nr = atoi(argv[4]);
	int ql = atoi(argv[5]);
	int qr = atoi(argv[6]);
	LL ml = atoll(argv[7]);
	LL mr = atoll(argv[8]);
	int vl = atoi(argv[9]);
	int vr = atoi(argv[10]);
	for (int i = tl; i <= tr; i++) {
	    startTest(i);
        int n = rnd.next(nl, nr);
    	int q = rnd.next(ql, qr);
        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            arr[j] = rnd.next(vl, vr);
        }
    	vector<LL> queries(q);
    	for (int j = 0; j < q; j++) {
    		queries[j] = (rnd.next(1, maxX) * 1ll * rnd.next(1, maxX)) % (mr - ml + 1) + ml;
    	}
    	printf("%d %d\n", n, q);
        printIntVector(arr);
    	printLongVector(queries);
	}
}