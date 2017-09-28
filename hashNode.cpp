/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hashNode.cpp
 * Author: Alani
 * 
 * Created on May 17, 2017, 10:10 AM
 */

#include "hashNode.hpp"
#include <time.h>
#include <cstdlib>

/* hashNode() - constructor of hashNode class
 *             initializes parameters as specified:
 *                  keyword - ""
 *                  values - NULL
 *                  valuesSize - 0
 *                  currSize - 0
 * Parameters: None
 * Returns: None
 * Output: None
 */
hashNode::hashNode() {
    srand(time(NULL));
    keyword = "";
    values = NULL;
    valuesSize = 0;
    currSize = 0;
}

/* hashNode(string s) - constructor of hashNode class
 *             initializes parameters as specified:
 *                  keyword - s
 *                  values - array of 100 strings
 *                  valuesSize - 100
 *                  currSize - 0
 * Parameters: 
 *      string - key
 * Returns: None
 * Output: None
 */
hashNode::hashNode(string s) {
    srand(time(NULL));
    keyword = s;
    values = new string[100];
    valuesSize = 100;
    currSize = 0;
    
}

/* hashNode(string s, string v) - constructor of hashNode class
 *             initializes parameters as specified:
 *                  keyword - s
 *                  values - array of 100 strings
 *                  valuesSize - 100
 *                  currSize - 0
 * Parameters: 
 * Returns: None
 * Output: None
 */
hashNode::hashNode(string s, string v){
    srand(time(NULL));
    keyword = s;
    values = new string[100];
    addValue(v);
    valuesSize = 100;
}

/* addValue(string v) - add value to the array of values within the Node
 * Parameters: 
 *      string v - value
 * Returns: None
 * Output: None
 */
void hashNode::addValue(string v){
    if (currSize>=valuesSize){
        dblArray();
    } 
    
    values[currSize] = v;
    currSize++;
}

/* dblArray() - double the array size by
 *                                creating new array and copying over elements
 * Parameters: None
 * Returns: None
 * Output: None
 */
void hashNode::dblArray(){
    string *tmpArr = new string[valuesSize*2];
    for (int i=0; i<valuesSize; i++){
        tmpArr[i]=values[i];
    }
    valuesSize = valuesSize*2;
    values = tmpArr;
}

/* getRandValue() - returns a random string from the list of values
 * Parameters: None
 * Returns:
 *      string - random string from list of values
 * Output: None
 */
string hashNode::getRandValue(){
    if (currSize==0){
        return "";
    } else{
        return values[rand()%currSize];
    }
}

