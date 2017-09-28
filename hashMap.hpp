
/* 
 * File:   hashMap.hpp
 * Author: Alani Johnson
 *
 * Data Stuctures Lab 7
 * Created on May 17, 2017, 10:12 AM
 */

#ifndef HASHMAP_HPP_
#define HASHMAP_HPP_
#include "hashNode.hpp"
#include <math.h>
#include <iostream>

class hashMap {
    friend class makeSeuss;
    hashNode **map; //map stores address of array of hashNode addresses
    string first; // for first keyword for printing to a file
    int numKeys; //the number of current keys in the map
    int mapSize; //the size of the map array
public:
    //constuctor that creates the map, and initializes the values to
    //NULL so you know whether that index has a key in it or not already
    hashMap();
    void addKeyValue(string k, string v);
    // adds a node to the map at the correct index based on the key string, and
    //then inserts the value into the value field of the hashNode
    // Must check to see whether there's already a node at that location. If
    //there's nothing there (it's NULL), add the hashNode with the keyword and value.
    // If the node has the same keyword, just add the value to the list of values.
    //If the node has a different keyword, keep calculating a new hash index until
    //either the keyword matches the node at that index's keyword, or until the
    // map at that index is NULL, in which case you'll add the node there.
    //This method also checks for load, and if the load is over 70%, it calls the
    //reHash method to create a new longer map array and rehash the values
    int getIndex(string k); // uses calcHash and reHash to calculate and return
    //the index of where the keyword k should be inserted into the map array
    int calcHash(string k); // hash function
    void getClosestPrime(); // I used a binary search on an array of prime
    //numbers to find the closest prime to double the map Size, and then set mapSize to
    //that new prime. You can include as one of the fields an array of prime numbers, or
    //you can write a function that calculates the next prime number. Whichever you
    //prefer.
    void reHash(); // when size of array is at 70%, double array size and rehash keys
    int dblHash(int h, int i, string k); // for hashing when index is already full
    int findKey(string k); //finds the key in the array and returns its index.
    //If it's not in the array, returns -1
    void printMap(); //I wrote this solely to check if everything was working.
    bool isPrime(int n);
    int returnHash(string k);


};

#endif /* HASHMAP_HPP */

