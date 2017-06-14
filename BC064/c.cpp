#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

void solve(int n, vector<int> a) {
    vector<bool> flag(8, false);
    int target = 0;
    int rating[] = {0, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200};
    for (int i = 0; i < n; i++) {
        if (a[i] >= rating[8]) {
            target += 1;
            continue;
        }
        for (int j = 0; j < 8; j++) {
            if (a[i] >= rating[j] && a[i] < rating[j+1]) {
                flag[j] = true;
                break;
            }
        }
    }
    int maxcolor = 0;
    int mincolor = 0;
    for (int i = 0; i < 8; i++) {
        if (flag[i] == true) {
            maxcolor += 1;
            mincolor += 1;
        }
    }
    if (target > 0) {
        maxcolor += target;
        if (mincolor == 0) {
            mincolor = 1;
        }
    }
    std::cout << mincolor << " " << maxcolor << std::endl;

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
