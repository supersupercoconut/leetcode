/*** 图论(主要整理代码随想录中的图论章节问题, 问题基本都是在卡码网上) ***/


/* 卡码网104 建造最大岛屿 */
// note 这里的整理过程主要有两步 (1)整理当前所有岛屿以及其对应的编号 (2)重新遍历0元素出来的位置然后寻找对应的区域 但是需要直到每一个(x,y)位置对应的岛屿编号 | 一开始的思路是保留原始的输入数据，所以需要重新新建一个m*n的二维结构来对应数据
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//// 对应岛屿编号 | 序号从1开始,将其与其余部分分开
//int grid_index = 1;
//// 对应岛屿面积
//int grid_res = 0;
////int temp = 0;
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited, vector<vector<int>>& index, int x, int y)
//{
//    if(visited[x][y] == 1)
//        return;
//    visited[x][y] = 1;
//    int next_x = 0;
//    int next_y = 0;
//
//    if(graph[x][y] == 1)
//    {
//        index[x][y] = grid_index;
//        grid_res +=1;
//        for(auto temp : dir)
//        {
//            next_x = x + temp[0];
//            next_y = y + temp[1];
//            // 合理范围判断下一步元素
//            if(next_x >= 0 && next_y >= 0 && next_x <= graph.size()-1 && next_y <= graph[0].size()-1)
//            {
//                dfs(graph, visited, index, next_x, next_y);
//            }
//        }
//    }
//}
//
//// 调用这个函数就默认了其会进行0到1的转换，但是实际上是存在不进行转化也能取到最大的情况
//int computeMaxRes(vector<vector<int>>& graph, vector<vector<int>>& index,  unordered_map<int, int>& grid_map)
//{
//    int res = 0;
//    // 定义used数组(处理是否出现相同元素还可以使用unorder_set()操作，清除的时候可以直接clear)
//    vector<int> used(grid_map.size(), 0);
//    for(int i = 0; i < graph.size(); ++i)
//    {
//        for(int j = 0; j < graph[0].size(); ++j)
//        {
//            if(graph[i][j] == 0)
//            {
//                int next_x = 0;
//                int next_y = 0;
//                int temp_res = 0;
//                // 直接只去寻找周围元素, 但是需要注意当前元素周围是同一个index序号的岛屿，这里容易出现反复加的情况
//                for(auto temp : dir)
//                {
//                    next_x += i + temp[0];
//                    next_y += j + temp[1];
//                    if(next_x >= 0 && next_y >= 0 && next_x <= graph.size()-1 && next_y <= graph[0].size() - 1)
//                    {
//                        if(grid_map.find(index[next_x][next_y]) != grid_map.end())
//                        {
//                            if(used[index[next_x][next_y]] == 0)
//                            {
//                                temp_res += grid_map[index[next_x][next_y]];
//                                used[index[next_x][next_y]] = 1;
//                            }
//                        }
//                    }
//                    // 注意这里的元素需要清零
//                    next_x = 0;
//                    next_y = 0;
//                }
//                res = res > temp_res ? res : temp_res;
//                // 使用数据清零
//                vector<int> tmp_vec(grid_map.size(), 0);
//                used.swap(tmp_vec);
//            }
//        }
//    }
//    return res;
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//
//    vector<vector<int>> graph(n, vector<int>(m, 0));
//    vector<vector<int>> visited(n, vector<int>(m,0));
//    vector<vector<int>> index(n, vector<int>(m,0));
//    unordered_map<int, int> grid;
//
//    for(int i = 0; i < n; ++i)
//    {
//        for(int j = 0; j < m; ++j)
//            cin >> graph[i][j];
//    }
//
//    int max_res = 0;
//    for(int i = 0; i < n; ++i)
//    {
//        for(int j = 0; j < m; ++j)
//        {
//            if(graph[i][j] == 1 && visited[i][j] == 0)
//            {
//                dfs(graph, visited, index, i, j);
//                grid.insert(pair<int, int>( grid_index ,grid_res));
//                max_res = max_res > grid_res ? max_res : grid_res ;
//                grid_index += 1;
//                grid_res = 0;
//            }
//        }
//    }
//    // 变换之后, 自己那个位置上对应的元素也应该+1 | 如果不进行变换, 那么就直接使用对之前整理出来的max_res即可
//    cout << max(max_res, computeMaxRes(graph, index, grid) + 1);
////    for(auto i : grid)
////    {
////        cout << i.first << " " << i.second << endl;
////    }
////
////    for(auto i : index)
////    {
////        for(auto j : i)
////        {
////            cout << j << ' ';
////        }
////        cout << endl;
////    }
//
//    return 0;
//}






