#include "TestProgram.h"

#include <iostream>
#include "Math.h"
#include "Vector3d.h"

using namespace std;

// just a method to test some functionality. should write unittests instead...
void test() {

    cout << "TEST Vector3d" << endl;
    Vector3d zero;
    Vector3d a(1, 2, 3);
    Vector3d b(4, 5, 6);
    cout << zero.toString() << endl;
    cout << a.toString() << endl;
    cout << b.toString() << endl;
    cout << (a + b).toString() << endl;
    cout << (a - b).toString() << endl;
    cout << (a * 2).toString() << endl;
    cout << (a / 3).toString(2) << endl;
    cout << a.dot(b) << endl;

    cout << "TEST Math" << endl;
    cout << Math::dot(a, b) << endl;
}


int main() {
    cout << "Blue Byte Programming Test" << endl;
    cout << "Gerald Schenke 29.01.2018" << endl;

    TestProgram program;
    program.run();

    test();

    cout << "Goodbye" << endl;
    return 0;
}

