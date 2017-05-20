#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

void solve(int x, int y) {
    vector<int> gr1 = {1, 3, 5, 7, 8, 10, 12};
    vector<int> gr2 = {4, 6, 9, 11};
    vector<int> gr3 = {2,};
    bool x_is_gr1 = find(gr1.begin(), gr1.end(), x) != gr1.end();
    bool x_is_gr2 = find(gr2.begin(), gr2.end(), x) != gr2.end();
    if (x_is_gr1) {
        if (find(gr1.begin(), gr1.end(), y) != gr1.end()) {
            std::cout << "Yes" << std::endl;
        } else{
            std::cout << "No" << std::endl;
        }
    } else if(x_is_gr2) {
        if (find(gr2.begin(), gr2.end(), y) != gr2.end()) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    } else {
        if (y == 2) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}

int main() {
    struct timeval start,end;
    long long span;
    int x, y;

    gettimeofday(&start,NULL);

    std::cin >> x >> y;
    solve(x, y);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
