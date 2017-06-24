#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>

using namespace std;

long long mod = 10e8 + 7;

long long powx(long long n) {
    if (n == 1) {
        return 1LL;
    } else {
        return (n * powx(n-1))%mod;
    }
}

void solve(long long n, long long m) {
    if (n > m) {
        long long tmp = n;
        n = m;
        m = tmp;
    }
    if (n == m) {
        long long x = powx(n);
        std::cout << (((x*x)%mod)*2)%mod << std::endl;
    } else if(m-n == 1) {
        long long x = powx(n);
        std::cout << (((x*x)%mod)*m)%mod << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    long long n, m;

    gettimeofday(&start,NULL);

    std::cin >> n >> m;
    solve(n, m);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
