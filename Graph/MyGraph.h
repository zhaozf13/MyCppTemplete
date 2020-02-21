#ifndef MYGRAPH_H
#define MYGRAPH_H


class MyGraph
{
    public:
        MyGraph();
        void InsertVertex(char v);
        virtual ~MyGraph();


    private:
        int MaxVertex;
        int NumVertex;
        int NumEdge;
        char *Vertex;
        int **Edge;
};

#endif // MYGRAPH_H
