#include<bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()

#ifndef ONLINE_JUDGE
    #include "debug.h"
    #define debug(x...) Debug::debug(__LINE__, #x, x);
#else
    #define debug(x...) 
#endif

#define int int64_t
#define uint uint64_t

// Comment out this directive if no testcases
#define TEST_CASES

void solve() {
    
}

signed main()
{
    fastio();
    cout << boolalpha;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("debug.txt", "w", stderr);
    #endif

    #ifdef TEST_CASES
        int t;
        cin >> t;
        while(t--)
            solve();
    #else
        solve();
    #endif

    return 0;
}
