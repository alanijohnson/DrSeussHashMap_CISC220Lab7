
/* 
 * File:   hashNode.hpp
 * Author: Alani
 *
 * Created on May 17, 2017, 10:10 AM
 */

#ifndef HASHNODE_HPP_
#define HASHNODE_HPP_
#include <iostream>
using namespace std;

class hashNode {
    friend class hashMap;
    string keyword; // this is used as the key – each key is only inserted once!
    string *values; // the dynamically allocated array of words that follow the
    //key in the Dr. Seuss text. If this set of words gets to be larger than the
    //valuesSize of the array, then you must re - allocate the array double in size and copy
    //over all the old values
    int valuesSize; // the size of the values array
    int currSize; // the number of words in the values array so far
public:
    hashNode(); //construor-initializes keyword to “” , values to 0, and array to NULL
    hashNode(string s); // initializes keyword to s, the arraysize to 100 (or
    //whatever you like for starting), the currSize to 0, and the valuesSize to 100
    hashNode(string s, string v); // in addition, puts a value in the values
    //array and initializes currSize to 1
    void addValue(string v); // adds a new value to the end of the values array,
    //increases currSize, checks to make sure there’s more space, and, if not, calls
        //dblArray();
    void dblArray(); //creates a new array, double the length, and copies over the
    //values. Sets the values array to be the newly allocated array.
    string getRandValue(); // returns a random string from the values array. If
    //there’s no values in the value array, then it returns an empty string.
};
#endif /* HASHNODE_HPP_ */


