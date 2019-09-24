/// author: Mr.Hakimov

#include <bits/stdc++.h>
#include <chrono>

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);

/* Just some advices:
1. If I use set/multiset, I will check it - is it correct to use set/multiset in a problem?
2. If I can't solve problem, I must write a program, which could help me to understand it much more better)
...
*/

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef long long LL;
typedef long double LD;

int TN = 1;

void solve() {
    int n, m;
    cin >> n >> m;
    deque < int > A;
    for (int i = 0; i < n; i++) {
        int a_i;
        cin >> a_i;
        A.push_back(a_i);
    }
    deque < int > mainA = A;
    for (int i = 0; i < m; i++) {
        LL m_j;
        cin >> m_j;
        for (int j = 0; j < m_j - 1; j++) {
            int a = A.front();
            A.pop_front();
            int b = A.front();
            A.pop_front();
            if (b > a) {
                swap(a, b);
            }
            A.push_front(a);
            A.push_back(b);
        }
        int a = A.front();
        A.pop_front();
        int b = A.front();
        A.pop_front();
        A.push_front(b);
        A.push_front(a);
        cout << a << " " << b << endl;
        A = mainA;
    }
}

int main() {
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    /// =========================================
    /// fin("input.txt"); fout("output.txt");
    /// fin("file.in"); fout("file.out");
    /// cin >> TN;
    /// =========================================
    while (TN--) solve();
    auto finish = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(finish - start);
    cerr << endl << "Time: " << elapsed_ms.count() << " ms\n";
    return 0;
}