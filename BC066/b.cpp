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

bool isTrue(string S) {
    bool ret = true;
    for (int i = 0; i < S.size()/2; i++) {
        ret = ret && (S[i] == S[i+S.size()/2]);
    }
    return ret;
}

void solve(string S) {
    bool ret = S.size()-2;
    S.pop_back();
    S.pop_back();
    while(S.size() > 1) {
        if (isTrue(S)) {
            break;
        }
        S.pop_back();
        S.pop_back();
    }
    std::cout << S.size() << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    string S;

    gettimeofday(&start,NULL);

    std::cin >> S;
    solve(S);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
