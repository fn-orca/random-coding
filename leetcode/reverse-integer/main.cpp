#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long d = 0;
        int aux = 0;

        bool neg = false;
        if(x < 0) {
            neg = true;
            x = -x;
        }
        
        while(x) {
            d *= 10;
            d += x % 10;
            aux *= 10;
            aux += x % 10;
            x /= 10;
        }
        
        if(d != (long long) aux) {
            return 0;
        }
        
        if(neg) {
            d = -d;
        }
        
        return (int) d;
    }
};

int main() {
    return 0;
}