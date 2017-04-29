#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

void solve(string a, string b, string c) {
    if (a.back() == b.front()) {
        if (b.back() == c.front()) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    string a,b,c;
    gettimeofday(&start,NULL);
    std::cin >> a >> b >> c;
    solve(a, b, c);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
