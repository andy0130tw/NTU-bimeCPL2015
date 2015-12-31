//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-12-17
//  FILENAME    : HW07A002.CPP
//  DESCRIPTION : Finding the longest string in a file, whose reversed one is also on a list.
//================================================================

#include<iostream>
#include<algorithm>  // std::reverse
#include<cstdlib>
#include<fstream>

#define HASH_SIZE 100007

using namespace std;

string* strHash[HASH_SIZE];
int hashEntryUsed = 0;

char lower(char x) {
    if (x >= 'A' && x <= 'Z')
        return x - 'A' + 'a';
    return x;
}

bool hashEqual(string* s1, string* s2) {
    // ignore the last character
    // compare strings case-insensitively
    if (s1->length() != s2->length())
        return false;
    for (size_t i = 0, n = s1->length() - 1; i < n; i++)
        if (lower((*s1)[i]) != lower((*s2)[i]))
            return false;
    return true;
}

unsigned hashTest(ifstream& src, size_t hashConst, string* longest, string* longest_conj) {
    char buf[1024];

    unsigned hashColl = 0;
    while (src >> buf) {
        int i = 0;
        size_t key = 0;

        for (; buf[i] != '\0'; i++)
            // calculate hash of the string
            key = (key + lower(buf[i]) * hashConst) % HASH_SIZE;

        // i is now the length of the string
        if (lower(buf[0]) > lower(buf[i - 1])) {
            reverse(buf, buf + i);
            buf[i] = 2;
        } else buf[i] = 1;
        buf[i + 1] = '\0';


        string* s = new string(buf);

        // this should NOT happen
        if (hashEntryUsed == HASH_SIZE)
            return -1;

        while (strHash[key] != 0) {
            // if the string is the same, we've found a candidate
            // otherwise use linear probing
            char c1 = (*strHash[key])[strHash[key]->length() - 1];
            char c2 = (*s)[s->length() - 1];

            if (c1 != c2 && hashEqual(strHash[key], s)) {
                if (!longest || longest->length() < s->length()) {
                    if (c1 == 1) {
                        longest = strHash[key];
                        longest_conj = s;
                    } else {
                        longest = s;
                        longest_conj = strHash[key];
                    }

                }
            }

            key = (key + 1) % HASH_SIZE;
            hashColl++;
        }
        strHash[key] = s;
        hashEntryUsed++;
    }

    // free the hash table
    for (size_t i = 0; i < HASH_SIZE; i++) {
        delete strHash[i];
        strHash[i] = 0;
    }

    hashEntryUsed = 0;

    return hashColl;
}

int main() {
    ifstream f("words.txt");
    if (!f) {
        cerr << "File `words.txt` does not exist! Exiting...";
        system("pause");
        return 1;
    }

    string* longest = 0;
    string* longest_conj = 0;

    for (size_t i = 0; i < HASH_SIZE; i++) {
        f.seekg(0);
        size_t c = hashTest(f, i, longest, longest_conj);
        f.clear();
        cout << i << "; " << c << endl;
    }

    // system("pause");
    return 0;
}