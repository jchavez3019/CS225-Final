#pragma once

#include <cstdlib>
#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

HashTable::hash() {
    for (int i = 0; i < tableSize; i++) {
        HashTable[i] = new MapNode;
    }
}

int HashTable::hash(int key) {
    int 
}

void HashTable::addMapNode(int id) {
    int index = hash(ID);

    // Finish making the MapNode
    HashTable[index]->key = id;
}
void HashTable::printTable() {
    //Finish displaying all the other data from each airport
    for (int i = 0; i < tableSize; i++) {
        cout <<"----------------------\n";
        cout <<"Index = "<< i << endl;
        cout <<"Airport ID = "<< HashTable[i]->key << endl;
        cout <<"Airport Name = "<< HashTable[i]->value << endl;
        cout <<"Longitude/Latitude "<< HashTable[i]->key << endl;
        cout <<"----------------------\n";


    }
}
void removeMapNode(int id) {
    int index = hash(id);
    MapNode* delPtr;
    if(HashTable[i]->key != 0 && HashTable[i]->value != "empty") {
        HashTable[i]->key = 0;
        HashTable[i]->value = "empty";
        HashTable[i]->currentWeight = 0;
    }
}
