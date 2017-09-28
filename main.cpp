

/* 
 * File:   main.cpp
 * Author: Alani
 * Lab 7 
 * Created on May 17, 2017, 10:03 AM
 * File Contents: 
 */

#include <cstdlib>
#include "hashMap.hpp"
#include "hashNode.hpp"
#include "makeSeuss.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    makeSeuss(); //reads in default DrSeuss.txt
    makeSeuss("DrSeuss.txt","test2.txt");
    
    return 0;
}

