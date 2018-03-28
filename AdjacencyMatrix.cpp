#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include "AdjacencyMatrix.h"
#include <iomanip>
//-|----------------------------------------
//-| 1. Initialize Adjacency Matrix Graph 
//-|----------------------------------------
AdjacencyMatrix :: AdjacencyMatrix()
{	
	//Create an Array of Origin & Destination City Names
	static string Array_Names[rows_cols_size] = {"Miami", "Tampa", "Key West", "Melbourne", "Jacksonville", "Atlanta",	
						     "Birmingham", "Tallahassee", "Charleston", "Memphis", "Columbia", "Little Rock", 	
						     "Jackson", "Mobile", "Fort Worth", "Sheveport", "Greenville", "Nashville", "Tulsa",
						     "Morristown", "New Orleans", "Norman", "Seattle", "Spokane",	
						     "Missoula", "Great Falls", "Portland", "Pendleton", "Medford", "Glassgow", "Boise",
						     "Eureka", "Sacremento", "Reno", "Las Vegas", "Billings", "Bismarck"}; //Array for Origin & Destination Name
	//Create new visited & Adjacency
	visited = new bool [rows_cols_size];
        Adjacency = new int* [rows_cols_size];

	//Assign Array_Names to Origin_RowName & Destination_ColName
	Origin_RowName = Destination_ColName = Array_Names;
	
	//Initialize Adjacency Matrix using nested for-loops
        for (int i = 0; i < rows_cols_size; i++)
        {
		Adjacency[i] = new int [rows_cols_size];
        	for(int j = 0; j < rows_cols_size; j++)
        	{
			Adjacency[i][j] = 0;
        	}//for
    	}//for
}//AdjacencyMatrix

//-|----------------------
//-| 2. Create Graph
//-|----------------------
void AdjacencyMatrix :: CreateGraph()
{
	//Declare Variables
	ifstream inF; //Variable for in-file
	int Route = 0; //Variable for whether there is a route or not
	int origin, destination = 0; //Set Variables for Origin & Destination to Zero
	
	//Open File
	inF.open("Graph_Data.txt");
	
	//Test File For Error
	if(inF.fail())
	{
           cout << endl << "FATAL ERROR: UNABLE TO OPEN FILE \"Graph_Data.txt\". TERMINATING..."
                << endl << endl;
           exit (1);
	}//if
	
	//Else, Read in the Data into the Graph
	else
	{
		//Read in Data .... if origin < rows_cols_size then, break out of loop
		while(inF >> Route && origin < rows_cols_size)
		{
			//Check for if Destination == rows_cols_size
			if(destination == rows_cols_size)
			{				
				//Assign 0 to Destination
				destination = 0;
				
				//Increment origin by 1
				origin++;
			}//if
			
			//Assign Data into Adjacency Matrix
			Adjacency[origin][destination] = Route;
			
			//Increment destination by 1
			destination++;
		}//while
	}//else
	
	//Close InFile
	inF.close();
}//CreateGraph

//-|----------------------
//-| 3. Print Graph
//-|----------------------
void AdjacencyMatrix :: Print_Graph()
{
	//Declare Variables
	ofstream OutF;
	OutF.open("Flight_Map.txt");
	
	OutF << "\t\t\t\t";
	//Print out the Destination Cities
	for(int i = 0; i < rows_cols_size; i++)
		OutF << Destination_ColName[i] << "\t\t\t";
	OutF << endl;
	
	//Print out the Origin Cities & Flight Network
    	for(int i = 0; i < rows_cols_size; i++)
    	{
    		//Print out the Origin City
		OutF << left << Origin_RowName[i];
		OutF << setw(20);
		
		//Print Flight Network
        	for(int j = 0; j < rows_cols_size; j++)
		{
			OutF << right << Adjacency[i][j] << "\t\t\t\t\t";
	        }//2nd-for
		OutF <<endl;
    	}//1st-for
	
    	//Close OutFile
    	OutF.close();
}//Print_Graph
