#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>

using namespace std;

void solve(int x, int a, int b) {
    if (b <= a) {
        std::cout << "delicious" << std::endl;
    } else if(b <= a+x){
        std::cout << "safe" << std::endl;
    } else {
        std::cout << "dangerous" << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    int x, a, b;

    gettimeofday(&start,NULL);

    std::cin >> x >> a >> b;
    solve(x, a, b);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
