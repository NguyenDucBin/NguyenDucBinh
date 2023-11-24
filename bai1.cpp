#include<iostream>
using namespace std;

class Sum {
    int a, b;
public:
    Sum(int a, int b) {
        this->a = a;
        this->b = b;
    }
    int TinhTong() {
        return a + b;
    }
};

int main() { 
    int A, B;
    cin >> A>>B;
    Sum s(A, B);
    cout  << s.TinhTong() << endl;
    return 0;
}
