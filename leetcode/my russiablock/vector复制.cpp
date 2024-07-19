#include <iostream>
#include <vector>

// ����һ��ʹ��ѭ������
void copyWithLoop(const std::vector<int>& source, std::vector<int>& destination, int start, int end) {
    for (int i = start; i <= end; ++i) {
        destination.push_back(source[i]);
    }
}

// ��������ʹ�õ���������
void copyWithIterators(const std::vector<int>& source, std::vector<int>& destination, int start, int end) {
    auto begin = source.begin() + start;
    auto endIt = source.begin() + end + 1;
    destination.insert(destination.end(), begin, endIt);
}

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> destination;

    // ���ƴ����� 2 �� 5 ��Ԫ��
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
