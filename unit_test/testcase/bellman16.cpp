#include "unit_test.hpp"

bool UNIT_TEST::bellman16()
{
    string name = "bellman16";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 11;
    int G1[num_vertices][num_vertices] = {
        {0, 7294, 9242, 8090, 2047, 943, 7132, 2592, 3150, 2487, 1322},
        {4750, 0, 1926, 1959, 9342, 6594, 6304, 5736, 91, 5609, 9124},
        {1572, 5054, 0, 7119, 9887, 16, 158, 375, 2826, 8214, 1443},
        {2204, 1861, 7037, 0, 294, 3908, 7981, 3778, 2852, 1131, 6266},
        {527, 2233, 4544, 2486, 0, 7927, 7491, 5142, 3663, 3934, 7104},
        {9139, 5506, 2158, 6258, 1746, 0, 8526, 2769, 2121, 1352, 7335},
        {3565, 3557, 9196, 602, 203, 9457, 0, 4935, 3982, 8661, 2418},
        {6600, 9188, 1004, 7496, 8027, 8931, 4987, 0, 9521, 8947, 5274},
        {6625, 8086, 780, 8783, 697, 2526, 3662, 9818, 0, 1000, 5014},
        {7153, 4565, 4923, 6350, 1519, 1479, 2159, 2807, 5461, 0, 820},
        {5225, 8413, 6361, 6229, 5909, 4388, 1513, 7249, 3909, 460, 0}
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'Q', 'R', 'S'};

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
        BF(edge1, numberOfEdges1, start, value_arr, prev_arr);
    }

    // In ra giá trị chi phí từ A đến từng đỉnh
    for (int i = 0; i < num_vertices; i++)
    {
        output << "Value[" << char('A' + i) << "] = " << value_arr[i] << ", Prev[" << char('A' + i) << "] = " << (prev_arr[i] == -1 ? '-' : char('A' + prev_arr[i])) << "\n";
    }

    //! ---- EXPECT --------
    string expect =
        "Value[A] = 0, Prev[A] = -\n"
        "Value[B] = 4280, Prev[B] = E\n"
        "Value[C] = 3101, Prev[C] = F\n"
        "Value[D] = 3437, Prev[D] = G\n"
        "Value[E] = 2047, Prev[E] = A\n"
        "Value[F] = 943, Prev[F] = A\n"
        "Value[G] = 2835, Prev[G] = K\n"
        "Value[H] = 2592, Prev[H] = A\n"
        "Value[I] = 3064, Prev[I] = F\n"
        "Value[J] = 1782, Prev[J] = K\n"
        "Value[K] = 1322, Prev[K] = A\n";
    return printResult(output.str(), expect, name);
}