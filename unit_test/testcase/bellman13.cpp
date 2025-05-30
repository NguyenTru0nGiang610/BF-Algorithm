#include "unit_test.hpp"

bool UNIT_TEST::bellman13()
{
    string name = "bellman13";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 10;
    int G1[num_vertices][num_vertices] = {
        {0, 39, 10, 14, 17, 3, 77, 27, 60, 9},
        {47, 0, 74, 76, 12, 8, 59, 25, 74, 14},
        {3, 10, 0, 90, 9, 70, 22, 40, 62, 25},
        {39, 46, 43, 0, 77, 85, 6, 43, 55, 9},
        {73, 82, 21, 82, 0, 29, 47, 10, 93, 8},
        {69, 18, 82, 35, 21, 0, 92, 25, 30, 62},
        {47, 71, 77, 24, 10, 75, 0, 68, 39, 61},
        {74, 35, 68, 35, 8, 50, 56, 0, 42, 31},
        {56, 53, 24, 64, 22, 94, 46, 58, 0, 16},
        {38, 35, 98, 52, 35, 21, 81, 59, 32, 0}
    };
    int G2[num_vertices][num_vertices] = {
        {0, 25, 99, 69, 12, 17, 1, 47, 89, 63},
        {30, 0, 87, 69, 8, 23, 85, 71, 47, 94},
        {87, 36, 0, 57, 41, 73, 49, 16, 73, 64},
        {79, 88, 23, 0, 31, 65, 22, 52, 30, 39},
        {54, 77, 80, 69, 0, 7, 68, 90, 16, 91},
        {75, 39, 91, 21, 78, 0, 79, 30, 19, 52},
        {31, 87, 26, 95, 66, 66, 0, 18, 49, 32},
        {93, 54, 14, 84, 8, 91, 65, 0, 29, 51},
        {33, 19, 67, 76, 46, 58, 67, 19, 0, 36},
        {46, 49, 55, 51, 32, 94, 77, 28, 12, 0}
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
            BF(edge1, numberOfEdges1, 'B', BellmanFordValue, BellmanFordPrevious);
        } else {
            BF(edge2, numberOfEdges2, 'C', BellmanFordValue, BellmanFordPrevious);
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
                    "47 0 74 76 12 8 59 25 74 14 \n" 
                    "1 -1 1 1 1 1 1 1 1 1 \n"
                    "step 2:\n"
                    "30 0 39 29 8 8 48 25 26 14 \n"
                    "1 -1 7 5 1 1 0 1 9 1 \n" 
                    "step 3:\n"
                    "30 0 29 29 8 8 35 18 26 14 \n"
                    "1 -1 4 5 1 1 3 4 9 1 \n" 
                    "step 4:\n"
                    "30 0 29 29 8 8 31 18 24 14 \n" 
                    "1 -1 4 5 1 1 0 4 4 1 \n"
                    "step 5:\n"
                    "30 0 29 29 8 8 31 18 24 14 \n"
                    "1 -1 4 5 1 1 0 4 4 1 \n"
                    "step 6:\n"
                    "30 0 29 29 8 8 31 18 24 14 \n"
                    "1 -1 4 5 1 1 0 4 4 1 \n"
                    "step 7:\n"
                    "30 0 29 29 8 8 31 18 24 14 \n"
                    "1 -1 4 5 1 1 0 4 4 1 \n" 
                    "step 8:\n"
                    "30 0 29 29 8 8 31 18 24 14 \n" 
                    "1 -1 4 5 1 1 0 4 4 1 \n"
                    "step 9:\n"
                    "30 0 29 29 8 8 31 18 24 14 \n"
                    "1 -1 4 5 1 1 0 4 4 1 \n"
                    "step 10:\n"
                    "30 0 29 29 8 8 31 18 24 14 \n"
                    "1 -1 4 5 1 1 0 4 4 1 \n";
    return printResult(output.str(), expect, name);
}