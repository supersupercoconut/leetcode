//import universal *.h
#include "../../../stdc.h"
using namespace std;
namespace solution37{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*** 二维递归...每一行中的元素取值是递归，不同行之前的取值也是递归
     *  1. N皇后问题： 每一行的元素排列是简单的，只有那么几种可能
     *  2. 解数独问题: 一次递归要分析的是整个二维平面上一个位置的取值
     *      backtracking() 分析其变换的情况 接受上一次backtracking已经取值到的位置, 然后更改自己的取值，继续判断这是不是数独问题的解
     *
     *  求解该问题所犯的bug在于
     *  (1) 在backtracking() 什么时候需要返回true以及什么之后返回false —— (i,j)处从'1'~'9'取值, 没有正确结果即返回false，上一次递归处需要重新取值 | 所有的(i,j)都取值结束，可以返回true
     *      获取返回值可以提前结束整个递归 因为整个递归中只有一个解
     *  (2) 处理isValid()函数中, 给定的row以及col未必是最后一个元素，所以3*3区域判断的时候，有些元素还是'.' | 这些'.'是可以重复的!!
     * ***/

    // 判断当前填入的数据是否正常 row代表行数
    bool isValid(vector<vector<char>>& board, int row, int col)
    {
        // (row,col) 当前写入的值，在本行没有相同元素 在本列没有相同元素
        for(int i = 0; i < board.size(); ++i)
        {
            if(i == col) continue;
            // 当前列
            if(board[row][i] == board[row][col]) return false;
        }
        for(int j = 0; j < board.size(); ++j)
        {
            if(j == row) continue;
            if(board[j][col] == board[row][col]) return false;
        }

        // 数字在每一个3*3的区域中只能出现一次
        for(int border_row = 3; border_row <= board.size(); border_row = border_row + 3 )
        {
            for(int border_col = 3; border_col <= board.size(); border_col = border_col + 3 )
            {
                unordered_set<char> temp = {};
                for(int i = border_row-3; i < border_row; i++)
                {
                    for(int j = border_col-3; j < border_col; j++)
                    {
                        if(board[i][j] != '.')
                        {
                            if(temp.find(board[i][j]) != temp.end()) return false;
                            else
                                temp.insert(board[i][j]);
                        }
                    }
                }
            }
        }
        return true;
    }

    // (row, col)代表位置
    bool backtracking(vector<vector<char>>& board, int row, int col)
    {
        int i = row;
        int j = col;
        // note 二维递归, 先判断这一行的元素能不能通过isValid(), 再取判断下一行的元素能不能通过isValid()
        // (i,j) 上一次填入数据的位置就是(i,j) 当前输入(i,j) 程序会自动去(i,j+1)位置
        for(; i < board.size(); ++i)
        {
            for(; j < board.size(); ++j)
            {
                if(board[i][j] == '.')
                {
                    for(char val = '1'; val <= '9'; val++)
                    {
                        board[i][j] = val;
                        if(isValid(board,i,j))
                            if(backtracking(board,i,j)) return true;
                        board[i][j] = '.';
                    }
                    // 当前位置1~9全部选择完毕 没有解
                    return false;
                }
            }
            j = 0;
        }
        // 9*9中所有的数据都找到了, 可以返回正确结果
        return true;
    }

    // 该程序中如果没有找到解，就会返回最初给定的board
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board,0,0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution37;
int main() {
    Solution solution = Solution();
    vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solution.backtracking(board,0,0);

    for(int i = 0; i <board.size(); ++i)
    {
        for(int j = 0; j < board.size(); ++j)
            cout << board[i][j] << ' ';
        cout << endl;
    }
    return 0;
}

