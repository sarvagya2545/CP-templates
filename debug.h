#include<bits/stdc++.h>
using namespace std;

class Debug {
public:
    static void __print(int x) {cerr << x;}
    static void __print(long x) {cerr << x;}
    static void __print(long long x) {cerr << x;}
    static void __print(unsigned long long x) {cerr << x;}
    static void __print(float x) {cerr << x;}
    static void __print(double x) {cerr << x;}
    static void __print(long double x) {cerr << x;}
    static void __print(char x) {cerr << "\'" << x << "\'";}
    static void __print(string x) {cerr << "\"" << x << "\"";}
    static void __print(bool x) {cerr << x;}

    template<class T, class U>
    static void __print(pair<T, U> x) {
        cerr << "("; __print(x.first); cerr << ", "; __print(x.second); cerr << ")";
    }

    // For iterables
    template<typename T> 
    static void __print(const T &x) {
        int f = 0;
        cerr << "[ ";
        for (auto &i: x) 
            cerr << (f++ ? ", " : ""), __print(i); 
        cerr << " ]";
    }
    
    // For multiple debug statements
    template<typename T, typename... V> 
    static void __recursive_print(T t, V... v) {
        __print(t);
        if(sizeof...(v)) {
            cerr << ", ";
            __recursive_print(v...);
        }
    }
    
    // Need to define this function else compiler throws an error
    static void __recursive_print(){}

    // Actual debug statement called
    template<typename... Args>
    static void debug(const int line_number, const char* variable_names, const Args&... args) {
        cerr << line_number << ": ";
        if constexpr (sizeof...(args) == 1) {
            cerr << variable_names << " => ";
            __recursive_print(args...);
        } else {
            cerr << "[" << variable_names << "] => [ ";
            __recursive_print(args...);
            cerr << " ]";
        }

        cerr << "\n";
    }
};


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define ff first
#define ss second

class OldPrint {
public:
    static void __print(int x) {cerr << x;}
    static void __print(long x) {cerr << x;}
    static void __print(ll x) {cerr << x;}
    static void __print(ull x) {cerr << x;}
    static void __print(float x) {cerr << x;}
    static void __print(double x) {cerr << x;}
    static void __print(ld x) {cerr << x;}
    static void __print(char x) {cerr << x;}
    static void __print(string x) {cerr << x;}
    static void __print(bool x) {cerr << x;}
    template<class T> static void __print(vector<T> x) {cerr << "[ "; for(T i: x) {__print(i); cerr << " "; } cerr << " ]";}
    template<class T> static void __print(set<T> x) {cerr << "[ "; for(T i: x) { __print(i); cerr << " "; } cerr << "]";}
    template<class T, class U> static void __print(pair<T, U> x) {cerr << "{ "; __print(x.ff); cerr << ", "; __print(x.ss); cerr << " }";}
    template<class T, class V> static void __print(map<T, V> v) {cerr << "[ "; for (auto i : v) {__print(i); cerr << " ";} cerr << "]";}
    template<class T, class V> static void __print(unordered_map<T, V> v) {cerr << "[ "; for (auto i : v) {__print(i); cerr << " ";} cerr << "]";}
};
