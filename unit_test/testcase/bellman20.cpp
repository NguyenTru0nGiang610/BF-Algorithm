#include "unit_test.hpp"

bool UNIT_TEST::bellman20()
{
    string name = "bellman20";
    stringstream output;
    //! ---- DATA --------
    int num_vertices = 15;
    int G1[num_vertices][num_vertices] = {
        {0, 99, 77, 44, 8, 21, 15, 76, 86, 94, 24, 76, 86, 7, 46},
        {88, 0, 97, 52, 4, 19, 29, 69, 44, 39, 33, 76, 24, 57, 95},
        {58, 38, 0, 6, 57, 67, 51, 17, 40, 18, 93, 26, 12, 17, 55},
        {50, 77, 1, 0, 39, 74, 53, 43, 46, 34, 12, 90, 74, 45, 18},
        {50, 54, 13, 8, 0, 45, 72, 17, 12, 75, 35, 53, 93, 28, 31},
        {6, 98, 38, 56, 75, 0, 92, 47, 1, 97, 91, 99, 32, 55, 89},
        {58, 53, 59, 60, 59, 73, 0, 69, 4, 45, 38, 69, 72, 73, 74},
        {65, 2, 57, 23, 0, 96, 32, 0, 27, 40, 79, 28, 37, 22, 28},
        {69, 78, 69, 79, 83, 29, 40, 42, 0, 54, 61, 99, 51, 99, 20},
        {23, 73, 94, 40, 27, 51, 64, 27, 99, 0, 96, 6, 39, 75, 86},
        {77, 50, 66, 98, 80, 36, 78, 63, 17, 70, 0, 57, 23, 31, 8},
        {26, 30, 28, 1, 55, 22, 41, 82, 26, 5, 61, 0, 77, 1, 67},
        {69, 29, 6, 46, 79, 72, 96, 11, 60, 26, 74, 29, 0, 96, 83},
        {52, 79, 92, 30, 10, 20, 31, 65, 95, 73, 0, 73, 78, 0, 61},
        {50, 32, 81, 71, 13, 87, 69, 44, 59, 66, 55, 72, 44, 81, 0}
    };
    int G2[num_vertices][num_vertices] = {
        {0, 84, 45, 82, 68, 1, 73, 27, 95, 18, 65, 51, 43, 69, 23},
        {56, 0, 46, 17, 12, 16, 25, 10, 70, 32, 89, 69, 36, 66, 24},
        {31, 99, 0, 19, 15, 44, 53, 35, 46, 79, 63, 93, 49, 80, 44},
        {93, 2, 19, 0, 1, 48, 88, 65, 16, 14, 75, 86, 98, 16, 8},
        {34, 82, 84, 17, 0, 81, 55, 85, 78, 60, 20, 76, 39, 35, 21},
        {89, 16, 18, 34, 70, 0, 37, 87, 18, 26, 52, 86, 92, 79, 72},
        {90, 95, 32, 25, 30, 16, 0, 42, 11, 71, 79, 41, 84, 0, 69},
        {23, 35, 91, 64, 3, 9, 98, 0, 73, 46, 37, 43, 24, 41, 29},
        {16, 20, 54, 59, 16, 38, 84, 46, 0, 55, 78, 9, 78, 58, 3},
        {62, 10, 72, 38, 45, 63, 2, 1, 72, 0, 53, 74, 71, 42, 70},
        {95, 84, 51, 64, 4, 5, 23, 72, 96, 59, 0, 18, 3, 89, 80},
        {33, 99, 83, 96, 9, 7, 86, 7, 71, 40, 8, 0, 95, 45, 34},
        {18, 88, 56, 14, 72, 8, 30, 28, 65, 53, 1, 61, 0, 12, 71},
        {64, 1, 51, 98, 1, 86, 46, 62, 94, 84, 69, 17, 24, 0, 29},
        {12, 70, 16, 31, 58, 72, 97, 82, 32, 27, 10, 98, 80, 63, 0}
    };

    char vertex[num_vertices] = {'O','N', 'M', 'L','K', 'J', 'I', 'H', 'G', 'F' ,'E', 'D', 'C', 'B', 'A'};

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
            BF(edge1, numberOfEdges1, char('A' + i), BellmanFordValue, BellmanFordPrevious);
        } else {
            BF(edge2, numberOfEdges2, char('A'+ i%12), BellmanFordValue, BellmanFordPrevious);
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

    for(int i = 0; i < num_vertices; i++){
        output << "Path from C to " << char('A' + i) << ": ";
        string result = BF_Path(edge1, numberOfEdges1, 'C', char('A' + i));
        output << result << endl;
    }

    //! ---- EXPECT --------
    string expect = "step 1:\n"
                    "0 81 44 72 55 66 59 44 69 87 13 71 81 32 50 \n"
                    "-1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n"
                    "step 2:\n"
                    "0 48 44 68 10 27 32 42 57 48 13 30 16 32 12 \n"
                    "-1 10 0 6 0 0 0 13 13 13 0 10 0 0 0 \n"
                    "step 3:\n"
                    "0 19 28 33 10 27 25 30 27 33 13 21 16 32 12 \n"
                    "-1 14 12 5 0 0 10 10 14 14 0 10 0 0 0 \n"
                    "step 4:\n"
                    "0 19 13 28 10 27 25 28 27 13 13 21 16 20 12 \n"
                    "-1 14 4 4 0 0 10 5 14 14 0 10 0 1 0 \n"
                    "step 5:\n"
                    "0 19 13 28 10 27 14 24 27 13 13 21 16 20 12 \n"
                    "-1 14 4 4 0 0 9 2 14 14 0 10 0 1 0 \n"
                    "step 6:\n"
                    "0 19 13 23 10 27 14 24 27 13 13 21 16 20 12 \n"
                    "-1 14 4 6 0 0 9 2 14 14 0 10 0 1 0 \n"
                    "step 7:\n"
                    "0 19 13 23 10 27 14 24 27 13 13 21 16 20 12 \n"
                    "-1 14 4 6 0 0 9 2 14 14 0 10 0 1 0 \n"
                    "step 8:\n"
                    "0 19 13 23 10 27 14 24 27 13 13 21 16 20 12 \n"
                    "-1 14 4 6 0 0 9 2 14 14 0 10 0 1 0 \n"
                    "step 9:\n"
                    "0 19 13 23 10 27 14 24 27 13 13 21 16 20 12 \n"
                    "-1 14 4 6 0 0 9 2 14 14 0 10 0 1 0 \n"
                    "step 10:\n"
                    "0 19 13 23 10 27 14 24 27 13 13 21 16 20 12 \n"
                    "-1 14 4 6 0 0 9 2 14 14 0 10 0 1 0 \n"
                    "step 11:\n"
                    "0 19 13 23 10 27 14 24 27 13 13 21 16 20 12 \n"
                    "-1 14 4 6 0 0 9 2 14 14 0 10 0 1 0 \n"
                    "step 12:\n"
                    "0 19 13 23 10 27 14 24 27 13 13 21 16 20 12 \n"
                    "-1 14 4 6 0 0 9 2 14 14 0 10 0 1 0 \n"
                    "step 13:\n"
                    "0 19 13 23 10 27 14 24 27 13 13 21 16 20 12 \n"
                    "-1 14 4 6 0 0 9 2 14 14 0 10 0 1 0 \n"
                    "step 14:\n"
                    "0 19 13 23 10 27 14 24 27 13 13 21 16 20 12 \n"
                    "-1 14 4 6 0 0 9 2 14 14 0 10 0 1 0 \n"
                    "step 15:\n"
                    "0 19 13 23 10 27 14 24 27 13 13 21 16 20 12 \n"
                    "-1 14 4 6 0 0 9 2 14 14 0 10 0 1 0 \n"
                    "Path from C to A: C M L A\n"
                    "Path from C to B: C M B\n"
                    "Path from C to C: C\n"
                    "Path from C to D: C D\n"
                    "Path from C to E: C M L E\n"
                    "Path from C to F: C M F\n"
                    "Path from C to G: C H N K G\n"
                    "Path from C to H: C H\n"
                    "Path from C to I: C H N I\n"
                    "Path from C to J: C H N J\n"
                    "Path from C to K: C H N K\n"
                    "Path from C to L: C M L\n"
                    "Path from C to M: C M\n"
                    "Path from C to N: C H N\n"
                    "Path from C to O: C H N J O\n";
    return printResult(output.str(), expect, name);
}