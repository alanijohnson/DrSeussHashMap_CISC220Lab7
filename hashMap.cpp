/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hashMap.cpp
 * Author: Alani
 * 
 * Created on May 17, 2017, 10:12 AM
 */

#include "hashMap.hpp"

/* hashMap() - constructor of hashMap class
 *             creates a hashMap of default size 17
 *             initializes numKeys to 0
 *             generates hashMap initializing all values in array to NULL
 * Parameters: None
 * Returns: None
 * Output: None
 */
hashMap::hashMap() {
    mapSize = 17; //initialize mapSize
    map = new hashNode*[mapSize]; //create an array of hashNode addresses
    numKeys = 0; //initialize number of keys to 0

    //initialize all values in map to NULL
    for (int i = 0; i < mapSize; i++) {
        map[i] = NULL;
    }
    
    //printMap();
}

/* addKeyValue(string k, string v) - creates node for key value and adds it to hash map
 *          hash the key and place it in the map
 * 
 * Parameters: 
 *          string k - key
 *          string v - value
 * Returns: None
 * Output: None
 */
void hashMap::addKeyValue(string k, string v) {
    //cout << "adding key: " << k << endl;
    
    //check load
    //if load is 70% full hashMap is resized and rehashed
    if (0.7 * mapSize < numKeys) {
        reHash(); //resize the hashMap and transfer over keys to new map
    }
    
    //add node to map

    //determine hash
    int h = calcHash(k);
    int i = 0;
    
    if (map[h] == NULL) { //hash index is empty, add node
        hashNode *node = new hashNode(k); //create new node
        node->addValue(v); //add value to node
        map[h] = node; //store node
        numKeys++; //increment number of keys
        //cout << "hash: "<<h << endl;
        //printMap();
        return;
    } else { //rehash
        while (map[h] != NULL) { //hash location is full
            if (h>=mapSize || map[h]->keyword != k) { //hash location contains different keyword
                h = dblHash(h, i, k); //calculate new hash
                i++; 
            } else { //hash location contains keyword
                map[h]->addValue(v); //add value to list
                //cout << "hash: "<<h << endl;
                //printMap();
                return;
            }
        }
    }

    //create the new node after double hashing
    hashNode *node = new hashNode(k);
    node->addValue(v);
    //add node to map
    map[h] = node;
    numKeys++;
    //cout << "hash: "<<h << endl;
    //printMap();
    return;

}

/* getIndex(string k) - returns the expected index of a key
 * Parameters:
 *      string k - key
 * Returns:
 *      int - the index location of key
 * Output: None
 */
int hashMap::getIndex(string k) {
    return returnHash(k); //already wrote this method and used it without realizing
                          //method was asked for
}

/* calcHash(string k) - first hashing function
 *              hashes the function by looking at all the characters in a string
 *              and adding them to the hash
 *              Not the most efficient hashing function
 *              takes prime number (31) multiplies by current hash value and adds the value of the character
 *              then mods over mapSize
 * Parameters: 
 *      string k - key
 * Returns:
 *      int - hash index
 * Output: None
 */
int hashMap::calcHash(string k) {
    int hash = 0;
    int a = 31;
    for (int i = 0; i < k.length(); i++) {
        hash = (a * hash + k[i]) % mapSize;
    }
    return hash;
}

/* dblHash(int h, int k, string k) - double hash
 *             determines double hash using number of collisions and current hash
 *             and string
 *             
 * Parameters:
 *      int h - current hash
 *      int i - number of collisions
 *      string k - key
 * Returns: 
 *      int - hash index
 * Output: None
 */
int hashMap::dblHash(int h, int i, string k) {
    int sPrime;
    
    //prime number smaller than size
    for (int n = mapSize - 1; n>=2 ; n--) {
        if (isPrime(n)) {
            sPrime = n;
            break;
        }
    }
    
    
    return sPrime - ((h+i) % sPrime);
}

