#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> ans;
		int row = matrix.size();
		int col = matrix[0].size();
		int start = 0;
		while (row>start * 2 && col>start * 2){
			for (int i = start; i <= col - 1 - start; i++){
				ans.push_back(matrix[start][i]);
			}
			if (start<row - start - 1){
				for (int i = start + 1; i <= row - 1 - start; i++){
					ans.push_back(matrix[i][col - 1 - start]);
				}
			}
			if (start<col - start - 1 && start<row - start - 1){
				for (int i = col - 2 - start; i >= start; i--){
					ans.push_back(matrix[row - start - 1][i]);
				}
			}
			if (start<col - start - 1 && start<row - start - 2){
				for (int i = row - 2 - start; i >= start + 1; i--){
					ans.push_back(matrix[i][start]);
				}
			}
			start++;
		}
		return ans;
	}
};

void TestFunc(){

}

int main(){
	TestFunc();
	system("pause");
	return 0;
}