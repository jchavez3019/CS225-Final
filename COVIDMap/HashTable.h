#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include "MapOutput.h"

using namespace std;

class HashTable {
    public:\
        //creates the table
        hash();
        /**
        *Takes in a key and returns an index;
        *@param key
        */
        int hash(int key);
        /**
        *Adds a MapNode to the Table
        *@param id # of the airport that we can use to create the Mapnode
        */
        void addMapNode(int id);
        /**
        *COOL FORM TO SHOW THE MAPNODES!!
        */
        void printTable();
        /**
        *Removes a MapNode from the Table
        *@param id # of the airport
        */
        void removeMapNode(int id);
    private:
        //helper functions of hash
        static const int tableSize;
        MapNode item;
        MapNode* HashTable[tableSize];

};