**CS 225 Data Structures**

**Team Members (alpizar2-bheng2-jorgejc2-miguel5)**

**READFILE Important Information**

1. **Major Code, Data, Results and Their Locations** The files that hold all the code that you will need to run this code are found in the following files: 

* MapOutput.cpp/h - containts all the code for our three algorithms and their helper functions

    * **vector<int> findSCC (vector<vector<string>> file)**- this finds the strongly connected component of our dataset 

    * **void dijkstra(int src, int des)** - this find the shortest path between the source and destination 

    * **void findPath(int StartID, int finaID)** - this finds a bfs path between the source and destination 

    * **double EulerPath(double lat1, double long1, double lat2, double long2)** - the code for this was taken from: https://www.geeksforgeeks.org/program-distance-two-points-earth/

    * **Struct MapNode** - this is used to hold the information from the CSV file 

    * **LPHashTable<int, MapNode> IDTable_** - this is where our hash table is made with the MapNode that holds all our information 

* ReadFile.cpp/h - contains the code to read the csv files and organize the data 

    * **vector<vector<string>> read_file()**- this is where all the important information of airports_fitered.csv will be stored 

    * **vector<pair<int , int>> read_routes()** - this is where all the routes from routes_filtered.csv will be stored 

* HashTable.cpp/h - contains the code to create the hash table that will help us organize important information 

* main.cpp - this is where we set up for the test cases by getting the file and making the appropriates structs  

    * **vector<vector<string>> file = read_file()** - will initialize the information we need fromm airports_fitered.csv

    * **vector<pair<int,int>> routeFile = read_routes()** - will initialize the routes we need from routes_filtered.csv

    * **Map airports(file, routeFile)** - this will make the map that will have all the information we need to run our test cases 

* Other files in the COVIDMap folder are imported from past labs and helped out with the creation of the hash table 

* Our data is in 2 CSV files those being "airports_fitered.csv", and "routes_filtered.csv"

* Our results will be displayed in the terminal after modifying the main.cpp file and running the code. 

2. **How to Run Our Code** We are under the assumption that you have not cloned our repository so the instructions for that can be accessed here: 

    * https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository

* After cloning the repository you will follow these commands:

    * To access the correct files you will have to run $ cd alpizar2-bheng2-jorgejc2-miguel5/COVIDMap in the terminal 

    * You will then open main.cpp with your preferred source code editor. 

    * Next you will look through lines "78" - "141" of main.cpp to see what test cases you want to run :

* After finding the test case you want to test you will:

    * Go to your terminal and type $ make && ./COVIDMap TEST# (where # is the test case number) just like the image below.

        ![example](https://github-dev.cs.illinois.edu/cs225-sp21/alpizar2-bheng2-jorgejc2-miguel5/blob/master/test.JPG)

    * If you want to refer to the map the test case is using refer to the following map. 

        ![example](https://github-dev.cs.illinois.edu/cs225-sp21/alpizar2-bheng2-jorgejc2-miguel5/blob/master/testmap.JPG)

    * If you have questions on how to run our test cases you can just run $ ./COVIDMap in the terminal and you will be given more information on how to do so 

    * After running the command on the terminal the results will be displayed on the terminal.
    
    * If you are not running a test case you will run this in the terminal $ ./COVIDMap "algorithm" "sourceID" "destination ID" into the terminal with the parameters you would like
    
      * the instructions are specified when you type ./COVIDMap if you need further help 

3. **Using Another DataSet** When creating this code we based it on the CSV files we used. That is why our readfile functions and hash table are very specific to accomodate the information we needed such as the coordinates of an airport, there ID and the routes a specific airport can have. If you were to use a different dataset some changes would have to be made in our READFILE.cpp. These changes would cause more changes in later functions such as the Hash table and would be troublesosme since you would have modify our "structs". If you were to use a different dataset the CSV file would have to be exactly in the style of our CSV file. This is why it is recommended to use our CSV file since there is no direct instructions we can give if you were to use a different data set. 

4. **Resources and Video** 
* Link to our final presentation: https://drive.google.com/file/d/1cBFSs4mC9YkDWigglAXHeY80bmqxwMzl/view?usp=sharing

* Link to our powerpoint: https://docs.google.com/presentation/d/1UcxvWmSehw1QZiqbb7SuktiMFetoEwhW0zlnm4hz7k4/edit?usp=sharing




