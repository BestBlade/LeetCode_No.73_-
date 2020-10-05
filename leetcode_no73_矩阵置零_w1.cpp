/* ------------------------------------------------------------------|
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:

输入:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-matrix-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：32 ms, 在所有 C++ 提交中击败了77.92%的用户
*	内存消耗：13.1 MB, 在所有 C++ 提交中击败了45.77%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	vector <int> cols;
	
	for (int i = 0; i < matrix.size(); i++) {
		int flag = 0;
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == 0) {
				cols.push_back(j);
				flag = 1;
			}
		}
		if (flag) {
			fill(matrix[i].begin(), matrix[i].end(), 0);
		}
	}

	unique(cols.begin(), cols.end());

	for (int x:cols) {
		for (int i = 0; i < matrix.size(); i++) {
			matrix[i][x] = 0;
		}
	}

	return;
}

int main(){
	vector<vector<int> > matrix = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };

	setZeroes(matrix);
}