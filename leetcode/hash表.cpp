#include <iostream>
#include <unordered_map>

template<typename T1, typename T2>
struct CustomPair : std::pair<T1, T2> {
    CustomPair() : std::pair<T1, T2>(0, 0) {}
};
int main() {
    std::unordered_map<CustomPair<int, int>, int> loca1;  // 添加自定义哈希函数 PairHash
    loca1[{1, 2}] = 3;
    loca1[{4, 5}] = 6;
    return 0;
}
