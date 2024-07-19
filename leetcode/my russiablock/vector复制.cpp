#include <iostream>
#include <vector>

// 方法一：使用循环复制
void copyWithLoop(const std::vector<int>& source, std::vector<int>& destination, int start, int end) {
    for (int i = start; i <= end; ++i) {
        destination.push_back(source[i]);
    }
}

// 方法二：使用迭代器复制
void copyWithIterators(const std::vector<int>& source, std::vector<int>& destination, int start, int end) {
    auto begin = source.begin() + start;
    auto endIt = source.begin() + end + 1;
    destination.insert(destination.end(), begin, endIt);
}

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> destination;

    // 复制从索引 2 到 5 的元素
    copyWithLoop(source, destination, 2, 5);
    for (const auto& num : destination) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    destination.clear();
 	destination.insert(destination.end(),  source.begin() + 2,source.begin() + 5 + 1);
    //copyWithIterators(source, destination, 2, 5);
    for (const auto& num : destination) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
