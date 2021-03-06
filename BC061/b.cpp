#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

void solve(int n, int m, vector< pair<int,int> > gr) {
    vector<int> ans(n,0);
    for (int i = 0; i < m; i++) {
        ans[gr[i].first-1] += 1;
        ans[gr[i].second-1] += 1;
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    int n,m;

    gettimeofday(&start,NULL);

    std::cin >> n >> m;
    vector< pair<int,int> > gr(m);
    for (int i = 0; i < m; i++) {
        std::cin >> gr[i].first >> gr[i].second;
    }
    solve(n,m,gr);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
