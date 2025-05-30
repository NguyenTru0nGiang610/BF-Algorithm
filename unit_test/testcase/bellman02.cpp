#include "unit_test.hpp"

bool UNIT_TEST::bellman02()
{
    string name = "bellman02";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 4;
    int G[num_vertices][num_vertices] = {
        {0, 1, 4, 0},
        {0, 0, 2, 6},
        {0, 0, 0, 3},
        {0, 0, 0, 0}
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D'};

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
    string end = "C";

    string result = BF_Path(edge, numberOfEdges, start[0], end[0]);

    output << result;

    //! ---- EXPECT --------
    string expect = "A B C";
    return printResult(output.str(), expect, name);
}