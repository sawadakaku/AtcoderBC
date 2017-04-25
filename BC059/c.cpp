#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
    int t;
    vector<long long> answer(2,0);
    long long sumi = 0;
    bool flag = false;
    cin >> t;
    vector<long long> A(t);
    for (int i = 0; i < t; i++) {
        cin >> A[i];
    }
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < t; i++) {
            sumi += A[i];
            if(sumi == 0){
                answer[j] += 1;
                if (flag) {
                    sumi = -1;
                } else {
                    sumi = 1;
                }
            }else if(sumi>0 == flag) {
                answer[j] += abs(sumi)+1;
                if (sumi>0) {
                    sumi = -1;
                } else {
                    sumi = 1;
                }
            }
            flag = !flag;
        }
        flag = true;
        sumi =0;
    }
    cout << min(answer[0],answer[1]) << endl;

    return 0;
}
