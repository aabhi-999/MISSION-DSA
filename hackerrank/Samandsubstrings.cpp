#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'substrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING n as parameter.
 */

long substrings(string s) {
    long total = 0, endRight = 0, mod = 1000000007;
    for (int i=0; i < s.size(); i++) {
        int k = s[i] - '0';
        endRight = (10*endRight + (i+1)*k) % mod;
        total = (total + endRight) % mod;
    }
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
