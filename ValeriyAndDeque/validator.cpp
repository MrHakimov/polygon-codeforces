#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
	const int N = 100000;
	const int M = 3 * N;
	const long long int MAXVALUE = 1000 * 1000 * 1000;
	const long long int MAXQUERY = MAXVALUE * MAXVALUE;
	
	int n = inf.readInt(2, N, "n");
	inf.readSpace();
	int q = inf.readInt(0, M, "q");
	inf.readEoln();

	for(int i = 0; i < n; i++) {
		inf.readLong(0, MAXVALUE, "a_i");
		if (i < n - 1) {
			inf.readSpace();
		}
	}
	inf.readEoln();

	for (int i = 0; i < q; i++) {
		inf.readLong(1, MAXQUERY, "m_j");
		inf.readEoln();
	}
    inf.readEof();
}