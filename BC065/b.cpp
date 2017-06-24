#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>

using namespace std;

void solve(int n, vector<int> button) {
    vector<bool> flag(n, false);
    int i = 0;
    int ans = 0;
    bool aval = false;
    while (!flag[i]) {
        flag[i] = true;
        i = button[i]-1;
        ans++;
        if (i == 1) {
            aval = true;
            break;
        }
    }
    if (aval) {
        std::cout << ans << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    int n;

    gettimeofday(&start,NULL);

    std::cin >> n;
    vector<int> button(n);
    for (int i = 0; i < n; i++) {
        std::cin >> button[i];
    }
    solve(n, button);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
