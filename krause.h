//
//  krause.h
//  Assignment 4
//
//  Created by doug krause on 8/15/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "main.h"
#include<string>
using namespace std;


int TimeSort(funcPtr ptrToFunc, int array[]);

void DisplayTime(int timeResult, funcPtr ptrToFunc);

string AssignString(funcPtr ptrToFunc);

void QuickSort(int array[], int lowIdx, int hiIdx);

void GetMedian(int lowIndex, int hiIndex, int array[]);

void SelectionSort(int array[], int lowIndex, int hiIndex);

int GetRepetitions();

int ValidateNum(string repsString);