/* 卡码网103 水流问题(双边界开始遍历，从两个边界上能选择出来的visited数组进行融合) */
//#include <iostream>
//#include <vector>
//using namespace std;
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y)
//{
//    if(visited[x][y] == 1)
//        return;
//    visited[x][y] = 1;
//    int next_x = 0;
//    int next_y = 0;
//    for(auto temp : dir)
//    {
//        next_x = x + temp[0];
//        next_y = y + temp[1];
//        // 合理范围判断下一步元素
//        if(next_x >= 0 && next_y >= 0 && next_x <= graph.size()-1 && next_y <= graph[0].size()-1)
//        {
//            // 能够继续向上移动
//            if(graph[x][y] <= graph[next_x][next_y])
//                dfs(graph, visited, next_x, next_y);
//        }
//    }
//}
//
//
//int main()
//{
//    // note 一开始想的方法复杂度太高, 需要从每一个点都出发遍历整个区域,故为 O(m^2 * n^2)
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n, vector<int>(m, 0));
//    for(int i = 0; i < n; ++i)
//    {
//        for(int j = 0; j < m; ++j)
//            cin >> graph[i][j];
//    }
//
//    // 设定两种遍历的区域, 最终取其中的共享点
//    vector<vector<int>> firstBoard(n, vector<int>(m,0));
//    vector<vector<int>> secondBoard(n, vector<int>(m,0));
//
//    // 第一边界
//    for(int i = 0; i <= m-1; ++i)
//        dfs(graph, firstBoard, 0, i);
//    for(int i = 0; i <= n-1; ++i)
//        dfs(graph, firstBoard, i, 0);
//
//    // 第二边界
//    for(int i = 0; i <= m - 1; ++i)
//        dfs(graph, secondBoard, n-1, i);
//    for(int i = 0; i <= n - 1; ++i)
//        dfs(graph, secondBoard, i, m-1);
//
//
//    for(int i = 0; i < n; ++i)
//    {
//        for(int j = 0; j < m; ++j)
//        {
//            if(firstBoard[i][j] && secondBoard[i][j])
//                cout << i << ' ' << j << endl;
//        }
//    }
//    return 0;
//}


/* 卡码网102 (沉没孤岛) 深度优先搜索(重新修正了之前的处理模式，将深度优先的逻辑进行修正) */
//#include <iostream>
//#include <vector>
//#include <deque>
//using namespace std;
//
//int flag = 0;
//// 保留一定结果，方便后续的处理
//deque<pair<int,int>> reindex = {};
//// 定义方向
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//
//// 指定出发点(x,y) 终点(end_x, end_y) 以及当前地图graph, 访问地图visited
//void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y)
//{
//    if(visited[x][y] == 1) return;
//    else
//        visited[x][y] = 1;
//
//    int next_x = 0;
//    int next_y = 0;
//    if(graph[x][y] != 0)
//    {
//        // 处理当前节点，如果当前节点的位置在边缘区域直接清空该部分
//        if(x <= 1 || y <= 1 || x == graph.size() - 1 || y == graph[0].size() - 1)
//        {
//            flag = 0;
//            // 清除当前所有区域的信息
//            while(!reindex.empty())
//                reindex.pop_front();
//        }
//
//        if(flag == 1)
//            reindex.emplace_back(x,y);
//
//        for(auto temp : dir)
//        {
//            next_x = x + temp[0];
//            next_y = y + temp[1];
//            if(next_x >= 0 && next_x <= graph.size()-1 && next_y >= 0 && next_y <= graph[0].size()-1)
//                dfs(graph, visited, next_x, next_y);
//        }
//        // 一次回调函数对应的的reindex查找结束之后不能直接操作graph数据, 需要当前这次操作回到出发位置才能处理
//    }
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//            cin >> graph[i][j];
//    }
//
//    // 深度优先搜索
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//        {
//            if(visited[i][j] == 0)
//            {
//                if(i <= 1 || j <= 1 || i == graph.size()-1 || j == graph[0].size() - 1)
//                    flag = 0;
//                else
//                    flag = 1;
//
//                if(graph[i][j] == 1)
//                {
//                    dfs(graph, visited, i, j);
//                    while(!reindex.empty())
//                    {
//                        auto temp = reindex.front();
//                        reindex.pop_front();
//                        graph[temp.first][temp.second] = 0;
//                    }
//                }
//                else
//                    visited[i][j] = 1;
//            }
//        }
//    }
//
//    for(int i = 1; i<=graph.size()-1; ++i)
//    {
//        for(int j = 1; j <= graph[0].size() - 2; ++j)
//            cout << graph[i][j] << ' ';
//        cout << graph[i][graph[0].size()-1] << endl;
//    }
//    return 0;
//}


