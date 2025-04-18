#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    string s;
    cin >> s; // 输入一个不含空格的字符串

    // 统计 A～Z 每个字母的大写和小写出现次数
    vector<int> cntUp(26, 0), cntLow(26, 0);
    for (char c : s) {
        if (isupper(c))
            cntUp[c - 'A']++;
        else if (islower(c))
            cntLow[c - 'a']++;
    }

    // 每个字母能组成的字母对数为大写和小写出现次数的较小值
    vector<int> avail(26, 0);
    for (int i = 0; i < 26; i++){
        avail[i] = min(cntUp[i], cntLow[i]);
    }

    vector<string> snakes;  // 保存每轮提取的蛇形字符串

    // 重复提取，直到没有任何可用的字母对
    while (true) {
        int bestLen = 0;    // 当前轮最长蛇形字符串的字母对数
        int bestStart = -1; // 对应的起始字母下标（0对应 'A'）

        // 遍历 A～Z 作为可能的起点
        for (int i = 0; i < 26; i++) {
            if (avail[i] > 0) { // 该字母有可用的字母对
                int len = 0;
                // 从字母 i 开始连续检查后续字母
                for (int j = i; j < 26; j++) {
                    if (avail[j] > 0)
                        len++;
                    else
                        break;
                }
                // 选择最长者；若长度相同则选择起始字母较小的
                if (len > bestLen) {
                    bestLen = len;
                    bestStart = i;
                }
            }
        }
        if (bestLen == 0) break; // 无任何可用字母对，结束提取

        // 构造蛇形字符串：每个字母对由对应大写和小写构成
        string snake = "";
        for (int j = bestStart; j < bestStart + bestLen; j++) {
            snake.push_back('A' + j);
            snake.push_back('a' + j);
        }
        snakes.push_back(snake);

        // 将已使用的字母对各自减1
        for (int j = bestStart; j < bestStart + bestLen; j++) {
            avail[j]--;
        }
    }

    // 根据输出描述进行排序：
    // 1. 按照蛇形字符串的首字符（大写字母）升序排列
    // 2. 同一首字母的，按照字符串长度降序排列（例如 "CcDdEeFf" 长于 "CcDdEe"）
    if (snakes.empty()) {
        cout << "Not Found";
    } else {
        sort(snakes.begin(), snakes.end(), [](const string &a, const string &b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            else
                return a.size() > b.size(); // 同一首字母时，长度长的排前面
        });
        // 每个蛇形字符串单独一行输出
        for (const auto &str : snakes) {
            cout << str << endl;
        }
    }
//    system("pause");
    return 0;
}