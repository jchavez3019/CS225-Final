#include "ReadFile.h"
#include "MapOutput.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "lphashtable.h"
#include <string>


using namespace std;
using namespace functions;

int main(int argc, char** param) {
    if(argc == 1){
        cout<<"Good morning, this is our final CS project!"<<endl;
        cout<<"In order to get started, type ./COVIDMap [string algorithm] [int parameter 1] [int parameter 2] in your terminal."<<endl;
        cout<<"The following algorithms can be run:"<<endl;
        cout<<"SCC, BFS, DIJSKTRA, TEST1, TEST2, TEST3, TEST4, TEST5, TEST6, TEST7"<<endl;
        cout<<"BFS and DIJSKTRA need at least two integer parameters to run correctly"<<endl;
        cout<<"Have fun testing our code!"<<endl;
        return 1;
    }
    //these two vectors contain all the information needed from the actual csv data
    vector<vector<string>> file = read_file();
    vector<pair<int,int>> routeFile = read_routes();

    //these two vectors contain the fictional nodes we created in order to efficiently display that our algorithms work correctly
    vector<vector<string>> file_test = read_file_test();
    vector<pair<int,int>> routeFile_test = read_routes_test();

    int startID = -1;
    int destinationID = -1;
    string alg(param[1]);
    if(argc >= 4){
        string temp1(param[2]);
        string temp2(param[3]);
        startID = stoi(temp1);
        destinationID = stoi(temp2);
    }
    cout<<"Running algorithm: "<<alg;
    if(startID == -1)
        cout<<" No startID is being used";
    else
        cout<<" startID: "<<startID;
    if(destinationID == -1)
        cout<< " No destinationID is being used"<<endl;
    else
        cout<< " destinationID: "<<destinationID<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    if(alg == "SCC"){
        Map SCC(file, routeFile);
        vector<int> sccs = SCC.findSCC(file);
    }
    else if (alg == "BFS") {
        //type BFS as the first parameter to call this algorithm
        //a source ID and a destination ID is necessary to run this algorithm
        if(startID == -1 || destinationID == -1){
            cout<<"Not enough parameters to run this algorithm. Please enter a source and destination ID"<<endl;
            return 1;
        }
        Map BFS(file,routeFile);
        BFS.printData(startID);
        BFS.printData(destinationID);
        BFS.findPath(startID, destinationID, false);

    }
    else if (alg == "DIJKSTRA"){
        if(startID == -1 || destinationID == -1){
            cout<<"Not enough parameters to run this algorithm. Please enter a source and destination ID"<<endl;
            return 1;
        }
        Map Dij(file, routeFile);
        Dij.printData(startID);
        Dij.printData(destinationID);
        Dij.dijkstra(startID, destinationID);
    }
    else if (alg == "TEST1"){
    cout<<"This test case shows that our Map object can take in CSV data and print the data correctly to the terminal"<<endl;
    cout<<"Every single airport ID is printed along with their corresponding name, latitude, longitude, and where they point to "<<endl;
    cout<<"which is denoted by -->"<<endl;
    Map test_one(file_test, routeFile_test);
    test_one.printAirports();
    return 1;
    }
    else if (alg == "TEST2"){
        cout<<"This test case runs BFS to find a path between to airport IDs [1] and [4]"<<endl;
        cout<<"This BFS algorithm assumes the distances between all paths are equal, so that printed path "<<endl;
        cout<<"isn't necessarily the shortest path. If you want the shortest path, try out DIJKSTRA's algorithm"<<endl;
        cout<<"---------------------"<<endl;

        Map BFS(file_test,routeFile_test);
        BFS.printData(1);
        BFS.printData(4);
        BFS.findPath(1, 4, true);
    }
    else if (alg == "TEST3"){
        cout<<"This test case runs BFS to find a path between to airport IDs [1] and [9]"<<endl;
        cout<<"There is no path between these two ID's, so no path should be printed "<<endl;
        cout<<"---------------------"<<endl;

        Map BFS(file_test,routeFile_test);
        BFS.printData(1);
        BFS.printData(9);
        BFS.findPath(1, 9, true);

    }
    else if (alg == "TEST4"){
        cout<<"This test case runs Tarjan's Strongly Connected Componetns Algortihm on a given directed graph"<<endl;
        cout<<"It should also return all the nodes in SuperNode 6 "<<endl;
        Map SCC(file_test,routeFile_test);
        vector<int> sccs = SCC.findSCC(file_test);
        for (int i = 0; i < sccs.size(); i++) {
            if(sccs[i] == 6){
                cout<<"------->"<<file_test[i][1]<<" is part of SuperNode "<<sccs[i]<<endl;
            }
        }

    }
    else if (alg == "TEST5") {
        Map test5(file_test, routeFile_test);
        
        double temp = test5.dijkstra(2, 5);
        if (310*0.95 < temp && temp< 310*1.05) {
            cout << "Answer is within tolerance" << endl;
        }
        else {
            cout << "Answer is not within tolerance" << endl;
        }
    }
    else if (alg == "TEST6") {
        Map test6(file_test, routeFile_test);
        double temp = test6.dijkstra(2, 10);
        if (5650.79 * 0.95 < temp && temp < 5650.79 * 1.05) {
            cout << "Answer is within tolerance" << endl;
        }
        else {
            cout << "Answer is not within tolerance" << endl;
        }
    }
    else if (alg == "TEST7") {
        Map test7(file_test, routeFile_test);

        double temp = test7.dijkstra(2, 4);
        if ( 148.7 * 0.95 < temp && temp < 148.7  * 1.05) {
            cout << "EulerPath works" << endl;
        }
        else {
            cout << "EulerPath does not work" << endl;
        }
    }
    else{
        cout<<"Invalid Algortihm"<<endl;
        return 1;
    }
        return 0;
    }