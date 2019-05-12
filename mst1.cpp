

#include <iostream>
#include <climits>
#define n 5
int parent[n];
using namespace std;

void printMST(int a[n], int b[n], int weight[n])
{


        cout << weight[n-2];

}

int findParent(int node)
{
    while(parent[node] >= 0)
        node = parent[node];

    return node;
}



int findParentPathCompression(int node)
{
    if(node == parent[node]) return node;
    return parent[node] = findParentPathCompression(parent[node]);
}


void kruskal(int cost[n][n])
{
    fill_n(parent, n, -1);
    int u, v, k = 0, count = 0;
    int firstNode, secondNode;
    int a[n];
    int b[n];
    int weight[n];
    int minimum;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;

    while(count < n-1)
    {
        minimum = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < minimum)
                {
                    minimum = cost[i][j];
                    firstNode = i;
                    secondNode = j;
                }
            }
        }

        u = findParent(firstNode);
        v = findParent(secondNode);


        if (u != v)
        {
            parent[v] = u;
            a[k] = firstNode;
            b[k] = secondNode;
            weight[k] = cost[firstNode][secondNode];
            count++;
            k++;
        }

        cost[firstNode][secondNode] = cost[secondNode][firstNode] = INT_MAX;
    }

    printMST(a, b, weight);
}


int main()
{

    kruskal(cost);
    return 0;
}
