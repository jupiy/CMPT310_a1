#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

class XY
{
public:
    int x;
    int y;
    XY(int, int);
};

int findPath(XY, XY);	// the function to find the shortest path between 2 nodes
XY landmark(XY);		// the funciton to find the nearest landmark of a node
int between(XY, XY);	// the function to find the distance between any 2 landmarks
int findFrontier(int);	// the funciton to find the number of node on the fringe

extern int grid[18][18];	// the map
extern XY A,B,C,D;			// landmarks
extern int res[18][18];		// the resulting path
extern int dis[18][18];		// the matrix the store the distance from the starting point to every node