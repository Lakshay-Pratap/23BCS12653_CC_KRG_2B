#include <bits/stdc++.h>
using namespace std;

vector<int> rabinKarp(string text, string pattern, int q = 101) {

    int d = 256;
    int n = text.length();
    int m = pattern.length();
    vector<int> result;

    if (m > n) return result;

    int h = 1;
    for (int i = 1; i < m; i++) {
        h = (h * d) % q;
    }

    int p = 0;
    int t = 0;
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(i);
            }
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }

    return result;
}

int main() {
    string text = "ABCAB";
    string pattern = "AB";

    vector<int> positions = rabinKarp(text, pattern);

    cout << "Pattern found at positions: ";
    for (int pos : positions) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}