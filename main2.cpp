#include<iostream>
#include<queue>
#include<stdio.h>
#include"navigation.h"
using namespace std;

int grid[18][18] = {    // the map: 0 means obstacles
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//0
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//1
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//2
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//3
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//4
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//5
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//6
    {1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1},//7
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//8
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//9
    {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1},//0
    {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1},//1
    {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1},//2
    {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1},//3
    {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1},//4
    {1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1},//5
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//6
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} //7
//   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7
};
XY A(5,5), B(5,12), C(12,5), D(12,12);  // 4 landmarks
int res[18][18];    // the matrix to store the resulting path
int dis[18][18];    // the matrix the store the distance from the starting point to every node

int main()
{
    XY start(0,0), goal(0,0);
    
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 18; j++){
            res[i][j] = grid[i][j]-1;
        }
    }
    
    // input the staring and ending points
    cout << "Starting Point: x=";
    cin >> start.x;
    cout << "Starting Point: y=";
    cin >> start.y;
    if (grid[start.x][start.y] == 0){ // if the node is an obstacle on the map, print out ERROR
        cout << "INPUT ERROR: the node is an obstacle!" << endl;
        return -1;
    }
    if (start.x < 0 || start.x > 17 || start.y < 0 || start.y > 17){    // if the node is out of the map
        cout << "INPUT ERROR: the node is out of range!" << endl;
        return -1;
    }
    
    cout << "Ending Point: x=";
    cin >> goal.x;
    cout << "Ending Point: y=";
    cin >> goal.y;
    if (grid[goal.x][goal.y] == 0){
        cout << "INPUT ERROR: the node is an obstacle!" << endl;
        return -1;
    }
    if (goal.x < 0 || goal.x > 17 || goal.y < 0 || goal.y > 17){
        return -1;
        cout << "INPUT ERROR: the node is out of range!" << endl;
    }
    
    cout << endl;
    int len = findPath(start, landmark(start)); // find the shortest path between the starting point to the nearest landmark
    cout << "The number of nodes on the fringe = " << findFrontier(len) << endl;  // print out the number of nodes on the fringe
    int total = len + between(landmark(start), landmark(goal));
    cout << "The length between landmark (" << landmark(start).x << ',' << landmark(start).y
                               << ") and (" << landmark(goal).x << ',' << landmark(goal).y
                               << ") = " << between(landmark(start), landmark(goal)) << endl;
    len = findPath(landmark(goal), goal);  // find the shortest path between the nearest landmark to the goal
    cout << "The number of nodes on the fringe = " << findFrontier(len) << endl;  // print out the number of nodes on the fringe
    total += len;
    cout << endl;
    cout << "The total length = " << total << endl;   // print out the total lenght from the starting point to the goal
    
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 18; j++){
            cout << res[i][j] << '\t';  // print out the path on the map to better illustrate the answer
        }
        cout << endl;
    }
    return 0;
}
