//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-12-25
//  FILENAME    : HW07C002.CPP
//  DESCRIPTION : A sudoku solver.
//================================================================

#include<iostream>
#include<algorithm>

using namespace std;

#define BLOCK_NUM(i,j) ((i) / 3 * 3 + (j) / 3)

int g[9][9];
unsigned ava[9][9];
unsigned cnt[9][9];

unsigned row[9];
unsigned col[9];
unsigned blk[9];

unsigned dfsList[81], dfsLen;

void setMask(int i, int j, unsigned b) {
    row[i] |= b;
    col[j] |= b;
    blk[BLOCK_NUM(i,j)] |= b;
}

void unsetMask(int i, int j, unsigned b) {
    row[i] ^= b;
    col[j] ^= b;
    blk[BLOCK_NUM(i,j)] ^= b;
}

inline bool isLegalMask(int i, int j, unsigned b) {
    return !(row[i]&b) && !(col[j]&b) && !(blk[BLOCK_NUM(i,j)]&b);
}

bool backtrack(unsigned depth) {
    if (depth == dfsLen)
        return true;

    unsigned i = dfsList[depth] / 9;
    unsigned j = dfsList[depth] % 9;

    int k = 1;
    unsigned a = ava[i][j] >> 1;

    while (a > 0) {
        if (a & 1) {
            // fill in k
            unsigned b = 1 << k;
            if (isLegalMask(i, j, b)) {
                g[i][j] = k;
                setMask(i, j, b);
                if (backtrack(depth + 1)) return true;
                // undo
                unsetMask(i, j, b);
            }
        }
        k++;
        a >>= 1;
    }
    return false;
}

bool inputEntry(int i, int j) {
    cin >> g[i][j];
    if (g[i][j] < 0 || g[i][j] > 9) return false;

    if (!g[i][j]) {
        return true;
    }

    unsigned bit = (1 << g[i][j]);
    if (!isLegalMask(i, j, bit)) return false;
    setMask(i, j, bit);
    return true;
}

int main() {

    // read in and validate a sudoku puzzle from stdin
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            if (!inputEntry(i, j)) {
                cout << "Illegal entry (" << g[i][j] << ") for row #" << (i+1) << " col #" << (j+1) << "!!" << endl;
                return 1;
            }
        }

    cout << "Puzzle: " << endl;

    // generate the table of possible entries
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // print out original puzzle
            if (g[i][j])
                cout << g[i][j];
            else
                cout << "_";
            cout << " ";

            if (g[i][j]) continue;

            unsigned b = 2;
            for (int k = 1; k <= 9; k++) {
                if (isLegalMask(i, j, b)) {
                    // cout << k << " ";
                    ava[i][j] |= b;
                    cnt[i][j] += 1;
                }
                b <<= 1;
            }

            // categorize blanks by the number of possible values
            // not knowing if vector is allowed... pack them into an array
            dfsList[dfsLen++] = i * 9 + j;
        }
        cout << endl;
    }
    cout << endl;

    cout << "Solving..." << flush;

    bool result = backtrack(0);
    if (result) {
        cout << "\rResult: SOLVED" << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "\rResult: NO SOLUTION" << endl;
        cout << "Sorry :(" << endl;
    }
    cin.get();

}
