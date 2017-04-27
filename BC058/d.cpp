#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
//#include <sys/time.h>

using namespace std;

vector<long long> calc_times(long long n){
//    vector< vector<long long> > xc(n, vector<long long>(n));
//    for (long long i = 0; i < n; i++) {
//        for (long long j = 0; j < n; j++) {
//            long long a = min( {i+1, j+1, n-i, n-j} );
//            xc[i][j] = a;
//        }
//    }
    vector<long long> ret(n);
    int prodiff = n;
    ret[0] = n;
    ret[n-1] = n;
    for (int i = 1; 2*i < n; i++) {
        prodiff -= 2;
        ret[i] = ret[i-1] + prodiff;
        ret[n-1-i] = ret[i-1] + prodiff;
    }
//    for (long long i = 0; i < n; i++) {
//        ret.push_back(accumulate(xc[i].begin(), xc[i].end(), 0));
//    }
    return ret;
}

void solve(long long n, long long m, vector<long long> X, vector<long long> Y){
    vector<long long> times_of_x(n-1);
    vector<long long> times_of_y(m-1);
    long long modll = 1000000007;
    times_of_x = calc_times(n-1);
    times_of_y = calc_times(m-1);
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    long long answer = 0;
    long long sum_X = 0;
    long long sum_Y = 0;
    for (int i = 0; i < n-1; i++) {
        sum_X += (X[i+1]-X[i]) * times_of_x[i] % modll;
        sum_X = sum_X % modll;
    }
    for (int i = 0; i < m-1; i++) {
        sum_Y += (Y[i+1]-Y[i]) * times_of_y[i] % modll;
        sum_Y = sum_Y % modll;
    }
    answer = sum_X * sum_Y % modll;
//    for (long long i = 0; i < n-1; i++) {
//        for (long long j = 0; j < m-1; j++) {
//            answer += (X[i+1]-X[i]) * (Y[j+1]-Y[j]) * times_of_x[i] * times_of_y[j] % 1000000007LL;
////            answer += (X[i+1]-X[i]) * (Y[j+1]-Y[j]) * times_of_x[i] * times_of_y[j];
////            answer = answer % 1000000007LL;
//        }
//    }
//    answer = answer % 1000000007LL;
    cout << answer << endl;
}

int main(){
//    struct timeval start,end;
//    long long span;
    long long n,m;

//    gettimeofday(&start,NULL);
    cin >> n >> m;
    vector<long long> X(n);
    vector<long long> Y(m);
    for (long long i = 0; i < n; i++) {
        cin >> X[i];
    }
    for (long long i = 0; i < m; i++) {
        cin >> Y[i];
    }
    solve(n, m, X, Y);
//    gettimeofday(&end,NULL);
//    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
//    cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
