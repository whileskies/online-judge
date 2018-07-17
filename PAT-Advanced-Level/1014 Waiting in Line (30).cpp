#include <iostream>
#include <queue>
#include <algorithm>
#include <iomanip>
 
using namespace std;
 
int N, M, K, Q;
int T[1010], totalTime[1010];
queue<int> winQueue[21];
 
int findMinCusWin(queue<int> q[])
{
    int minCus = 20;
    int index = 1;
    for (int w = 1; w <= N; w++) {
        if (q[w].size() < minCus) {
            minCus = q[w].size();
            index = w;
        }
    }
    return index;
}
 
void printTime(int t, int cusIndex)
{
    int h = 8, m = 0; 
    m = t % 60; 
    h += t / 60; 
 
    if ((t-T[cusIndex]) / 60 >= 9)
        cout << "Sorry" << endl;
    else
        cout << setfill('0') << setw(2) << h << ":" << setw(2) << m << endl; 
}
 
int main()
{
    //freopen("in", "r", stdin);
    cin >> N >> M >> K >> Q;
 
    for (int i = 1; i <= K; i++) {
        int t;
        cin >> t;
        T[i] = t;
 
        int winIndex = findMinCusWin(winQueue);
        if (winQueue[winIndex].size() != M) {   //存在有些窗口未满 winIndex为人数最少窗口且最小序号
            if (!winQueue[winIndex].empty())
                totalTime[i] = totalTime[winQueue[winIndex].back()] + t;
            else
                totalTime[i] = t;
            winQueue[winIndex].push(i);
        }
  
        else {   //窗口全满 寻找第一个顾客最快出队的队列 排到此队
            int minTime = 1 << 29;
            for (int w = 1; w <= N; w++) {
                if (totalTime[winQueue[w].front()] < minTime) {
                    minTime = totalTime[winQueue[w].front()];
                    winIndex = w;
                }
            }
 
            winQueue[winIndex].pop();
            totalTime[i] = totalTime[winQueue[winIndex].back()] + t;
            winQueue[winIndex].push(i);
        }
    }
 
    while (Q--) {
        int c;
        cin >> c;
        printTime(totalTime[c], c);
    }
 
    return 0;
}