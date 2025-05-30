#include "unit_test.hpp"

bool UNIT_TEST::bellman12()
{
    string name = "bellman12";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 7;
    int G1[num_vertices][num_vertices] = {
        {0, 76, 95, 70, 68, 55, 61},
        {61, 0, 87, 16, 53, 42, 19},
        {42, 5, 0, 11, 2, 0, 83},
        {55, 3, 89, 0, 68, 34, 26},
        {55, 26, 89, 51, 0, 30, 62},
        {87, 59, 10, 58, 27, 0, 65},
        {19, 41, 5, 87, 94, 99, 0}
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    // Convert to edge list
    int edge1[num_vertices*num_vertices][3];
    int numberOfEdges1 = 0;
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (G1[i][j] > 0)
            {
                edge1[numberOfEdges1][0] = vertex[i];
                edge1[numberOfEdges1][1] = vertex[j];
                edge1[numberOfEdges1][2] = G1[i][j];
                numberOfEdges1++;
            }
        }
    }

    string start = "A";
    string end = "B";

    string result = BF_Path(edge1, numberOfEdges1, start[0], end[0]);

    output << result;

    //! ---- EXPECT --------
    string expect =
        "A F C B";
    return printResult(output.str(), expect, name);
}