#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;
#define UNASSIGNED 0
#define N 9

bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
bool isSafe(int grid[N][N], int row, int col, int num);

/* assign values to all unassigned locations for Sudoku solution  
 */
bool SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
    if (isSafe(grid, row, col, num))
    {
        grid[row][col] = num;
        if (SolveSudoku(grid))
            return true;
        grid[row][col] = UNASSIGNED;
    }
    }
   
    return false;
}

/* Searches the grid to find an entry that is still unassigned. */
bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
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

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout<<grid[row][col]<<"  ";
        cout<<endl;
    }
}

int main()
{
	ifstream in_file;
	in_file.open ("input.txt");
	string line;
	int count=0;//to check that there are at least 17 known numbers
	int grid[N][N];	
	for (int i=0; i<9; i++){ //Converting user input into a Vector 
		in_file>>line;
		for (int j=0; j<9;j++){
			grid[i][j]=line[j]-'0'; 
			if (grid[i][j] != 0)
				count++;	
		}
	}
	
    
    SolveSudoku(grid);
    printGrid(grid);
//cout<<"No solution exists"<<endl;
    return 0;
}
