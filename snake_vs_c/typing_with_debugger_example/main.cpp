#include <iostream>
#include <map>

// met auto kunnen we de compiler laten bepalen welk type iets wordt

void call_4(std::map<std::string, int> x) {
    std::cout << x["a"] << std::endl;
}

void call_3(std::map<std::string, int> x) {
    x[0];
    std::cout << x[0] << std::endl;
    call_4(x);
}

void call_2(std::map<std::string, int> x) {
    return call_3(x);
}

void call_1(std::map<std::string, int> x) {
    return call_2(x);
}

int main() {
    call_1(std::map<std::string, int>{{"a", 5}});
    //call_1([{'a': 5}]);
    return 0;
}