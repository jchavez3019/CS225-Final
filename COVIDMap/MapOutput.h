#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ReadFile.h"
#include <sstream>
#include <fstream>
#include <queue>
#include <list>
#include <algorithm>
#include<limits.h>
#include "lphashtable.h"
#include <stack>

using namespace functions;
using namespace std;

class Map{
    public:

    Map();

    ~Map();
    
    //Map(); //this will create the binary tree
    Map(vector<vector<string>> file, vector<pair<int,int>> routeFile);

    void printData(int ID);
    
    void printAirports();

    void readRoutes(vector<pair<int,int>> file);

    double toRadians(const double degree);

    double Eulerpath(double lat1, double long1, double lat2, double long2);
    // string getValue(int key);

    void insertStates();

    vector<int> findPath(int startID, int finalID, bool display);

    vector<int> findSCC(vector<vector<string>> file);

    void dfs(int i, vector<vector<string>> file);      

    void printSCC(vector<int> low, vector<vector<string>> file);  
    void dijkstra(int src);
    double dijkstra(int src, int des);
    void printSolution(double dist[], int parent[], int src);
    void printPath(int parent[], int j);
    int sccCount;
    

    private:

    
    //this MapNode struct is how we create our graph of airports and connections
    struct MapNode {
        int key;
        string value;
        int currentWeight;
        vector<int> nodes;
        double x;
        double y;
        int prev;

        /**
         * Node constructor; sets children to point to `NULL`.
         * @param newKey The object to use as a key
         * @param newValue The templated data element that the constructed
         *  node will hold.
         */
        MapNode(const int& newKey, const string& newValue, double lat, double lon)
            : key(newKey), value(newValue), currentWeight(-1), x(lat), y(lon), prev(-1)
        {
        }
        MapNode() : key(-1), value("n/a"), currentWeight(-1), x(-1.0), y(-1.0), prev(-1)
        {}
    };
    double minDistance(double dist[], bool visited[], MapNode & curr);
    //this hash table holds our map
    LPHashTable<int,MapNode> IDTable_;

    vector<MapNode*> airports;
    
    vector<int> hasVisited_;

    vector<pair<int,int>> routes_;

    // variables used for SCC
    vector<int> ids;
    vector<int> low;
    vector<bool> onStack;
    stack<int> mystack;
    int id;   
    //test
};