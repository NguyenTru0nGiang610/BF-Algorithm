#include "unit_test.hpp"

bool UNIT_TEST::bellman15()
{
    string name = "bellman15";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 4;
    int G1[num_vertices][num_vertices] = {
        {0, 43, 58, 33},
        {97, 0, 67, 5},
        {6, 24, 0, 84},
        {63, 85, 82, 0}
    };
    int G2[num_vertices][num_vertices] = {
        {0, 72, 39, 6},
        {76, 0, 61, 18},
        {20, 6, 0, 98},
        {59, 50, 75, 0}
    };
    int G3[num_vertices][num_vertices] = {
        {0, 52, 64, 63},
        {64, 0, 83, 67},
        {50, 99, 0, 49},
        {61, 34, 9, 0}
    };
    int G4[num_vertices][num_vertices] = {
        {0, 45, 38, 27},
        {1, 0, 45, 56},
        {60, 16, 0, 92},
        {54, 40, 51, 0}
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D'};
    char vertex4[num_vertices] = {'O', 'P', 'S', 'U'};

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

    int edge2[num_vertices*num_vertices][3];
    int numberOfEdges2 = 0;
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (G2[i][j] > 0)
            {
                edge2[numberOfEdges2][0] = vertex[i];
                edge2[numberOfEdges2][1] = vertex[j];
                edge2[numberOfEdges2][2] = G2[i][j];
                numberOfEdges2++;
            }
        }
    }

    int edge3[num_vertices*num_vertices][3];
    int numberOfEdges3 = 0;
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (G3[i][j] > 0)
            {
                edge3[numberOfEdges3][0] = vertex[i];
                edge3[numberOfEdges3][1] = vertex[j];
                edge3[numberOfEdges3][2] = G3[i][j];
                numberOfEdges3++;
            }
        }
    }

    int edge4[num_vertices*num_vertices][3];
    int numberOfEdges4 = 0;
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (G4[i][j] > 0)
            {
                edge4[numberOfEdges4][0] = vertex4[i];
                edge4[numberOfEdges4][1] = vertex4[j];
                edge4[numberOfEdges4][2] = G4[i][j];
                numberOfEdges4++;
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
        if (i % 4 == 0) {
            BF(edge1, numberOfEdges1, 'D', BellmanFordValue, BellmanFordPrevious);
        } else if (i % 4 == 1) {
            BF(edge2, numberOfEdges2, 'A', BellmanFordValue, BellmanFordPrevious);
        } else if (i % 4 == 2) {
            BF(edge3, numberOfEdges3, 'B', BellmanFordValue, BellmanFordPrevious);
        } else {
            BF(edge4, numberOfEdges4, 'S', BellmanFordValue, BellmanFordPrevious);
        }
        
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
                    "63 85 82 0 \n" 
                    "3 3 3 -1 \n"
                    "step 2:\n"
                    "59 50 75 0 \n"
                    "3 3 3 -1 \n" 
                    "step 3:\n"
                    "59 34 9 0 \n"
                    "3 3 3 -1 \n" 
                    "step 4:\n"
                    "35 25 9 0 \n" 
                    "1 2 3 -1 \n";
    return printResult(output.str(), expect, name);
}