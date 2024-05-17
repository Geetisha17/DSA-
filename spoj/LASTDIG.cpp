#include <iostream>
#include <vector>
using namespace std;

int lastDigitOfPower(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % 10;
        }
        a = (a * a) % 10;
        b /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        int last_digit = lastDigitOfPower(a % 10, b);

        cout << last_digit << endl;
    }

    return 0;
}
