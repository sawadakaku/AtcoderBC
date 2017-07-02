#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;

long long mod = 1e9+7;

long long bikkuri(int n) {
    if (n == 0) {
        return 1;
    } else {
        return (static_cast<long long>(n)*bikkuri(n-1));
    }
}

long long C(int n, int m) {
    if (n < m || n <= 0) {
        return 0;
    }
    long long tmp = 1;
    long long tmp2 = 1;
    for (int i = 0; i < min(n-m, m); i++) {
        tmp = (tmp * n);
        n--;
        tmp2 = (tmp2*(i+1));
    }
    return (tmp/tmp2)%mod;
}

void solve(int n, vector<int> a) {
    vector<int> used(n, 0);
    int k, m;
    for (int i = 0; i < n+1; i++) {
        if (used[a[i]] != 0) {
            k = i - used[a[i]];
            break;
        }
        used[a[i]] = i+1;
    }
    m = n - k - 1;
    std::cout << n << std::endl;
    for (int i = 2; i < n; i++) {
        int ret = 0;
        ret = (static_cast<long long>(ret) + C(n-1, i))%mod;
        ret = (static_cast<long long>(ret) + C(n-1, i-2))%mod;
        ret = (static_cast<long long>(ret) + 2*(C(n-1, i-1) - C(m, i-1)) + C(m, i-1))%mod;
        std::cout << ret << std::endl;
    }
    if (n > 1) {
        std::cout << n+1 << std::endl;
    }
    std::cout << 1 << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int n;

    gettimeofday(&start,NULL);

    std::cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    solve(n, a);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
