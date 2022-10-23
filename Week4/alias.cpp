#include <vector>
#include <string>

using BigInt = unsigned long long int;
using MyList = std::vector<BigInt>;

int main() {
    const BigInt value = 1234567890ULL;
    MyList wordList = {value, 1ULL, 0};
    return 0;
}

