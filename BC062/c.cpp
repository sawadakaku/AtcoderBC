#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>

using namespace std;

void solve(long long h, long long w) {
    vector<long long> differs;
    long long min_of_3;
    long long max_of_3;
    if (h%3 == 0 || w%3 == 0) {
        std::cout << 0 << std::endl;
    } else {
        if (h%3 == 1) {
            min_of_3 = w * (h/3);
            if (w%2 == 0) {
                differs.push_back((h-(h/3))*(w/2) - min_of_3);
            } else {
               // if (w < h-(h/3)) {
               //     differs.push_back(w);
               // } else {
               //     differs.push_back(((h-(h/3))/2 +1)*w - min_of_3);
               // }
                differs.push_back(w);
                differs.push_back((h-(h/3))*(w/2+1) - min_of_3);
            }
        } else {
            max_of_3 = w * ((h/3)+1);
            if (w%2 == 0) {
                differs.push_back(max_of_3 - (h-((h/3)+1))*(w/2));
            } else {
                //if (w < h-((h/3)+1)) {
                //    differs.push_back(w);
                //} else {
                //    differs.push_back(max_of_3 - (h-((h/3)+1))*(w/2+1));
                //}
                differs.push_back(w);
                differs.push_back(max_of_3 - (h-((h/3)+1))*(w/2));
            }
        }
        long long tmp = w;
        w = h;
        h = tmp;
        if (h%3 == 1) {
            min_of_3 = w * (h/3);
            if (w%2 == 0) {
                differs.push_back((h-(h/3))*(w/2) - min_of_3);
            } else {
                differs.push_back(w);
                differs.push_back((h-(h/3))*(w/2+1) - min_of_3);
            }
        } else {
            max_of_3 = w * ((h/3)+1);
            if (w%2 == 0) {
                differs.push_back(max_of_3 - (h-((h/3)+1))*(w/2));
            } else {
                differs.push_back(w);
                differs.push_back(max_of_3 - (h-((h/3)+1))*(w/2));
            }
        }
        std::cout << *min_element(differs.begin(), differs.end()) << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    long long h,w;

    gettimeofday(&start,NULL);

    std::cin >> h >> w;
    solve(h, w);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
