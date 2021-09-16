#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "solver.h"
using namespace std;

void solver::create_grid(const char* file){
	ifstream in_file;
	in_file.open ("input.txt");
	string line;
	for (int i=0; i<9; i++){ //Converting user input into a grid of integers 
		in_file>>line;
		for (int j=0; j<9;j++)
			grid[i][j]=line[j]-'0'; 	
		
	}
	
}
	
bool solver::is_valid(int row, int col, int num)
{
   	for (int i=0; i<9;i++) //check row
		if( grid[row][i]==num )
			return false;
			
	for (int j=0; j < 9;j++) //check column
		if( grid[j][col]==num )
			return false;
	
	int threebythree_row =row - (row%3);
	int threebythree_column =  col - (col%3);
	
	for (int i = 0; i < 3; i++)   //check_box
        for (int j = 0; j < 3; j++)
            if (grid[i+threebythree_row][j+threebythree_column] == num) 
                return false;
	
	
	return true;
}

bool solver::find_empty(int &row, int &col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

bool solver::solve()
{
	int row,col;
    if (!find_empty(row,col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
    if (is_valid(row,col,num))
    {
        grid[row][col] = num;
        if (solve())
			return true;
        grid[row][col] = 0;
    }
    }
   
    return false;
}

void solver::print(){
	for( int i= 0 ; i< 9 ; i++ ){
		if (i%3==0 && i!=0)
			cout << " - - - - - - - - - - - - "<<endl;
		for( int j = 0 ; j < 9; j++ ){
			if (j%3==0 && j!=0)
				cout<<" | ";
			cout <<" "<<grid[i][j];
		}
		cout<<endl;
	}
	return;
}

