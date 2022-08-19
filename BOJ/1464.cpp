#include <iostream>
#include <string>

using namespace std;

string flipString(string, int);
string S;
int main(int argc, char const *argv[])
{
    cin >> S;
    cout << flipString(S, 0);
    
    return 0;
}

string flipString(string str, int len) {
    if (len == str.length()) return str;

    string str2 = "";
    for (int i = len; i >= 0; i--) {
        str2 += str[i];
    }
    str2 += str.substr(len+1);

    string ret1 = flipString(str, len + 1);
    string ret2 = flipString(str2, len+1);

    if (ret1 > ret2) return ret2;
    else return ret1;
}