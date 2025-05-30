#ifndef _BELLMAN_H_
#define _BELLMAN_H_

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void BF(int graph[][3], int numberOfEdges, char startVertex, int BellmanFordValue[], int BellmanFordPrevious[]);
string BF_Path(int graph[][3], int numberOfEdges, char startVertex, char goalVertex);

#endif //_BELLMAN_H_