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

using namespace std;

int dfs(int W, vector< vector< pair<int, int> > > stuff, int w, int k) {
    if (W < w+k) {
        return 0;
    } else {
        int ret = 0;
        while (k<4) {
            if (W-(w+k) < 0) {
                break;
            }
            if (stuff[k].empty()) {
                k++;
                continue;
            }
            pair<int, int> tmp = stuff[k].back();
            stuff[k].pop_back();
            ret = max(ret, tmp.second + dfs(W-(w+k), stuff, w, k));
            stuff[k].push_back(tmp);
            k++;
        }
        return ret;
    }
}

void solve(int N, int W, vector< pair<int, int> > stuff) {
    int w = stuff[0].first;
    vector< vector< pair<int, int> > > stuff_wight_concern(4);
    for (int i = 0; i < N; i++) {
        stuff_wight_concern[stuff[i].first-w].push_back(stuff[i]);
    }
    for (int i = 0; i < 4; i++) {
        sort(stuff_wight_concern[i].begin(), stuff_wight_concern[i].end());
    }
    int ret = dfs(W, stuff_wight_concern, w, 0);
    std::cout << ret << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int N, W;

    gettimeofday(&start,NULL);

    std::cin >> N >> W;
    vector< pair<int, int> > stuff(N);
    for (int i = 0; i < N; i++) {
        std::cin >> stuff[i].first >> stuff[i].second;
    }
    solve(N, W, stuff);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
