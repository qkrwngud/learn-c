#include <iostream>
#include <vector>
#include <algorithm>

const int MapSize = 5;

int Map[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 1, 6, 1, 1},
    {4, 1, 6, 1, 9},
    {1, 1, 6, 1, 1},
    {1, 1, 1, 1, 1}
};

int FirstSNode[2] = { 0, };

int SNode[2] = { 0, };
int ENode[2] = { 0, };

const int SL[2][4] = { // 직선
    {1, -1, 0, 0},
    {0, 0, 1, -1}
};

const int DL[2][4] = { // 대각선
    {1, 1, -1, -1},
    {1, -1, 1, -1}
};

class Node {

private:
    int SNodeX;
    int SNodeY;

    std::vector<int> x;
    std::vector<int> y;

    std::vector<int> F;
    std::vector<int> G;
    std::vector<int> H;

public:
    Node(int arr[2]) : SNodeX(arr[0]), SNodeY(arr[1]) {} // arr[x][y] 시작 위치 배열

    void SetNode()
    {
        int SLArr[2] = { 0, };
        int DLArr[2] = { 0, };

        for (int i = 0; i < 4; ++i) {
            SLArr[0] = SNodeX + SL[0][i];
            SLArr[1] = SNodeY + SL[1][i];
            DLArr[0] = SNodeX + DL[0][i];
            DLArr[1] = SNodeY + DL[1][i];

            if (SLArr[0] > -1 && SLArr[1] > -1)
            {
                if (Map[SLArr[0]][SLArr[1]] == 1 || Map[SLArr[0]][SLArr[1]] == 9)
                {
                    x.push_back(SNodeX + SL[0][i]);
                    y.push_back(SNodeY + SL[1][i]);
                    G.push_back(10);
                    Map[x[i]][y[i]] = 1;
                }
            }

            if (DLArr[0] > -1 && DLArr[1] > -1)
            {
                if (Map[DLArr[0]][DLArr[1]] == 1 || Map[DLArr[0]][DLArr[1]] == 9)
                {
                    x.push_back(SNodeX + DL[0][i]);
                    y.push_back(SNodeY + DL[1][i]);
                    G.push_back(14);
                    Map[x[i]][y[i]] = 1;
                }
            }
        }
    }

    bool bEndNode()
    {
        for (auto& i : x) {
            if (i == ENode[0])
            {
                for (auto& j : y) {
                    if (j == ENode[1])
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void Calculate()
    {
        if (F.empty() && H.empty())
        {
            for (int i = 0; i < x.size(); ++i)
            {
                H.push_back((abs(x[i] - ENode[0]) + abs(y[i] - ENode[1])) * 10);
            }
            for (int i = 0; i < G.size(); ++i)
            {
                F.push_back(H[i] + G[i]);
            }
        }
    }

    void MinNode()
    {
        auto Min = std::min_element(F.begin(), F.end()) - F.begin();

        Map[x[Min]][y[Min]] = 4;

        SNode[0] = x[Min];
        SNode[1] = y[Min];
    }
};

class Astar {

public:

    Astar()
    {
        for (int i = 0; i < MapSize; ++i) {
            for (int j = 0; j < MapSize; ++j)
            {
                if (Map[i][j] == 4)
                {
                    FirstSNode[0] = i;
                    FirstSNode[1] = j;
                    SNode[0] = i;
                    SNode[1] = j;
                }
                else if (Map[i][j] == 9)
                {
                    ENode[0] = i;
                    ENode[1] = j;
                }
            }
        }
    }

    void Search()
    {
        int i = 0;
        while (i < 100)
        {
            Node* node = new Node(SNode);

            node->SetNode();
            node->Calculate();
            node->MinNode();

            if (node->bEndNode())
            {
                break;
            }
            
            ++i;
        }
    }

    void PrintMap()
    {
        Map[FirstSNode[0]][FirstSNode[1]] = 4;

        for (int i = 0; i < MapSize; ++i) {
            for (int j = 0; j < MapSize; ++j) {
                if (Map[i][j] == 6) std::cout << "■ ";
                else if (Map[i][j] == 4) std::cout << "★ ";
                else std::cout << "  ";

            }
            std::cout << '\n';
        }
    }
};

int main() {

    Astar* A = new Astar();
    A->Search();
    A->PrintMap();

    return 0;
}
