#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

void solve(int r, int g, int b) {
    int num = 100*r + 10*g + b;
    if (num%4 == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    int r, g, b;

    gettimeofday(&start,NULL);

    std::cin >> r >> g >> b;
    solve(r, g, b);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
