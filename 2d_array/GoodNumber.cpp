#include <iostream>
#include <vector>
using namespace std;

int sumOfGoodNumbers(vector<vector<int>>& a) {
    int totalSum = 0;
    
    for (const auto& row : a) {
        int rowSize = row.size();
        
        if (rowSize == 1) {
            totalSum += row[0];
        } else {
            for (int i = 0; i < rowSize - 1; ++i) {
                if (abs(row[i] - row[i + 1]) == 1) {
                    totalSum += row[i];
                }
            }
            if (rowSize > 1 && abs(row[rowSize - 2] - row[rowSize - 1]) == 1) {
                totalSum += row[rowSize - 1];
            }
        }
    }
    
    return totalSum;
}

int main() {
    vector<vector<int>> a = {
        {7, 6, 5, 4, 3},
        {5},
        {4},
        {10, 12, 23},
        {1, 2, 3},
        {5, 10}
    };
    
    int result = sumOfGoodNumbers(a);
    cout << "Sum of good numbers: " << result << endl;
    
    return 0;
}
