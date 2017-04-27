#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sys/time.h>

using namespace std;

void solve(int n, vector<string> s){
    //vector< vector<int> > bin(n vector<int>(26,0));
    vector< vector<int> > bin(26, vector<int>(n+1,0));
    string answer = "";
    for (int i = 0; i < n; i++) {
        while (!s[i].empty()) {
            for (int j = 0; j < 26; j++) {
                if (s[i].back() == 'a'+j) {
                    bin[j][i] += 1;
                    s[i].pop_back();
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        bin[i][n] = *min_element(bin[i].begin(), bin[i].end()-1);
        for (int j = 0; j < bin[i][n]; j++) {
            answer.push_back('a' + i);
        }
    }
    cout << answer << endl;
}

int main(){
    struct timeval start,end;
    long long span;
    int n;

    gettimeofday(&start,NULL);
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    solve(n, s);
    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    fprintf(stderr,"**Total time: %lld ms\n",span/1000);
    return 0;
}
