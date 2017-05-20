#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

void solve(int h, int w, vector<string> pixels) {
    for (int i = 0; i < w+2; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;
    for (int i = 0; i < h; i++) {
        std::cout << "#" << pixels[i] << "#" << std::endl;
    }
    for (int i = 0; i < w+2; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int h,w;

    gettimeofday(&start,NULL);

    std::cin >> h >> w;
    vector<string> pixels(h);
    for (int i = 0; i < h; i++) {
        std::cin >> pixels[i];
    }
    solve(h,w,pixels);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
