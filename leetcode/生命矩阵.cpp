#include <iostream>
#include <vector>
std::vector<std::vector<int>> expandAndZero(const std::vector<std::vector<int>>& row) {
    int n = row.size();
    int m = row[0].size();

    std::vector<std::vector<int>> tar(n + 2, std::vector<int>(m + 2, 0));

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            tar[i][j] = row[i - 1][j - 1];
        }
    }

    return tar;
}
std::vector<std::vector<int>> shrinkAndRestore(const std::vector<std::vector<int>>& tar) {
    int n = tar.size() - 2;
    int m = tar[0].size() - 2;

    std::vector<std::vector<int>> row(n, std::vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            row[i][j] = tar[i + 1][j + 1];
        }
    }

    return row;
}
std::vector<std::vector<int>> countSurroundingGreaterThanZero(const std::vector<std::vector<int>>& row) {
    int n = row.size();
    int m = row[0].size();

    std::vector<std::vector<int>> result(n, std::vector<int>(m, 0));

    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            int count = 0;
            if(row[i][j] > 0){
            	count--;
			} 
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x >= 0 && x < n && y >= 0 && y < m && row[x][y] > 0) {
                        count++;
                    }
                }
            }
            result[i][j] = count;
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> row = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    std::vector<std::vector<int>> counts = countSurroundingGreaterThanZero(expandAndZero(row));
	counts=shrinkAndRestore(counts);
    for (const auto& vec : counts) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
