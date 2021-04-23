#include "common.h"

using namespace std;

/**
 * @brief 
 * 
 * @param board 
 * @return true 
 * @return false 
 */
bool isValidSudoku(vector<vector<char>>& board) {
	vector<vector<bool>> col(9, vector<bool>(9, false));
	vector<vector<bool>> row(9, vector<bool>(9, false));
	vector<vector<bool>> box(9, vector<bool>(9, false));

	auto ROW_SIZE = board.size();
	if (ROW_SIZE <= 0) {
		return false;
	}
	auto COL_SIZE = board[0].size();
	for (int i = 0; i < ROW_SIZE; ++i) {
		for (int j = 0; j < COL_SIZE; ++j) {
			if (board[i][j] == '.') {
				continue;
			}
			int value = board[i][j] - '1';
			int index = (i * 3 ) / 3 + j / 3;

			// if (row[i][value] == false && col[j][value] == false && box[index][value] == false) {
			// 		row[i][value] = true;
			// 		col[j][value] = true;
			// 		box[index][value] = true;
			// } else {
			// 	return false;
			// }
			
			if (col[j][value] || row[i][value] || box[index][value]) {
				return false;

			}
			row[i][value] = true;
			col[j][value] = true;
			box[index][value] = true;
		}
	}

	return true;
}


int main()
{
	vector<vector<char>> data {{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}};
	bool temp = isValidSudoku(data);
	cout << temp << endl;
	assert(temp == true);

	return 0;
}
