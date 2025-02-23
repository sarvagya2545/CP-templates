/**
 * Function to calculate GCD of 2 integers
 * Time complexity: O(log(max(a,b)));
 * Space complexity: O(1)
 * Principle: GCD(a,b) = GCD(a, b - a) (Given that a < b of course)
 * So GCD(a,b) = GCD(a, b % a) = GCD(b%a, a)
 * */
// Not required to write, use __gcd in c++
int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}


template<typename T>
T pow(T a, T exp) {
    if(exp == 1) return a;
    if(exp == 0) return 1;

    if(exp % 2 == 0) {
        return pow(a * a, exp / 2);
    } else {
        return a * pow(a, exp - 1);
    }
}

// MOD INVERSE
int extended_euclidean_gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int modInv(int a, int m) {
    int x, y;
    int g = extended_euclidean_gcd(a, m, x, y);
    if (g != 1) {
        return -1;
    }
    else {
        x = (x % m + m) % m;
        return x;
    }
}
