#include <iostream>

bool palindroom(std::string w) {
    if (w.size() <= 1) return true;

    if (w[0] == w[w.size()-1]) {
        return palindroom(w.substr(1, w.size()-2));
    } else {
        return false;
    }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << palindroom("kak") << std::endl;
    std::cout <<palindroom("akaka") << std::endl;
    std::cout <<palindroom("hottoho") << std::endl;
    std::cout <<palindroom("") << std::endl;
    std::cout <<palindroom("k") << std::endl;
    return 0;
}