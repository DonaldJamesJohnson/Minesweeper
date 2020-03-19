/*
  prog5.cc
  Donald Johnson
  CSCI 501
  10-11-18
  
  Implementation file for prog5.h
  prog5 creates a minesweeper grid based on a size and probability read in from an input file. It outputs both the mine locations and the number of surrounding mines.
*/
#include "prog5.h"

int main(){ //the main function creates the vectors of vectors "mines" and "counts", reads in the size and prob values from an input file, and calls the necessary functions for creating and outputting the mine and count fields 
    vector<vector<bool> > mines;
    vector<vector<unsigned> > counts;
    unsigned size;
    double prob;
	ifstream infile;
	
	infile.open(iFile.c_str());
	if (!infile){
		cout << "Error could not open file: " << iFile;
		exit(EXIT_FAILURE);
	}
	infile >> size;
	while (infile.good()){
		infile >> prob;

    	mines.resize(size);
    	buildMineField(mines, prob);
		cout << "Mine locations: size = " << size << " x " << size << ", prob of mine = " << fixed << setprecision(2) << prob << endl;
    	displayMineLocations(mines);
    	fixCounts(mines, counts);
    	cout << "Mine counts: " << endl;
    	displayMineCounts(counts);
			
    	infile >> size;
	}	
    return 0;
}

void buildMineField (vector< vector <bool> >& mines, const double& mineProb){ //builds the mine field based on the size of "mines" and value of "mineProb"
	srand(SEED);
	unsigned s = mines.size();
	mines.resize(0);
    for (unsigned i=0; i<s; i++){
    	vector<bool> temp;
    	for (unsigned j=0; j<s; j++){
    		double rnd = rand()/(double(RAND_MAX)+1);
			if (rnd < mineProb){
				temp.push_back(true);
			} else temp.push_back(false);
		}
	    mines.push_back(temp);	
	}
}
void fixCounts (const vector< vector <bool> >& mines, vector < vector <unsigned> >& counts){ //fixes the counts for each position in the minefield based on where the mines are located
	counts.resize(0);	
	for (unsigned i=0; i<mines.size(); i++){
		vector<unsigned> temp;
		for (unsigned j=0; j<mines.size(); j++){
			if (mines[i][j] == 1){
				temp.push_back(1);
			} else if (mines[i][j] == 0) temp.push_back(0);
		}
		counts.push_back(temp);
	}
	cout << endl;
	for (unsigned i=0; i<mines.size(); i++){
		for (unsigned j=0; j<mines.size(); j++){
			if (j > 0){
				if (mines[i][j-1] == 1){
					counts[i][j] = counts[i][j] + 1;
				}
			}
			if (j < mines.size()-1) {
				if (mines[i][j+1] == 1){
					counts[i][j] = counts[i][j] + 1;
				}
			}
			if (i > 0){
				if (mines[i-1][j] == 1){
					counts[i][j] = counts[i][j] + 1;
				}
			}
			if (i < counts.size()-1){
				if (mines[i+1][j]==1){
					counts[i][j] = counts[i][j] + 1;
				}	
			}
			if (i > 0 && j > 0){
				if (mines[i-1][j-1]==1){
					counts[i][j] = counts[i][j] + 1;
				}				
			}
			if (i < counts.size()-1 && j > 0){
				if (mines[i+1][j-1]==1){
					counts[i][j] = counts[i][j] + 1;
				}	
			}
			if (i < counts.size()-1 && j < counts.size()-1){
				if (mines[i+1][j+1]==1){
					counts[i][j] = counts[i][j] + 1;
				}				
			}
			if (i > 0 && j < counts.size()-1){
				if (mines[i-1][j+1]==1){
					counts[i][j] = counts[i][j] + 1;
				}				
			}
		}
	}
}
void displayMineLocations (const vector < vector <bool> >& mines){ //outputs the positions of the mines
	for (unsigned i=0; i<mines.size();i++){
		for (unsigned j=0; j<mines[i].size();j++){
			if (mines[i][j] == 1){
				cout << "|_X_";
			} else cout << "|___";
		}
		cout << "|" << endl;
	}		
}
void displayMineCounts (const vector < vector <unsigned> >& counts){ //outputs the count values for each position in the minefield
	for (unsigned i=0; i<counts.size();i++){
		for (unsigned j=0; j<counts[i].size();j++){
			cout << "|_" << counts[i][j] << "_";
		}
		cout << "|" << endl;
	}
	cout << endl;
}
