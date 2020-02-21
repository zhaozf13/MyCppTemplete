#include "MyGraph.h"
#define SIZE 10

MyGraph::MyGraph()
{
    //初始化
    MaxVertex = SIZE;
    NumVertex = NumEdge = 0;//顶点数和边数初始化为0
    Vertex = new char[MaxVertex];
    Edge = new int*[MaxVertex];//int *Edge[10];
    int i,j;
    for(i = 0;i<MaxVertex;i++){
        Edge[i] = new int[MaxVertex]; //Edge[10][10]
    }
    for(i = 0;i<MaxVertex;i++){
        for(j = 0;j<MaxVertex;j++){
            Edge[i][j] = 0;
        }
    }
}

void MyGraph::InsertVertex(char v){
    if(NumVertex >= MaxVertex)
			return;
    Vertex[NumVertex++] = v;
}

MyGraph::~MyGraph()
{
    //dtor
}
