#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string a,b,c;
    cin >> a >> b >> c;
    transform(a.begin(),a.begin()+1,a.begin(),::toupper);
    transform(b.begin(),b.begin()+1,b.begin(),::toupper);
    transform(c.begin(),c.begin()+1,c.begin(),::toupper);
    cout << a[0] << b[0] << c[0] << endl;
    return 0;
}
