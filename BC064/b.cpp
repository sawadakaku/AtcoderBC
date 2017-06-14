#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

void solve(vector<int> coo) {
    int maxcoo = *max_element(coo.begin(), coo.end());
    int mincoo = *min_element(coo.begin(), coo.end());
    std::cout << maxcoo - mincoo << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int t;

    gettimeofday(&start,NULL);

    std::cin >> t;
    vector<int> coo(t);
    for (int i = 0; i < t; i++) {
        std::cin >> coo[i];
    }
    solve(coo);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
