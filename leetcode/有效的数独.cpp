#include <iostream>
#include <vector>
#include <map>
using namespace std; 
 // 假设上述代码在 Solution.h 中
class Solution {
public:
    bool isValidSudoku(vector<vector <char> >& board) {
        int result=1;
        map<pair <int,int>,int> hasx;
        map<pair <int,int>,int> hasy;
        map<pair <int,int>,int> hasz;
        for(int x=0;x<board.size();x++){
             for(int y=0;y<board[0].size();y++){
             	 if(board[x][y]==' '){
                    continue;}
                int res=board[x][y] - '0';
                cout<<"res=" <<res <<endl;
                
                int z= x / 3 * 3 + y / 3;
                pair<int, int> px={x,res},py={y,res},pz{z,res};
                ++hasx[px];
                ++hasy[py];
                ++hasz[pz];
               // cout<<res <<"  "<<y <<"  "<<x <<"  "<<z<<"  hasx=  "<<hasx[px]<<"  hasy=  "<<hasy[py]<<"  hasz=  "<<hasz[pz]<<endl;
                if(hasx[px]>1){
                    result=0;break;}
                if(hasy[py]>1){
                    result=0;break;}
                if(hasz[pz]>1){
                    result=0;break;}                     
        }
        }
        if(result==1){
            return true;
        }
        else
        return false;
    }
};
int main() {
    Solution solution;

    // 有效的数独棋盘示例
    std::vector<std::vector<char>> validBoard = {
        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    // 无效的数独棋盘示例
    std::vector<std::vector<char>> invalidBoard = {
        {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '5'}  // 最后一个数字应为 9 ，这里是 5 ，导致无效
    };

    if (solution.isValidSudoku(validBoard)) {
        std::cout << "The valid board is valid." << std::endl;
    } else {
        std::cout << "The valid board is invalid. Something is wrong!" << std::endl;
    }

    if (solution.isValidSudoku(invalidBoard)) {
        std::cout << "The invalid board is valid. Something is wrong!" << std::endl;
    } else {
        std::cout << "The invalid board is invalid as expected." << std::endl;
    }

    return 0;
}
