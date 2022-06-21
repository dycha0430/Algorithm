#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int solve(int);
bool isPalindrome(int, int);
int cache[2500];
string input;
int main(int argc, char const *argv[])
{
    cin >> input;
    memset(cache, -1, 2500 * sizeof(int));
    cout << solve(0) << endl;
    
    return 0;
}

int solve(int start) {
    if (start == input.length()) return 0;
    int& ret = cache[start];
    if (ret != -1) return ret;
    ret = 2500;
    for (int i = start; i < input.length(); i++) {
        if (isPalindrome(start, i)) ret = min(ret, 1 + solve(i+1));
    }
    
    return ret;
}

bool isPalindrome(int start, int end) {
    for (int i = 0; i < (end-start)/2 + 1; i++) {
        if (input[start+i] != input[end-i]) return false;
    }
    return true;
}