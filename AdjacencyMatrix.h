#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

//Adjacency Matrix Class
class AdjacencyMatrix
{
    private:
		int V; //Variable for Vertex
		int E; //Variable for Edge
		int **Adjacency; //Two Dimensional Matrix
		bool *visited; //Variable to track when a node was visted 
		static const int rows_cols_size = 37; //Variable for # of Rows & Cols
		string *Origin_RowName; //Array for Origin Name
                string *Destination_ColName; //Array for Destination Name
		
    public:
	//Initialize Constructor
        AdjacencyMatrix();
	//Create Graph
        void CreateGraph();
	//Print Graph
        void Print_Graph();
};
#endif
