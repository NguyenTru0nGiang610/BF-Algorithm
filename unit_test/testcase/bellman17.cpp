#include "unit_test.hpp"

bool UNIT_TEST::bellman17()
{
    string name = "bellman17";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 8;
    int G1[num_vertices][num_vertices] = {
        {0, 4281, 6587, 7158, 9050, 8141, 5670, 3474},
        {1718, 0, 9777, 9137, 979, 2002, 4333, 7291},
        {3146, 9981, 0, 1929, 8615, 6655, 21, 4216},
        {8106, 6084, 770, 0, 8617, 2178, 989, 8064},
        {565, 9261, 4312, 1198, 0, 2201, 7822, 248},
        {342, 3492, 74, 8412, 3270, 0, 9211, 9391},
        {5272, 3545, 6682, 4771, 9878, 8612, 0, 9738},
        {6533, 4985, 3955, 991, 1069, 4725, 9608, 0}
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'Z'};

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

    string start = "Z";
    string end = "A";

    string result = BF_Path(edge1, numberOfEdges1, start[0], end[0]);

    output << result;

    //! ---- EXPECT --------
    string expect = "Z E A";
    return printResult(output.str(), expect, name);
}