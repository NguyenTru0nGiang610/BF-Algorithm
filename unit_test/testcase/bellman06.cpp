#include "unit_test.hpp"

bool UNIT_TEST::bellman06()
{
    string name = "bellman06";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 8;
    int G[num_vertices][num_vertices] = {
        {0, 72, 89, 77, 2, 58, 13, 69},
        {77, 0, 69, 31, 57, 93, 83, 48},
        {52, 21, 0, 62, 8, 77, 32, 14},
        {33, 1, 40, 0, 72, 99, 72, 59},
        {89, 24, 1, 61, 0, 12, 78, 63},
        {36, 91, 98, 79, 26, 0, 28, 1},
        {18, 77, 49, 36, 98, 77, 0, 45},
        {75, 9, 59, 7, 77, 65, 45, 0},
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D', 'E', 'J', 'F', 'G'};

    // Convert to edge list
    int edge[num_vertices*num_vertices][3];
    int numberOfEdges = 0;
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (G[i][j] > 0)
            {
                edge[numberOfEdges][0] = vertex[i];
                edge[numberOfEdges][1] = vertex[j];
                edge[numberOfEdges][2] = G[i][j];
                numberOfEdges++;
            }
        }
    }

    string start = "A";
    string end = "D";

    string result = BF_Path(edge, numberOfEdges, start[0], end[0]);

    output << result;

    //! ---- EXPECT --------
    string expect =
        "A E J G D";
    return printResult(output.str(), expect, name);
}