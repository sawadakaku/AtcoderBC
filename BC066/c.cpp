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
#include <list>

using namespace std;

void solve(int n, vector<int> a) {
    list<int> ret;
    bool flag = true;
    if (n%2 == 0) {
        flag = !flag;
    }
    for (int i = 0; i < n; i++) {
        if (flag) {
            ret.push_front(a[i]);
        } else {
            ret.push_back(a[i]);
        }
        flag = !flag;
    }
    for (int i = 0; i < n-1; i++) {
        std::cout << ret.front() << " ";
        ret.pop_front();
    }
    std::cout << ret.front() << std::endl;
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
