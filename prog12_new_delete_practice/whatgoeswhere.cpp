// (<XXX> HUGenerateStudentVersion=True)
#include <iostream>
using std::cout;
static int resultaat;

int doeNogMeer(int& a, int& b){
    a -= 3;
    b -= 3;
    int* c = new int(4);
    cout << "a: " << a << "\nb: " << b << "\n" << "c: " << c << "\n";
    return a*b**c;
}

void doeIets(int k, int &j){
    k *= 6;
    j *= 6;
    int* c = new int(4);
    cout << &j << "\n";
    cout << "k: " << k << "\nj: " << j << "\n";

}

int main(void) {
    int a = 1;
    int b = 1;

    doeIets(a, b);
    cout << &b << "\n";
    cout << "a: " << a << "\nb: " << b << "\n";

    resultaat = doeNogMeer(a,b);
    cout << "a: " << a << "\nb: " << b << "\n";
    return 0;
}