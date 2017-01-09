#include<iostream>
#include<queue>
#include<stdio.h>
#include"navigation.h"
using namespace std;

XY::XY(int i, int j){   //initialization of a node in the map
    x = i;
    y = j;
}

int findPath(XY start, XY goal)
{
    int i, j, p, q;
    
    for(i = 0; i < 18; i++){
        for(j = 0; j < 18; j++){
            dis[i][j] = -1;     // initialization
        }
    }
    
    queue<XY> iterator;
    iterator.push(start);       // push the starting point into the queue
    dis[start.x][start.y] = 0;
    
    XY xy(0,0);
    int flag = 0;
    while(!iterator.empty()){
        xy = iterator.front();  // get the first element in the queue
        iterator.pop();
        for(p = -1; p < 2; p++){    // check the 8 nodes around it
            for(q = -1; q < 2; q++){
                if(p == q || p + q == 0)continue;   // ignore the diagonal nodes
                i = xy.x + p;
                j = xy.y + q;
                
                if(i < 0 || j < 0 || i > 17 || j > 17)continue; // ignore the nodes outside the fringe
                
                if(dis[i][j] == -1){    // check whether it is modified before or not
                    if(grid[i][j] != 0){    // check whether it is an obstacle or not
                        dis[i][j] = dis[xy.x][xy.y] + 1;    // save the distance between the starting point to this node
                        XY xyn(i,j);
                        if (i == goal.x && j == goal.y){
                            flag = 1;   // goal found, set and flag and end the loop
                            break;
                        }
                        iterator.push(xyn);     // push the node into the queue
                    }
                }
            }
            if(flag)break;  // goal found
        }
        if(flag)break;  // goal found
    }
    
    
    int cnt = dis[goal.x][goal.y];  // the resulting distance between start and goal
    cout << "Length of the shortest path: " << cnt << endl;
    
    int x = goal.x;
    int y = goal.y;
    int path[cnt][2];   // the array to save the way nodes
    while(cnt != 0){
        flag = 0;
        for(p = -1; p < 2; p++){    // check the 8 nodes around
            for(q = -1; q < 2; q++){
                if(p == q || p + q == 0)continue;
                i = x + p;
                j = y + q;
                
                if(i < 0 || j < 0 || i > 17 || j > 17)continue;
                
                if(dis[i][j] == cnt-1){     // backtrack the path from goal to start
                    cnt = cnt - 1;
                    flag = 1;
                    path[cnt][0] = i;
                    path[cnt][1] = j;
                    x = i;
                    y = j;
                    break;
                }
            }
            if(flag)break;
        }
    }
    
    for(i = 0; i < dis[goal.x][goal.y]; i++){   
        cout << "No." << i << ":\t" << path[i][0] << '\t' << path[i][1] << endl;    // print out the way points
        res[path[i][0]][path[i][1]] = 1;                                            // print out the path in a map
    }
    cout << "No." << i << ":\t" << goal.x << '\t' << goal.y << endl;
    res[goal.x][goal.y] = 1;
    return dis[goal.x][goal.y];
}

XY landmark(XY xy)  // the function to find the nearest landmark
{
    if(abs(xy.x - 5) < abs(xy.x - 12)){
        if(abs(xy.y - 5) < abs(xy.y - 12))
            return A;
        else
            return B;
    }
    else{
        if(abs(xy.y - 5) < abs(xy.y - 12))
            return C;
        else
            return D;
    }
}

int between(XY m, XY n) // the function to compute the distance between any 2 landmarks
{
    if(m.x != n.x && m.y == 5 && n.y == 5)
        return 9;
    else
        return abs(m.x - n.x) + abs(m.y - n.y);
}

int findFrontier(int len)   // the function to find the number of nodes on the fringe
{
    int count = 0;
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 18; j++){
            if (dis[i][j] == len || dis[i][j] == len - 1){  // the nodes on the frontier must have the value of max or max-1
                if (i > 0){     // the node on the left
                    if (dis[i-1][j] == -1 && grid[i-1][j] != 0){    // it should have value -1 and is not a obstacle
                        count++;
                        continue;
                    }
                }
                if (i < 17){    // the node on the right
                    if (dis[i+1][j] == -1 && grid[i+1][j] != 0){
                        count++;
                        continue;
                    }
                }
                if (j > 0){     // the node above
                    if (dis[i][j-1] == -1 && grid[i][j-1] != 0){
                        count++;
                        continue;
                    }
                }
                if (j < 17){    // the node underneath
                    if (dis[i][j+1] == -1 && grid[i][j+1] != 0){
                        count++;
                        continue;
                    }
                }
            }
        }
    }
    return count;
}

