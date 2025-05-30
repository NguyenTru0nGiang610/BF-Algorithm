#include "unit_test.hpp"

bool UNIT_TEST::bellman04()
{
    string name = "bellman04";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 6;
    int G[num_vertices][num_vertices] = {
        {0,75,6,19,4,83},
        {81,0,34,24,86,76,},
        {49,91,0,4,60,14},
        {55,99,17,0,47,67,},
        {57,96,77,34,0,38,},
        {13,15,66,41,65,0}
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D', 'E', 'F'};

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
    string end = "E";

    string result = BF_Path(edge, numberOfEdges, start[0], end[0]);

    output << result;

    //! ---- EXPECT --------
    string expect = "A E";
    return printResult(output.str(), expect, name);
}