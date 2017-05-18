#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

const long long INF = 1LL << 50;

void solve(int n, int m, vector< vector<int> > gr) {
    vector<long long> dist(n, INF);
    dist[0] = 0;
    for (int loop = 0; loop < n-1; loop++) {
        for (int i = 0; i < m; i++) {
            if (dist[gr[i][0]-1] == INF) {
                continue;
            }
            if (dist[gr[i][1]-1] > dist[gr[i][0]-1] + gr[i][2]) {
                dist[gr[i][1]-1] = dist[gr[i][0]-1] + gr[i][2];
            }
        }
    }
    long long ans = dist[n-1];
    vector<bool> flag(n, false);
    for (int loop = 0; loop < n; loop++) {
        for (int i = 0; i < m; i++) {
            if (dist[gr[i][0]-1] == INF) {
                continue;
            }
            if (dist[gr[i][1]-1] > dist[gr[i][0]-1] + gr[i][2]) {
                dist[gr[i][1]-1] = dist[gr[i][0]-1] + gr[i][2];
                flag[gr[i][1]-1] = true;
            }
            if (flag[gr[i][0]-1]) {
                flag[gr[i][1]-1] = true;
            }
        }
    }
    if (flag[n-1]) {
        std::cout << "inf" << std::endl;
    } else {
        std::cout << -ans << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    int n,m;

    gettimeofday(&start,NULL);

    std::cin >> n >> m;
    vector< vector<int> > gr(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        std::cin >> gr[i][0] >> gr[i][1] >> gr[i][2];
        gr[i][2] = -gr[i][2];
    }
    solve(n,m,gr);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
