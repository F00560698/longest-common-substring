// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDistance(int distance[], bool Tset[]);

void DijkstraAlgorithm(int graph[6][6], int src);

int main()
{
    int graph[6][6] = {
        {1, 0, 0, 5, 1, 0},
        {0, 1, 2, 0, 0, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 0, 0, 2, 1, 0},
        {0, 1, 3, 2, 0, 1}};
    DijkstraAlgorithm(graph, 0);

    return 0;
}

int minDistance(int distance[], bool Tset[])
{
    int min = INT_MAX, index;

    for (int a = 0; a < 6; a++)
    {
        if (Tset[a] == false && distance[a] <= min)
        {
            min = distance[a];
            index = a;
        }
    }
    return index;
}

void DijkstraAlgorithm(int graph[6][6], int src)
{
    int distance[6];
    bool Tset[6];

    for (int a = 0; a < 6; a++)
    {
        distance[a] = INT_MAX;
        Tset[a] = false;
    }

    distance[src] = 0;

    for (int a = 0; a < 6; a++)
    {
        int md = minDistance(distance, Tset);
        Tset[md] = true;
        for (int a = 0; a < 6; a++)
        {

            if (!Tset[a] && graph[md][a] && distance[md] != INT_MAX && distance[md] + graph[md][a] < distance[a])
            {
                distance[a] = distance[md] + graph[md][a];
            }
        }
    }
    cout << "Vertex\t  \t  \t Distance from source vertex" << endl;
    for (int a = 0; a < 6; a++)
    {
        char str = 65 + a;
        cout << str << "\t\t\t\t" << distance[a] << endl;
    }
}