/* 卡码网101 (孤岛的最大面积) 广度优先搜索 */
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int flag = 0;
//int res = 0;
//int temp_res = 0;
//deque<pair<int,int>> que = {};
//// 定义方向
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//
//void bfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y)
//{
//    visited[x][y] = 1;
//    if(graph[x][y] == 0)
//        return;
//
//    // 当前开始搜索的位置为graph中的1位置
//    que.push_back(pair<int,int>(x,y));
//    if(flag == 1)
//        temp_res += 1;
//    while(!que.empty())
//    {
//        auto node = que.front();
//        que.pop_front();
//
//        int next_x = 0;
//        int next_y = 0;
//        for(auto temp : dir)
//        {
//            next_x = node.first + temp[0];
//            next_y = node.second + temp[1];
//            if(next_x >= 0 && next_x <= graph.size() - 1 && next_y >= 0 && next_y <= graph[0].size() - 1)
//            {
//                if(visited[next_x][next_y] == 0)
//                {
//                    visited[next_x][next_y] = 1;
//                    if(graph[next_x][next_y] == 1)
//                    {
//                        // 判断是否在边缘
//                        if(next_x <= 1 || next_y <= 1 || next_x == graph.size() -1 || next_y == graph[0].size() - 1)
//                        {
//                            flag = 0;
//                            temp_res = 0;
//                        }
//                        if(flag == 1)
//                            temp_res += 1;
//                        que.push_back(pair<int,int>(next_x,next_y));
//                    }
//                }
//            }
//        }
//    }
//    // 如果当前的队列为空, 即对应着一块岛屿面积就查找完毕了
////    cout << temp_res << endl;
//    res += temp_res;
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//            cin >> graph[i][j];
//    }
//
//
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//        {
//            if(visited[i][j] == 0)
//            {
//                // graph为0的时候,需要进入给visited赋值1
//                if( i <= 1 || i == graph.size()-1 || j <= 1 || j == graph[0].size() - 1)
//                    flag = 0;
//                else
//                    flag = 1;
//                bfs(graph, visited, i, j);
//                temp_res = 0;
//
//            }
//        }
//    }
//    cout << res;
//    return 0;
//}


