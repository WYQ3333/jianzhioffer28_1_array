#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
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

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>res;
		int n = matrix.size();
		int m = matrix[0].size();
		int layer = (min(m, n) - 1) / 2 + 1;
		for (int i = 0; i<layer; i++){
			for (int j = i; j<m - i; j++){
				res.push_back(matrix[i][j]);
			}
			for (int k = i + 1; k<n - i; k++){
				res.push_back(matrix[k][m - i - 1]);
			}
			for (int p = m - i - 2; (p>i - 1) && (n - i - 1 != i); p--){
				res.push_back(matrix[n - i - 1][p]);
			}
			for (int q = n - i - 2; (q>i) && (m - i - 1 != i); q--){
				res.push_back(matrix[q][i]);
			}
		}
		return res;

	}
};

void TestFunc(){
	vector<vector<int>> array = { { 1, 2, 3, 4 }, {5,6,7,8}
	, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	int i = 0;
	int j = 0;
	for (i = 0; i < array.size(); ++i){
		for (j = 0; j < array[0].size(); ++j){
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	Solution s;
	vector<int> temp = s.printMatrix(array);
	i = 0;
	for (i = 0; i < temp.size(); ++i){
		cout << temp[i] <<" ";
	}
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}