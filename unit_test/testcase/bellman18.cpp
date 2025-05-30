#include "unit_test.hpp"

bool UNIT_TEST::bellman18()
{
    string name = "bellman18";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 5;
    int G1[num_vertices][num_vertices] = {
        {3328, 7518, 7969, 9128, 0},
        {7928, 0, 6371, 1361, 8327},
        {372, 1065, 0, 2595, 9249},
        {1018, 221, 6074, 0, 5086},
        {0, 5217, 8606, 6364, 1012}
    };

    char vertex[num_vertices] = {'Z', 'B', 'C', 'D', 'A'};

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
    string end = "Z";

    int BellmanFordValue[20];
    int BellmanFordPrevious[20];

    for (int i = 0; i < num_vertices; i++)
    {
        BellmanFordValue[i] = -1;
        BellmanFordPrevious[i] = -1;
    }

    for (int i = 0; i < num_vertices; i++)
    {
        BF(edge1, numberOfEdges1, 'A', BellmanFordValue, BellmanFordPrevious);

        output << "step " << i + 1 << ":" << endl;
        for (int j = 0; j < num_vertices; j++)
        {
            output << BellmanFordValue[j] << " ";
        }
        output << endl;
        for (int j = 0; j < num_vertices; j++)
        {
            output << BellmanFordPrevious[j] << " ";
        }
        output << endl;
    }

    string result = BF_Path(edge1, numberOfEdges1, start[0], end[0]);

    output << "Result: " << result;

    //! ---- EXPECT --------
    string expect = "step 1:\n"
                    "0 5217 8606 6364 -1 \n"
                    "-1 0 0 0 -1 \n"
                    "step 2:\n"
                    "0 5217 8606 6364 7382 \n"
                    "-1 0 0 0 3 \n"
                    "step 3:\n"
                    "0 5217 8606 6364 7382 \n"
                    "-1 0 0 0 3 \n"
                    "step 4:\n"
                    "0 5217 8606 6364 7382 \n"
                    "-1 0 0 0 3 \n"
                    "step 5:\n"
                    "0 5217 8606 6364 7382 \n"
                    "-1 0 0 0 3 \n"
                    "Result: A D Z";
    return printResult(output.str(), expect, name);
}