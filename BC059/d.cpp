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

void solve(long long x, long long y) {
    long long diff = abs(x-y);
    if (diff < 2) {
        std::cout << "Brown" << std::endl;
    } else {
        std::cout << "Alice" << std::endl;
    }

}

int main() {
    struct timeval start,end;
    long long span;
    long long x, y;

    gettimeofday(&start,NULL);

    std::cin >> x >> y;
    solve(x, y);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
