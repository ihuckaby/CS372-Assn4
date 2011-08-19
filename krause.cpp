//
//  krause.cpp
//  Assignment 4
//
//  Created by doug krause on 8/15/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "krause.h"
#include <ctime>
#include <iostream>

using namespace std;

const int ARRAY_SIZE = 100000;
const int BASE_INDEX = 0;
const int repsFlag = -1;


/*****************************************************************************
FUNCTION : TimeSort
IMPLEMENTED BY: Doug Krause
DESCRIPTION:		controls flow of one sort test, timing how long it takes
INPUTS:
	Parameters:
        funcPtr			- function pointer to appropriate sort function
		arrayToSort		- the array to be sorted
        arraySize		- size of array
OUTPUTS:
	Returns:
        timeResult		- number of clock ticks the sort took
CALLS TO:
				VerifySort
				BubbleSort
				InsertSort
				MergeSort
				QuickSort
				SelectSort
				ShellSort
				DisplayTime
***************************************************************************/

int TimeSort(funcPtr ptrToFunc, int array[]){
    
    int startTime, stopTime, timeResult;
    
        startTime = clock();
        ptrToFunc(array, BASE_INDEX, ARRAY_SIZE);
        stopTime = clock();
        timeResult = stopTime - startTime;
        
        if (!(VerifySort(array)))
            timeResult = 0;
            
        else 
            DisplayTime(timeResult, ptrToFunc);
            
        return timeResult;
}//end fn

/******************************************************************************
FUNCTION : DisplayTime
IMPLEMENTED BY: Doug Krause
DESCRIPTION:		output timing information for an individual test
INPUTS:
    Parameters:
        ptrToFunc - pointer to sort function used
		timeResult - number of clock ticks
CALLS TO:
    assignString - 
*******************************************************************************/
    
void DisplayTime(int timeResult, funcPtr ptrToFunc){
    
    string sortTypeString;
    
    sortTypeString = AssignString(ptrToFunc);
    
    cout << sortTypeString << " time " << timeResult << "..." << endl;
}
    
/****************************************************************************
FUNCTION : assignString
IMPLEMENTED BY: Doug Krause
DESCRIPTION:		takes in a function pointer and returns a string for output
INPUTS:
	Parameters:
		funcPtr	- pointer to sort function used
OUTPUTS:
	Return:
		sortTypeStr	- string for the appropriate function
***************************************************************************/
string AssignString(funcPtr ptrToFunc){
    
    string sortTypeString;
        
    if (ptrToFunc == BubbleSort) 
        sortTypeString = "Bubble Sort";
    else if (ptrToFunc == InsertionSort)
        sortTypeString = "Insertion Sort";
    else if (ptrToFunc == MergeSort)
        sortTypeString = "Merge Sort";
    else if (ptrToFunc == QuickSort)
        sortTypeString = "Quick Sort";
    else if (ptrToFunc == SelectionSort)
        sortTypeString = "SelectionSort";
    else if (ptrToFunc == ShellSort)
        sortTypeString = "Shell Sort";
    else
        cout << endl << "ERROR" << endl;
    
    return sortTypeString;
}
    

/******************************************************************************   
FUNCTION: QuickSort
DESCRIPTION: performs quick sort on received integer array
INPUT:  
  Parameters:
     array[] - array to be sorted
     lowIdx - location of low element in list being sorted
     hiIdx - location of high element in list being sorted
OUTPUT: 
  Parameters:
     array[] - sorted array
CALLS TO:
  getMedian - implements Median of Three pivot selection algorithm
  insertionSort - implements insertion sort algoritm
*****************************************************************************/
void QuickSort(int array[], int lowIdx, int hiIdx) {
        
    int pivot;
    int left;
    int right;
    int temp;
    int size;
        
    if (lowIdx < hiIdx) {  
            
        size = (hiIdx - lowIdx) + 1;
            
        GetMedian(lowIdx, hiIdx, array);
        pivot = lowIdx;
        left = lowIdx + 1;
        right = hiIdx;
                
        while (left <= right) {
                    
            while ((array[left] <= array[pivot]) && (left <= hiIdx)) 
                left++;            
            while ((array[right] >= array[pivot]) && (right >= left)) 
                right--;
            
            // compare indices for swap condition
            if (left < right) {   
                        
                temp = array[right];
                array[right] = array[left];
                array[left] = temp;
            }// end if
        }// end outer whle
                
        //swap value pointed to by pivot with value pointed to by right
        temp = array[right];
        array[right] = array[pivot];
        array[pivot] = temp;
                
        QuickSort(array, lowIdx, right - 1);
        QuickSort(array, right + 1, hiIdx);
            
        }// end if(general case)
}//end fn
  
