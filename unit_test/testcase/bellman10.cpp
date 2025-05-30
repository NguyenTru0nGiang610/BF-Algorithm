#include "unit_test.hpp"

bool UNIT_TEST::bellman10()
{
    string name = "bellman10";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 6;
    int G1[num_vertices][num_vertices] = {
        {0,82,36,83,45,65},
        {78,0,84,76,63,89},
        {55,66,0,34,51,72},
        {20,23,56,78,91,34},
        {93,41,15,26,0,79},
        {62,92,12,1,61,0}
    };
    int G2[num_vertices][num_vertices] = {
        {100,44,38,56,66,71},
        {67,30,33,70,83,92},
        {43,50,70,23,25,59},
        {69,71,65,90,98,56},
        {50,70,38,41,70,78},
        {64,38,24,67,91,60},
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D', 'X', 'Y'};

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

    int BellmanFordValue[20];
    int BellmanFordPrevious[20];

    for(int i = 0; i < num_vertices; i++){
        BellmanFordValue[i] = -1;
        BellmanFordPrevious[i] = -1;
    }

    for(int i = 0; i < num_vertices; i++){
        if (i % 2 == 0) {
            BF(edge1, numberOfEdges1, 'D', BellmanFordValue, BellmanFordPrevious);
        } else {
            BF(edge2, numberOfEdges2, 'A', BellmanFordValue, BellmanFordPrevious);
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
                    "20 23 56 0 91 34 \n" 
                    "3 3 3 -1 3 3 \n"
                    "step 2:\n"
                    "20 23 56 0 81 34 \n"
                    "3 3 3 -1 2 3 \n" 
                    "step 3:\n"
                    "20 23 46 0 65 34 \n"
                    "3 3 5 -1 0 3 \n" 
                    "step 4:\n"
                    "20 23 46 0 65 34 \n" 
                    "3 3 5 -1 0 3 \n"
                    "step 5:\n"
                    "20 23 46 0 65 34 \n"
                    "3 3 5 -1 0 3 \n"
                    "step 6:\n"
                    "20 23 46 0 65 34 \n"
                    "3 3 5 -1 0 3 \n";
    return printResult(output.str(), expect, name);
}