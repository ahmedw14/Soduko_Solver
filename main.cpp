#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
#include "solver.h"  // The SudokuSolver class.

void check_file (const char *file){
	int NUM=9;
	ifstream in_file;
	in_file.open (file);
	
	if (in_file.fail()){
		cout << "Error, Cannot open file" << endl;
		exit(1);
	}
	string line;
	int i=0;
	while (getline(in_file,line)){
		if (i>8|| NUM+1 != int(line.length())){
			cout << "invalid Soduko input"<< endl;
			exit(1);
		}
	for (int j=0; j<int(line.length())-1;j++){
		if((!isdigit(line[j]))){
			cout << "invalid Soduko input"<< endl;
			exit(1); } 
		}
	
		i++;
	}
}
int main(){
	//auto start = chrono::steady_clock::now();
	check_file ("input.txt");
	solver s("input.txt");
	//auto end = chrono::steady_clock::now();
	//auto diff = end - start;
	//cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    return 0;
}
