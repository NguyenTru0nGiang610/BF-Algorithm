#include "unit_test.hpp"

bool UNIT_TEST::bellman19()
{
    string name = "bellman19";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 8;
    int G1[num_vertices][num_vertices] = {
        {0, 67, 43, 42, 85, 53, 93, 26},
        {83, 0, 89, 89, 21, 10, 79, 66},
        {49, 25, 0, 48, 7, 84, 16, 75},
        {55, 93, 7, 0, 63, 26, 34, 73},
        {42, 52, 1, 9, 0, 47, 43, 94},
        {0, 36, 20, 35, 78, 0, 62, 56},
        {88, 93, 74, 89, 19, 23, 0, 96},
        {3, 91, 23, 58, 36, 30, 21, 0}
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D', 'O', 'S', 'T', 'W'};

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
    string end = "O";

    int BellmanFordValue[20];
    int BellmanFordPrevious[20];

    for(int i = 0; i < num_vertices; i++){
        BellmanFordValue[i] = -1;
        BellmanFordPrevious[i] = -1;
    }

    for(int i = 0; i < num_vertices; i++){
        BF(edge1, numberOfEdges1, 'A', BellmanFordValue, BellmanFordPrevious);
        
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

    string result = BF_Path(edge1, numberOfEdges1, start[0], end[0]);

    output << "Result: " << result;

    //! ---- EXPECT --------
    string expect = "step 1:\n"
                    "0 67 43 42 85 53 93 26 \n"
                    "-1 0 0 0 0 0 0 0 \n"
                    "step 2:\n"
                    "0 67 43 42 50 53 47 26 \n"
                    "-1 0 0 0 2 0 7 0 \n"
                    "step 3:\n"
                    "0 67 43 42 50 53 47 26 \n"
                    "-1 0 0 0 2 0 7 0 \n"
                    "step 4:\n"
                    "0 67 43 42 50 53 47 26 \n"
                    "-1 0 0 0 2 0 7 0 \n"
                    "step 5:\n"
                    "0 67 43 42 50 53 47 26 \n"
                    "-1 0 0 0 2 0 7 0 \n"
                    "step 6:\n"
                    "0 67 43 42 50 53 47 26 \n"
                    "-1 0 0 0 2 0 7 0 \n"
                    "step 7:\n"
                    "0 67 43 42 50 53 47 26 \n"
                    "-1 0 0 0 2 0 7 0 \n"
                    "step 8:\n"
                    "0 67 43 42 50 53 47 26 \n"
                    "-1 0 0 0 2 0 7 0 \n"
                    "Result: A C O";
    return printResult(output.str(), expect, name);
}