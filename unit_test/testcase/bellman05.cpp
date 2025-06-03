#include "unit_test.hpp"

bool UNIT_TEST::bellman05()
{
    string name = "bellman05";
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

    char vertex[num_vertices] = {'A', 'B', 'C', 'D', 'W', 'X', 'Y', 'Z'};

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

    int BellmanFordValue[20];
    int BellmanFordPrevious[20];

    for(int i = 0; i < num_vertices; i++){
        BellmanFordValue[i] = -1;
        BellmanFordPrevious[i] = -1;
    }

    for(int i = 0; i < 1; i++){
        BF(edge, numberOfEdges, 'D', BellmanFordValue, BellmanFordPrevious);
        output << "step " << i+1 << ":" << endl;
        for(int j = 0; j < num_vertices; j++){
            output << BellmanFordValue[j] << " ";
        }
        output << endl;
        for(int j = 0; j < num_vertices; j++){
            output << BellmanFordPrevious[j] << " ";
        }
        output << endl;
    }

    //! ---- EXPECT --------
    string expect = "step 1:\n"
                    "33 1 40 0 72 99 72 59 \n"
                    "3 3 3 -1 3 3 3 3 \n"
                    "step 2:\n"
                    "33 1 40 0 35 84 46 49 \n"
                    "3 3 3 -1 0 4 0 1 \n"
                    "step 3:\n"
                    "33 1 36 0 35 47 46 49 \n"
                    "3 3 4 -1 0 4 0 1 \n"
                    "step 4:\n"
                    "33 1 36 0 35 47 46 48 \n"
                    "3 3 4 -1 0 4 0 5 \n"
                    "step 5:\n"
                    "33 1 36 0 35 47 46 48 \n"
                    "3 3 4 -1 0 4 0 5 \n"
                    "step 6:\n"
                    "33 1 36 0 35 47 46 48 \n"
                    "3 3 4 -1 0 4 0 5 \n"
                    "step 7:\n"
                    "33 1 36 0 35 47 46 48 \n"
                    "3 3 4 -1 0 4 0 5 \n"
                    "step 8:\n"
                    "33 1 36 0 35 47 46 48 \n"
                    "3 3 4 -1 0 4 0 5 \n";
    return printResult(output.str(), expect, name);
}