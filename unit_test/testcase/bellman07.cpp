#include "unit_test.hpp"

bool UNIT_TEST::bellman07()
{
    string name = "bellman07";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 3;
    int G[num_vertices][num_vertices] = {
        {0,654,856},
        {333,0,840},
        {783,4,0}
    };

    char vertex[num_vertices] = {'A', 'B', 'C'};

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

    for(int i = 0; i < num_vertices; i++){
        BF(edge, numberOfEdges, 'A', BellmanFordValue, BellmanFordPrevious);
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
                    "0 654 856 \n"
                    "-1 0 0 \n"
                    "step 2:\n"
                    "0 654 856 \n"
                    "-1 0 0 \n"
                    "step 3:\n"
                    "0 654 856 \n"
                    "-1 0 0 \n";
    return printResult(output.str(), expect, name);
}