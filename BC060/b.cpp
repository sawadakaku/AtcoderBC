#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

void solve(int a, int b, int c) {
    int s,t;
    s = b;
    t = a;
    while (!(s==0)) {
        int tmp = t%s;
        t = s;
        s = tmp;
    }
    if (c%t == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    int a,b,c;

    gettimeofday(&start,NULL);

    std::cin >> a >> b >> c;
    solve(a, b, c);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