/* 卡码网101 (孤岛的最大面积) 深度优先搜索 */
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int flag = 0; // 用于判断res是否可以执行+1操作
//int res = 0;
//int temp_res = 0;
//// 定义方向
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//
//// 指定出发点(x,y) 终点(end_x, end_y) 以及当前地图graph, 访问地图visited
//void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y, int cur_x, int cur_y)
//{
//    if(visited[cur_x][cur_y] == 1) return;
//    else
//        visited[cur_x][cur_y] = 1;
//
//
//    int next_x = 0;
//    int next_y = 0;
//    if(graph[cur_x][cur_y] != 0)
//    {
//        if(cur_x <= 1 || cur_x == graph.size()-1 || cur_y <= 1 || cur_y == graph[0].size()-1)
//        {
//            temp_res = 0;
//            flag = 0;
//        }
//
//        // 当前graph[][]为1, 说明这里没有查找到的过陆地
//        if(flag == 1)
//            temp_res += 1;
//        for(auto temp : dir)
//        {
//            next_x = cur_x + temp[0];
//            next_y = cur_y + temp[1];
//            if(next_x >= 0 && next_x <= graph.size()-1 && next_y >= 0 && next_y <= graph[0].size()-1)
//                dfs(graph, visited, x, y, next_x, next_y);
//        }
//        // 当前节点的出发情况已经分析完毕, 即整理结果
//        if(cur_x == x && cur_y == y) res += temp_res;
//    }
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//            cin >> graph[i][j];
//    }
//
//    // 深度优先搜索
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//        {
//            flag = 1;
//            dfs(graph, visited, i, j, i, j);
//            temp_res = 0;
//        }
//    }
//    cout << res;
//    return 0;
//}


/* 卡码网100 最大岛屿的面积(广度优先搜索) */
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int res = 0;
//int max_res = 0;
//deque<pair<int,int>> que = {};
//// 定义方向
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//
//void bfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y)
//{
//    visited[x][y] = 1;
//    if(graph[x][y] == 0)
//        return;
//
//    que.push_back(pair<int,int>(x,y));
//    res += 1;
//    while(!que.empty())
//    {
//        auto node = que.front();
//        que.pop_front();
//
//        int next_x = 0;
//        int next_y = 0;
//        for(auto temp : dir)
//        {
//            next_x = node.first + temp[0];
//            next_y = node.second + temp[1];
//            if(next_x >= 0 && next_x <= graph.size() - 1 && next_y >= 0 && next_y <= graph[0].size() - 1)
//            {
//                if(visited[next_x][next_y] == 0)
//                {
//                    visited[next_x][next_y] = 1;
//                    if(graph[next_x][next_y] == 1)
//                    {
//                        // 对应没有查找且是一块路基
//                        res += 1;
//                        que.push_back(pair<int,int>(next_x,next_y));
//                    }
//                }
//            }
//        }
//    }
//    // 如果当前的队列为空, 即对应着一块岛屿面积就查找完毕了
//    max_res = max_res > res ? max_res : res;
//    res = 0;
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//            cin >> graph[i][j];
//    }
//
//
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//        {
//            if(visited[i][j] == 0)
//            {
//                // graph为0的时候,需要进入给visited赋值1
//                bfs(graph, visited, i, j);
//            }
//        }
//    }
//    cout << max_res;
//    return 0;
//}


/* 卡码网100 最大岛屿的面积(深度优先搜索) */
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int res = 0;
//int max_res = 0; // 用于衡量比较最大值
//// 定义方向
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//
//// 指定出发点(x,y) 终点(end_x, end_y) 以及当前地图graph, 访问地图visited
//void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y, int cur_x, int cur_y)
//{
//    if(visited[cur_x][cur_y] == 1) return;
//    else
//        visited[cur_x][cur_y] = 1;
//
//    int next_x = 0;
//    int next_y = 0;
//    if(graph[cur_x][cur_y] != 0)
//    {
//        // 当前graph[][]为1, 说明这里没有查找到的过陆地
//        res += 1;
//        for(auto temp : dir)
//        {
//            next_x = cur_x + temp[0];
//            next_y = cur_y + temp[1];
//            if(next_x >= 0 && next_x <= graph.size()-1 && next_y >= 0 && next_y <= graph[0].size()-1)
//                dfs(graph, visited, x, y, next_x, next_y);
//        }
//        // 说明当前该出发点周围一圈的陆地都被发现了,可以比较大小
//        if(x == cur_x && y == cur_y) max_res = max_res > res ? max_res : res;
//    }
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//            cin >> graph[i][j];
//    }
//
//    // 深度优先搜索
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//        {
//            dfs(graph, visited, i, j, i, j);
//            res = 0; // 执行完需要清空res的值
//        }
//    }
//    cout << max_res;
//    return 0;
//}


