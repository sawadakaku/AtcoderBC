#include <iostream>
#include <string>

using namespace std;

int main(){
    string o,e;
    cin >> o >> e ;
    string answer;
    for (int i = 0; i < e.size(); i++) {
        answer.push_back(o[i]);
        answer.push_back(e[i]);
    }
    if (o.size() > e.size()) {
        answer.push_back(o.back());
    }
    cout << answer << endl;
    return 0;
}