/* getClosestPrime() - increases the mapSize to the closest prime
 *                      NOTE: Poor function name, given method
 *                            should be upMapSize
 * Parameters: None
 * Returns: None
 * Output: None
 */
void hashMap::getClosestPrime() {
    for (int n = mapSize + 1; n < 2 * n - 2; n++) {
        if (isPrime(n)) {
            mapSize = n; //find the next largest prime and assign it to the mapSize
            break;
        }
    }
}

/* reHash() - remakes the hashMap after resizing
 * Parameters: None
 * Returns: None
 * Output: None
 */
void hashMap::reHash() {
    int h; //initialize index for hash index
    int oldSize = mapSize; //store the old map size
    getClosestPrime(); //size up the prime number
    hashNode **oldMap = map; //store the old map
    
    //create new map
    map = new hashNode*[mapSize];
    //initialize all values in map to NULL
    for (int i = 0; i < mapSize; i++) {
        map[i] = NULL;
    }
    
    //go through the old hashMap and rehash to new hashMap
    for (int i = 0; i < oldSize; i++) {
        if (oldMap[i] != NULL) {
            h = returnHash(oldMap[i]->keyword);
            map[h] = oldMap[i];
        }
    }
    
    //printMap();
}

/* findKey(string k) - find a key within the hashMap using the Hashing functions
 *             
 * Parameters:
 *      string k - key
 * Returns:
 *      int - index of key in the hashMap
 * Output: None
 */
int hashMap::findKey(string k) {
    //cout << "Key: " << k << endl;
    //printMap();
    
    //find key
    //hash to find node
    int h = calcHash(k);
    int i = 0;
    if (map[h]->keyword == k) { //first hash found keyword
        //cout << "hash: "<<h << endl;
        return h;
    } else { //rehash to find keyword
        while (map[h]->keyword != k && i<=numKeys) {
            //cout << "hash: "<<h << " " << map[h]->keyword << endl;
            if (map[h]==NULL){ //if null is found where keyword should be located keyword not in map (NOT USED IF REMOVING NODES)
                return -1;
            }
            h = dblHash(h, i, k);
            i++;
            
        }
    }
    
    //hashed more than the number of keys stored, element not in map
    if (i>numKeys){
        //cout << "return -1" << endl;
        return -1;
    } else {
        //cout << "return " << h<<endl;
        return h;
    }

}

/* printMap() - print the map and map information
 *              prints the current MapSize
 *              prints the Numebr of Keys:
 *              prints nodes in following formats:
 *                  index: Key: value, value,
 *                  index: NULL
 *              
 * Parameters: None
 * Returns: None
 * Output: prints map to console
 */
void hashMap::printMap() {
    cout << endl << "_________Printing hashMap_________" << endl;
    cout << "Current Map Size: " << mapSize << endl;
    cout << "Current Number of Keys: " << numKeys << endl << endl;
    
    for (int i=0; i<mapSize; i++){
        cout << i << ": ";
        if (map[i]==NULL){
            cout << "NULL"; //will print NULL if nothing is in node
        } else{
            cout << map[i]->keyword << ": ";
            for (int j=0; j<map[i]->currSize; j++){
                cout << map[i]->values[j]<< ", ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

/* isPrime(int n) - determine if n is prime return true false
 * Parameters:
 *      int n - integer to be evaluated
 * Returns:
 *      true - number is prime
 *      false - number is not prime
 * Output: None
 */
bool hashMap::isPrime(int n) {
    //prime numbers must be non-negative 0 isn't prime
    if (n <= 0) {
        return false;
    }
    
    bool b = true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            b = false;
            break;
        }
    }
    return b;
}

/* HELPER METHOD:
 * returns the hash after double hashing
 */
int hashMap::returnHash(string k){
    int h = calcHash(k);
    int i = 0;
    if (map[h] == NULL) {
        return h;
    } else { //rehash
        while (map[h] != NULL) {
            if (h>=mapSize || map[h]->keyword != k) {
                h = dblHash(h, i, k);
                i++;
            } else {
                return h;
            }
        }
    }

    return h;
}