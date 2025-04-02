#include <iostream>
using namespace std;

namespace david {
    void date_print(short j, short m, short d) {
        std::cout << j << ":" << m << ":" << d << " : YYYY:MM:DD" << endl;
    }

    bool datum_even(short j, short m, short d) {
        std::string result;
        result = j%2 == 0 && m%2==0 && d%2==0 ?  "even" : "oneven";
        std::cout << result << std::endl;
        return result == "even";
    }

    void string_print_whatever() {
        std::string whatever;
        std::cout << "Enter a string without spaces: " << std::endl;
        std::cin >> whatever;

        for (int i = 0; i < whatever.size() ; i++) {
            if (i%3 == 0) {
                std::cout << whatever[i] << ", ";
            }
        }
        std::cout << endl;
        std::string klinkers = "aeoiuAEOIU";
        for (char c : whatever) {
            if (klinkers.contains(c)) {
                std::cout << c << ", ";
            }
        }
        std::cout << endl;

    }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    short dag = 2;
    short maand = 4;
    short jaar = 2025;
    david::date_print(jaar, maand, dag);
    std::cout << david::datum_even(jaar, maand, dag);
    david::string_print_whatever();
    return 0;
}