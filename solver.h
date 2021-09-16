#ifndef soduko_solver
#define soduko_solver
#include <iostream>
using namespace std;

class solver {
	private:
	int grid[9][9];
	void create_grid(const char* file);
	bool is_valid(int,int,int);
	bool find_empty(int&, int&);
	void print();
	bool solve();
    public:
		solver(const char* file){
			create_grid (file);
			if (solve()){
				cout << "Soduko Puzzle has been Solved!"<<endl;
				print();}
			else
				cout << "Soduko Puzzle Could Not Be Solved"<<endl;
			}
};
#endif
