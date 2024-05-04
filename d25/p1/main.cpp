#include <iostream>
#include <fstream>
#include <cmath>

unsigned long long snufuToI(std::string snufu) {
    int pw = 0;
    unsigned long long ret = 0;
    for (auto it = snufu.rbegin(); it != snufu.rend(); it++ ) {
        unsigned long long val = pow(5, pw);
        switch (*it) {
        case '-':
            ret += -val;
            break;
        case '=':
            ret += -2 * val;
            break;
        case '1':
            ret += val;
            break;
        case '2':
            ret += 2 * val;
        }
        pw++;

    }
    return ret;
}

std::string iToSnafu(unsigned long long n) {
    std::string snafu = "012=-";
    if (!n) {
        return "";
    }
    int snfu = n%5;
    n /= 5;
    if (snfu > 2) {
        n++;
    }
    return iToSnafu(n) + snafu[snfu];
}

int main(int argc, char ** argv) {
    if (argc != 2) {
        return (0);
    }
    std::ifstream   ifs(argv[1]);
    std::string     numInSnufu;
    unsigned long long sum = 0;
    while (std::getline(ifs, numInSnufu)) {
        sum += snufuToI(numInSnufu);
    }
    ifs.close();
    std::cout << sum << std::endl;
    std::cout << iToSnafu(sum) << std::endl;
    return (0);
}