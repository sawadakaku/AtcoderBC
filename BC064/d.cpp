#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

void solve(int n, string s) {
    string original = s;
    int righthang = 0;
    int lefthang = 0;
    for (int i = 0; i < n; i++) {
        if (s.back() == ')') {
            break;
        }
        righthang += 1;
        s.pop_back();
    }
    while (s.empty() != true) {
        if (s.back() == ')' ) {
            lefthang += 1;
        } else {
            if (lefthang == 0) {
                righthang += 1;
            } else {
                lefthang -= 1;
            }
        }
        s.pop_back();
    }
    for (int i = 0; i < lefthang; i++) {
        std::cout << '(';
    }
    std::cout << original;
    for (int i = 0; i < righthang; i++) {
        std::cout << ')';
    }
    std::cout << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int n;

    gettimeofday(&start,NULL);

    string s;
    std::cin >> n >> s;
    solve(n, s);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
