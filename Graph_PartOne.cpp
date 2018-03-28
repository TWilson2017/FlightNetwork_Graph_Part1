//------------------------------------------------------------------
// File name:   Graph_PartOne.cpp
// Assign ID:   Project 5A
// Due Date:    3/22/18 at 12:30 pm
//
// Purpose:     Write a C++ program that creates an adjacency matrix
//			    to represent ALL of the routes depicted in the given 
//				adjacency matrix.
//              
// Author:      Tishauna Wilson
//------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "AdjacencyMatrix.cpp"
using namespace std;

int main()
{
   //Declare Variables
   AdjacencyMatrix Data; //Object for AdjacencyMatrix
	
   //-| ----------------------------------------------------------------------
   //-| Print the copyright notice declaring authorship.
   //-| ----------------------------------------------------------------------
   cout << endl << "(c) 2018, Tishauna Wilson" << endl << endl; 
	
   //-|---------------------------------
   //-|1. Call the CreateGraph Function
   //-|---------------------------------
   Data.CreateGraph();
	
   //-|---------------------------------
   //-|2. Call the Print_Graph Function
   //-|---------------------------------
   Data.Print_Graph();
	
   //-| ----------------------------------------------------------------------
   //-| Print the copyright notice declaring authorship again.
   //-| ----------------------------------------------------------------------
   cout << endl << "(c) 2018, Tishauna Wilson" << endl << endl; 
   return 0;
}//main