#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

void solve(int n,long long t, vector<long long> T) {
    long long answer = t;
    for (int i = 0; i < n-1; i++) {
        if (t < T[i+1] - T[i]) {
            answer += t;
        } else {
            answer += T[i+1] - T[i];
        }
    }
    std::cout << answer << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int n;
    long long t;
    vector<long long> T;

    gettimeofday(&start,NULL);

    std::cin >> n >> t;
    for (int i = 0; i < n; i++) {
        long long tmp;
        std::cin >> tmp;
        T.push_back(tmp);
    }
    solve(n, t, T);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
