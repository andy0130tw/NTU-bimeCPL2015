//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-10-22
//  FILENAME    : HW03A002.CPP
//  DESCRIPTION : Calculate PI using Leibniz series
//================================================================

#include "stdafx.h"
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;

int main(int argc, _TCHAR* argv[]) {
    // inaccurate after saved as       11...
    const double PI = 3.141592653589793238463;

    // specify precision
    cout << setprecision(15);

    // print the accurate PI (in double) for comparing
    // note the spaces inserted here is for aligning with the result
    cout << setw(20) << right << "ACCURATE PI = "
         << setw(16) << PI
         << endl;

    double s = 0;
    for (int k = 0; k <= 1e8; k++) {
        // 1-(k%2)*2 -- to apply negative sign if k % 2 == 1
        s += 4 * (1.0 - (k % 2) * 2) / (2 * k + 1);
        if (k == 1e3 || k == 1e4 || k == 1e5 || k == 1e6 || k == 1e7 || k == 1e8) {
            cout << "k = "     << setw(9) << k
                 << ", pi = "  << setw(16) << s
                 << ", err = " << setw(16) << fixed << (s - PI)
                 << endl;
            // clear fixed flag
            // ref: http://stackoverflow.com/a/12094984/2281355
	        cout.unsetf(ios_base::fixed);

    	    if (k == 1e5) {
                // print a separator
	            cout << "------" << endl;
	        }
        }
    }
    system("pause");
}

