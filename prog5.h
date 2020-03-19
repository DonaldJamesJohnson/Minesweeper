	/*
  prog5.h
  Donald Johnson 
  CSCI 501
  10-11-18
  
  Header file for prog5
*/
#ifndef __PROG5_H__
#define __PROG5_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iomanip>
using namespace std;


const string iFile = "/home/cs501/progs/18f/p5/prog5.d";
const int SEED = 1;

void buildMineField (vector< vector <bool> >& mines, const double& mineProb);
void fixCounts (const vector< vector <bool> >& mines, vector < vector <unsigned> >& counts);
void displayMineLocations (const vector < vector <bool> >& mines);
void displayMineCounts (const vector < vector <unsigned> >& counts);

#endif
