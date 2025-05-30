#include "unit_test.hpp"

bool UNIT_TEST::bellman08()
{
    string name = "bellman08";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 11;
    int G[num_vertices][num_vertices] = {
                {0,807,122,942,77,987,136,288,909,143,500},
                {970,0,724,117,995,704,633,124,410,914,618},
                {539,663,0,817,256,49,866,785,636,870,953},
                {990,29,428,0,284,459,415,773,99,676,916},
                {600,999,993,717,0,994,49,703,118,459,617},
                {88,351,281,905,607,0,682,124,745,671,994},
                {698,661,375,478,298,834,0,893,71,934,922},
                {339,886,921,684,603,267,733,0,658,737,545},
                {276,825,896,909,82,855,943,206,0,600,614},
                {552,651,628,280,481,278,114,375,349,0,48},
                {649,40,286,570,725,890,189,810,900,926,0}
    };

    char vertex[num_vertices] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};

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

    string start = "K";
    string end = "D";

    string result = BF_Path(edge, numberOfEdges, start[0], end[0]);

    output << result;

    //! ---- EXPECT --------
    string expect =
        "K B D";
    return printResult(output.str(), expect, name);
}