/* 卡码网99 岛屿数量(广度优先搜索) */
// note bfs与dfs最大的不同就是, dfs可以利用回溯剔除掉一些不合格的元素，但是bfs需要手动在队列输入的元素的时候就进行处理
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int res = 0;
//deque<pair<int,int>> que = {};
//// 定义方向
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//// 如果当前节点为graph为1 且当前visited为0 说明res可以+1
//void bfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y)
//{
//    visited[x][y] = 1;
//    if(graph[x][y] == 0)
//        return;
//
//    que.push_back(pair<int,int>(x,y));
//    while(!que.empty())
//    {
//        auto node = que.front();
//        cout << "que size():" << que.size() << endl;
//        que.pop_front();
//
//        int next_x = 0;
//        int next_y = 0;
//        for(auto temp : dir)
//        {
//            next_x = node.first + temp[0];
//            next_y = node.second + temp[1];
//            if(next_x >= 0 && next_x <= graph.size() - 1 && next_y >= 0 && next_y <= graph[0].size() - 1)
//            {
//                if(visited[next_x][next_y] == 0)
//                {
//                    visited[next_x][next_y] = 1;
//                    if(graph[next_x][next_y] == 1)
//                        que.push_back(pair<int,int>(next_x,next_y));
//                }
//            }
//        }
//    }
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//            cin >> graph[i][j];
//    }
//
//
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//        {
//            if(visited[i][j] == 0)
//            {
//                if(graph[i][j] == 1) res += 1;
//                // graph为0的时候,需要进入给visited赋值1
//                bfs(graph, visited, i, j);
//            }
//        }
//    }
//    cout << res;
//    return 0;
//}


/* 卡码网99 岛屿数量(深度优先搜索) */
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int res = 0;
//// 定义方向
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//
//// 指定出发点(x,y) 终点(end_x, end_y) 以及当前地图graph, 访问地图visited
//void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y, int cur_x, int cur_y)
//{
//    if(visited[cur_x][cur_y] == 1) return;
//    else
//        visited[cur_x][cur_y] = 1;
//
//    int next_x = 0;
//    int next_y = 0;
//    if(graph[cur_x][cur_y] != 0)
//    {
//        for(auto temp : dir)
//        {
//            next_x = cur_x + temp[0];
//            next_y = cur_y + temp[1];
//            if(next_x >= 0 && next_x <= graph.size()-1 && next_y >= 0 && next_y <= graph[0].size()-1)
//                dfs(graph, visited, x, y, next_x, next_y);
//        }
//        // 说明当前该出发点周围一圈的陆地都被发现了,可以直接输出res
//        if(x == cur_x && y == cur_y) res += 1;
//    }
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//            cin >> graph[i][j];
//    }
//
//    // 深度优先搜索
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//        {
//            dfs(graph, visited, i, j, i, j);
//        }
//    }
//    cout << res;
//    return 0;
//}


/* 卡码网98 所有可达路径 */
//#include <iostream>
//#include <vector>
//#include <list>
//// vector表示图的保存方式为邻接矩阵 | list表示图的保存方式为邻接表
//using namespace std;
//
//vector<vector<int>> res = {};
//vector<int> path = {};
//// x为当前节点 n为目标节点
//void bfs(const vector<vector<int>>& graph, int x, int n)
//{
//    if(x == n)
//    {
//        res.push_back(path);
//        return;
//    }
//
//    // 因为这里的graph是直接按照序号来的，所以需要在一开始的基础上+1
//    for(int i = 1; i < graph[x].size(); ++i)
//    {
//        if(graph[x][i] == 1)
//        {
//            path.push_back(i);
//            bfs(graph,i,n);
//            path.pop_back();
//        }
//    }
//    return;
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
//
//    // 构造邻接矩阵
//    int a = 0, b = 0;
//    while(m > 0)
//    {
//        cin >> a >> b;
//        graph[a][b] = 1;
//        --m;
//    }
//
//    path.push_back(1);
//    bfs(graph,1,n);
//
//    for(auto i : res)
//    {
//        for(int j = 0; j < i.size()-1; ++j)
//            cout << i[j] << ' ';
//        cout << i[i.size()-1];
//        cout << endl;
//    }
//    if(res.size() == 0) cout << -1 << endl;
//    return 0;
//}