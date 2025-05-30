#include "unit_test.hpp"

bool UNIT_TEST::bellman11()
{
    string name = "bellman11";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 10;
    int G1[num_vertices][num_vertices] = {
        {0, 87, 44, 1, 52, 63, 98, 44, 91, 35},
        {8, 0, 92, 32, 72, 94, 34, 4, 24, 18},
        {4, 73, 0, 55, 85, 86, 12, 93, 98, 26},
        {99, 34, 42, 0, 68, 22, 38, 22, 26, 54},
        {20, 70, 97, 56, 0, 78, 90, 40, 3, 36},
        {75, 59, 60, 45, 16, 0, 85, 52, 53, 72},
        {17, 46, 70, 95, 98, 57, 0, 37, 18, 31},
        {28, 40, 57, 34, 13, 27, 31, 0, 21, 57},
        {73, 61, 12, 10, 88, 72, 22, 34, 0, 40},
        {8, 38, 93, 32, 55, 39, 54, 50, 89, 0}
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

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

    string start = "E";
    string end = "G";

    string result = BF_Path(edge1, numberOfEdges1, start[0], end[0]);

    output << result;

    //! ---- EXPECT --------
    string expect =
        "E I G";
    return printResult(output.str(), expect, name);
}