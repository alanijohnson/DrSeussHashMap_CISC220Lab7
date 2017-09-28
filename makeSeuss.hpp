/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   makeSuess.hpp
 * Author: Alani
 *
 * Created on May 17, 2017, 10:17 AM
 */

#ifndef MAKESEUSS_HPP_
#define MAKESEUSS_HPP_
#include "hashMap.hpp"
#include <iostream>
using namespace std;

class makeSeuss {
    hashMap *ht;
    string fn; // file name for input (“DrSeuss.txt”)
    string newfile; // name of output file
public:
    makeSeuss();
    makeSeuss(string file, string newf);
    void readFile();
    void writeFile();
};

#endif /* MAKESEUSS_HPP_ */

