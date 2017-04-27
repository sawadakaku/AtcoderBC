#include <iostream>
#include <string>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    string answer;
    if (a-b == b-c) {
        answer = "YES";
    } else {
        answer = "NO";
    }
    cout << answer << endl;
    return 0;
}
