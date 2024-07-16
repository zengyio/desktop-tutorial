#include <iostream>
#include <string>
#include <cstring>
// 定义计算列号的函数
class Solution {
public:
    // 定义计算列号的函数
    int column(int i, int numRows) {
        int val = i % (2 * numRows - 2);
        int val1 = i / (2 * numRows - 2) * (numRows - 1);
        if (val1 == -1) {
            val1 = 0;
        }
        if (val <= numRows && val > 0) {
            return val1;
        } else if (val > numRows) {
            std::cout << val - numRows << std::endl;
            return val - numRows + val1;
        } else {
            return val1 - 1;
        }
    }

    // 定义计算行号的函数
    int row(int i, int numRows) {
        int q = i % (2 * numRows - 2);
        if (q > 0 && q <= numRows) {
            return q - 1;
        } else if (q == 0) {
            return 1;
        } else {
            return 2 * numRows - q - 1;
        }
    }

    std::string convert(std::string s, int numRows) {
        int len = s.length();
        char target[numRows][len];
        memset(target, '0', sizeof(target));
        for (int i = 0; i < len; i++) {
            target[row(i+1, numRows)][column(i+1, numRows)] = s[i];
        }
        std::string e;
        for (int i = 0; i < numRows; i++) {
            for (int w = 0; w < len; w++) {
            	
                if (target[i][w]!= '0') {
                    e += target[i][w];
                }
                std::cout<<target[i][w]<<" ";
            }
            std::cout<<std::endl;
        }
        return e;
    }
};

int main() {
    Solution solution;
    std::string s = "PAYPALISHIRING";
    int numRows = 2;
    std::string result = solution.convert(s, numRows);
    std::cout <<s.length()<< "转换后的字符串: " << result <<result.length()<< std::endl;

    return 0;
}
//00	 03               012321 012321 012321  a  s g
//10   1213  15 123450 123450 8-q	            
//20 21	 2324	y=x-4	 4
//30     33
