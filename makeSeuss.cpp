/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   makeSuess.cpp
 * Author: Alani
 * 
 * Created on May 17, 2017, 10:17 AM
 */

#include "makeSeuss.hpp"

#include "makeSeuss.hpp"
#include "hashMap.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

/* makeSeuss() - constructor of makeSeuss class
 *             generates new hashMap
 *             reads in default file Dr.Seuss.txt
 *             writes to default file testMakeSeuss.txt
 * Parameters: None
 * Returns: None
 * Output: None
 */
makeSeuss::makeSeuss(){
    ht = new hashMap();
    newfile = "testMakeSeuss.txt";
    fn = "DrSeuss.txt";
    readFile();
    writeFile(); 
}
/* makeSeuss(string f1, string f2) - constructor of makeSeuss class
 *             generates new hashMap
 *             reads in f1
 *             writes to f2
 * Parameters: 
 *      string f1 - file 1 - file to read
 *      string f2 - file 2 - file to write to
 * Returns: None
 * Output: None
 */
makeSeuss::makeSeuss(string f1, string f2) {
    ht = new hashMap();
    newfile = f2;
    fn = f1;
    readFile();
    writeFile();
}

void makeSeuss::readFile() {
    //int i = 0;
    ifstream infile(fn.c_str(), ios::in); // open file
    string key = "";
    string value = "";
    infile>> key;
    ht->first = key;
    while (infile >> value) { // loop getting single characters
        //cout << key << ": " << value << endl;
        ht->addKeyValue(key, value);
        //i++;
//        if (i%5000 == 0){
//            //ht->printMap();
//        }
        key = value;
        value = "";
    }
    ht->addKeyValue(key, value);
   // cout << endl;
    infile.close();
}

void makeSeuss::writeFile() {
    ofstream outfile(newfile.c_str(), ios::out);
    outfile << ht->first << " ";
    string key = "";
    string value = ht->map[ht->getIndex(ht->first)]->getRandValue();
    int ct = 0;
    while (ct < 500 && value != "") {
        key = value;
        outfile << key << " ";
        value = ht->map[ht->getIndex(key)]->getRandValue();
        ct++;
    }
    outfile.close();
}
