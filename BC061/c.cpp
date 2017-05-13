#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

void solve(int n, long long k, vector< pair<int,int> > vpi) {
    sort(vpi.begin(), vpi.end());
    int counter = 0;
    long long num_from_min = 0;
    while (k > num_from_min) {
        num_from_min += vpi[counter].second;
        counter++;
    }
    counter--;
    std::cout << vpi[counter].first << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int n;
    long long k;

    gettimeofday(&start,NULL);

    std::cin >> n >> k;
    vector< pair<int,int> > vpi(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vpi[i].first >> vpi[i].second;
    }
    solve(n, k, vpi);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
