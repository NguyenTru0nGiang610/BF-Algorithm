#include "unit_test.hpp"

bool UNIT_TEST::bellman03()
{
    string name = "bellman03";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 4;
    int G[num_vertices][num_vertices] = {
        {0, 1, 4, 0},
        {0, 0, 2, 6},
        {0, 0, 0, 3},
        {0, 0, 0, 0}
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D'};

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

    char start = 'A';

    int value_arr[20];
    int prev_arr[20];
    for (int i = 0; i < num_vertices; i++)
    {
        value_arr[i] = -1;
        prev_arr[i] = -1;
    }

    // Lặp num_vertices lần để BF hội tụ
    for (int i = 0; i < num_vertices; i++)
    {
        BF(edge, numberOfEdges, start, value_arr, prev_arr);
    }

    // In ra giá trị chi phí từ A đến từng đỉnh
    for (int i = 0; i < num_vertices; i++)
    {
        output << "Value[" << char('A' + i) << "] = " << value_arr[i] << ", Prev[" << char('A' + i) << "] = " << (prev_arr[i] == -1 ? '-' : char('A' + prev_arr[i])) << "\n";
    }

    //! ---- EXPECT --------
    string expect =
        "Value[A] = 0, Prev[A] = -\n"
        "Value[B] = 1, Prev[B] = A\n"
        "Value[C] = 3, Prev[C] = B\n"
        "Value[D] = 6, Prev[D] = C\n";
    return printResult(output.str(), expect, name);
}