/******************************************************************************
FUNCTION: GetMedian
DESCRIPTION: obtains pivot point for quick sort using median of three method
INPUT:  
Parameters:
    array[] - array to be sorted
    lowIdx - location of low element in list being sorted
    hiIdx - location of high element in list being sorted
OUTPUT: 
     Pivot point has been moved to low index in array[]
*****************************************************************************/
void GetMedian(int lowIndex, int hiIndex, int array[]){
        
    int middle = (hiIndex + lowIndex)/2;
    int temp;
        
        
    if (array[lowIndex] > array[middle]){
        temp = array[lowIndex];
        array[lowIndex] = array[middle];
        array[middle] = temp;
    }
        
    if (array[lowIndex] > array[hiIndex]) {
        temp = array[lowIndex];
        array[lowIndex] = array[hiIndex];
        array[hiIndex] = temp;
    }
        
    if (array[middle] > array[hiIndex]) {
        temp = array[middle];
        array[middle] = array[hiIndex];
        array[hiIndex] = temp;
    }
        
    temp = array[lowIndex];
    array[lowIndex] = array[middle];
    array[middle] = temp;
}
    
/******************************************************************************
FUNCTION: SelectionSort
DESCRIPTION: obtains pivot point for quick sort using median of three method
INPUT:  
 Parameters:
    array[] - array to be sorted
    lowIdx - location of low element in list being sorted
    hiIdx - location of high element in list being sorted
OUTPUT: 
 Parameters:
    array[] - sorted array
*****************************************************************************/
void SelectionSort(int array[], int lowIndex, int hiIndex){
        
    int remainListTop = 0;      // eliminate
    int lastItemIdx = hiIndex;  // eliminate
    int smallestIdx;
    int compareIdx;
    int temp;
        
    while (remainListTop < lastItemIdx) {
        smallestIdx = remainListTop;
        compareIdx = remainListTop + 1;
            
        while (compareIdx <= lastItemIdx) {
                
            if (array[compareIdx] < array[smallestIdx]) 
                smallestIdx = compareIdx;
            compareIdx++;
                
        }//end inner while
        if (array[smallestIdx] != array[remainListTop]) {
            temp = array[smallestIdx];
            array[smallestIdx] = array[remainListTop];
            array[remainListTop] = temp;
        }
        remainListTop++;
    }//end outer while
        
}
/*******************************************************************************
 FUNCTION : GetRepetitions
 IMPLEMENTED BY: Doug Krause
 DESCRIPTION: prompts user for number of times to loop sorting
 OUTPUTS:
    Returns:
        reps - number of repetitions
 CALLS TO:
    ValidateNum
 ******************************************************************************/
int GetRepetitions(){
    
    int const MIN_REPS = 1;
    string repsString;
    int reps = MIN_REPS;
    
    do {      
        if (reps < MIN_REPS)
            cout << "ERROR" << endl; 
        
        cout << "Enter the number of times to repeat each sort (1 or more): ";
        cin >> repsString;
        cout << endl;
        reps = ValidateNum(repsString);
    } while (reps < MIN_REPS);
    
    
    return reps;
}
/******************************************************************************
 FUNCTION : ValidateNum
 IMPLEMENTED BY: Doug Krause
 DESCRIPTION: returns valid for integer input > 1
 INPUTS:
    Parameters:
        repsString - user input, string representing number of times to loop sorting
 OUTPUTS:
    Returns:
        reps - validated number of times to loop sorting converted to int
 ******************************************************************************/
int ValidateNum(string repsString){
    
    int strLength;
    int reps;
    char *repsArray;
    bool valid = true;
    
    strLength = repsString.length();
    repsArray = new char [strLength + 1];
    strcpy(repsArray, repsString.c_str());
    
    for (int index = 0; index < strLength; index++) {
        if (!isdigit(repsArray[index])) {
            index = strLength + 1;
            reps = repsFlag;
            valid = false;
        }//end if
    }//end for
    
    if (valid)
        reps = atoi(repsArray);
    
    delete repsArray;
    return reps;
}


// **********END FILE*************