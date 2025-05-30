#include "unit_test.hpp"

bool UNIT_TEST::bellman14()
{
    string name = "bellman14";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 9;
    int G1[num_vertices][num_vertices] = {
        {0, 78, 71, 16, 53, 30, 85, 31, 59},
        {57, 0, 2, 6, 96, 62, 39, 75, 17},
        {34, 89, 0, 90, 88, 55, 45, 10, 57},
        {23, 5, 29, 0, 92, 16, 53, 2, 95},
        {76, 18, 48, 6, 0, 56, 32, 17, 65},
        {86, 23, 61, 48, 14, 0, 88, 17, 48},
        {30, 7, 89, 85, 53, 99, 0, 43, 28},
        {56, 24, 20, 73, 77, 75, 20, 0, 5},
        {45, 20, 11, 1, 4, 80, 67, 90, 0}
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D', 'O', 'W', 'X', 'Y', 'Z'};

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

    int BellmanFordValue[20];
    int BellmanFordPrevious[20];

    for(int i = 0; i < num_vertices; i++){
        BellmanFordValue[i] = -1;
        BellmanFordPrevious[i] = -1;
    }

    for(int i = 0; i < num_vertices; i++){
        BF(edge1, numberOfEdges1, 'B', BellmanFordValue, BellmanFordPrevious);
        
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
                    "57 0 2 6 96 62 39 75 17 \n"
                    "1 -1 1 1 1 1 1 1 1 \n"
                    "step 2:\n"
                    "29 0 2 6 21 22 39 8 17 \n"
                    "3 -1 1 1 8 3 1 3 1 \n" 
                    "step 3:\n"
                    "29 0 2 6 21 22 28 8 13 \n"
                    "3 -1 1 1 8 3 7 3 7 \n" 
                    "step 4:\n"
                    "29 0 2 6 17 22 28 8 13 \n" 
                    "3 -1 1 1 8 3 7 3 7 \n"
                    "step 5:\n"
                    "29 0 2 6 17 22 28 8 13 \n"
                    "3 -1 1 1 8 3 7 3 7 \n"
                    "step 6:\n"
                    "29 0 2 6 17 22 28 8 13 \n"
                    "3 -1 1 1 8 3 7 3 7 \n"
                    "step 7:\n"
                    "29 0 2 6 17 22 28 8 13 \n" 
                    "3 -1 1 1 8 3 7 3 7 \n"
                    "step 8:\n"
                    "29 0 2 6 17 22 28 8 13 \n"
                    "3 -1 1 1 8 3 7 3 7 \n"
                    "step 9:\n"
                    "29 0 2 6 17 22 28 8 13 \n"
                    "3 -1 1 1 8 3 7 3 7 \n";
    return printResult(output.str(), expect, name);
}