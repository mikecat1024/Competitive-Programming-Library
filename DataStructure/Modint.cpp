#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;



struct Modint {
    long long x;
    Modint(long long x = 0) : x(((x%mod)+mod)%mod) {}

    Modint modpow(const Modint& m, long long n){
        if(n == 0) return 1;
        Modint ret = modpow(m,n/2);
        ret *= ret;
        if(n & 1) ret *= m;
        return ret;
    }
    Modint inv(const Modint& right){ Modint ret(right); return modpow(ret, mod-2); }

    Modint operator-() const { return Modint(-x); }
    Modint& operator+=(const Modint& right){ if((x += right.x) >= mod) x -= mod; return *this; }
    Modint& operator-=(const Modint& right){ if((x += mod-right.x) >= mod) x -= mod; return *this; }
    Modint& operator*=(const Modint& right){ (x *= right.x) %= mod; return *this; }
    Modint& operator/=(const Modint& right){ return *this *= inv(right); }

    Modint operator+(const Modint& right) const { Modint ret(*this); return ret += right; }
    Modint operator-(const Modint& right) const { Modint ret(*this); return ret -= right; }
    Modint operator*(const Modint& right) const { Modint ret(*this); return ret *= right; }
    Modint operator/(const Modint& right) const { Modint ret(*this); return ret /= right; }

    friend ostream& operator<<(ostream& os, const Modint& ans){ os << ans.x; return os; } 
};



int main (){
    return 0;
}