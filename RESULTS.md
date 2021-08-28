**Brennan Eng**
**Edson Alpizar**
**Jorge Chavez**
**Miguel Moreno**
**GC Evans**
**CS225**
* **Results on CS225 final project**
	* In our new proposal we decided on the goal of trying to find a path from one location to another given that the  location was not isolated as well as finding the shortest path between two locations by connecting multiple locations and adding their weighted paths. We also wanted to see airport hubs by finding cells of airports that revolve around a specific supernode. I am happy to say that by using Airport locations and airplane routes between those locations, our CS225 group has managed to complete all our goals by finding a path between two airport locations and finding the shortest path between two airport locations since there can be multiple paths from a source to a destination. We also figured out central hubs of airports based on Strongly connected component by traversing through our map of airports and their directed routes
    
* **Creating a hash table to store a vast amount of data:** 
	* Our original idea was to store our inputted CSV file with a complex vector[i] of vectors[j] of strings where each vector [i] index represented a line in the CSV and each vector[j] index represented a specific column in the CSV file. While we did manage to store everything into a vector, we came to the realization that it took up too much space and memory and we decided to use the same implementation of hash table as the lab_hash code tweaked so our hash table was able to start a Node consisting on airportID, coordinates, name of the airport, and other various variables to help us with our algorithms. In the image on the left, you can see a snippet of our hash table output. The code that is running iterates through all airports and prints out their name, coordinates, and the routes that specific airport can fly to. The hash table method provided a very beneficial structure for storing useful information such as the current weight of the path in Dijkstra's as well as the ID, name, and the routes available for the program to look for. The hash table essentially provided us the ability to generate a graph of MapNodes based on the MapNodes data stored within it

    ### MapNode information
    ```C++
    struct MapNode {
        int key;
        string value;
        int currentWeight;
        vector<int> nodes;
        double x;
        double y;
        int prev;
    };
    ```
    ![Hashtable Output](https://github-dev.cs.illinois.edu/cs225-sp21/alpizar2-bheng2-jorgejc2-miguel5/blob/master/hashtable.JPG)

* **BFS traversal: findPath(int startID, int finalID):**
	* For the traversal of our final project, we decided on BFS to find a path from a source airport to a destination airport. It starts by using a queue in order to continually add new routes onto the queue based on new airports and their routes. findPath first initializes itself with the source airport which in this case would be 100 for the example on the left. The end destination goal would be the airport code 3599. Until the program encounters airport code 3599 it will continue to search the Map with BFS traversal. To read the output, the first line the terminal will see is the destination and it will be read backwards. In the image on the left of our test output, the program starts with 100 on the very bottom left and traverses up until it reaches the second image on the right and it will traverse with BFS until it reaches 3599. This method was successful in providing the user in finding one path between a source airport and a destination airport.

    ### findPath():
    ```C++
    vector<vector<string>> file = read_file();
    vector<pair<int,int>> routeFile = read_routes();
    Map airports(file, routeFile);
    airports.findPath(100,3599);
    ```
    ![BFS Output](https://github-dev.cs.illinois.edu/cs225-sp21/alpizar2-bheng2-jorgejc2-miguel5/blob/master/table.JPG)
* **Dijkstra’s Algorithm: dijkstras(int src, int des):**
	* Dijkstra’s is similar to BFS in that it traverses the MapNodes with a queue except the queue we implemented is a priority queue which in the way we manipulated the values, popped off the smallest value from the top and it continually sorts the integer values based on the distance between an airport the program is looking at and a route it can take. By self-regulating the paths available for the program to take, our program creates a greedy algorithm which finds the shortest path available to it and continually traverses until all airports have been exhausted. Once the program has been exhausted all values such as the parent of those airports, and the minimum distance to one of its routes. The output of Dijkstra’s can be found below on the right which shows the same source and destination airport as the BFS program discussed above, but a much shorter version. It also prints out the distance as well as the specific path it takes to get to the destination. Ultimately we test this path by looking at available routes as we went manually and by calculating the distance with the Euler’s path formula to accommodate the spherical coordinates of airports.

    ### dijkstras():
    ```C++
    vector<vector<string>> file = read_file();
    vector<pair<int,int>> routeFile = read_routes();
    Map airports(file, routeFile);
    airports.dijkstra(100, 3599);
    ```
    ![Dijkstra's Output](https://github-dev.cs.illinois.edu/cs225-sp21/alpizar2-bheng2-jorgejc2-miguel5/blob/master/dijoutput.JPG)

* **Strongly Connected Components: findSCC(vector<vector<string>>file):**
    * In order to be categorized as a Strongly Connected Graph every node in a directed graph must be reachable from every other node. Similarly, Strongly Connected Components of a graph are subgraphs of the main directed graph which are themselves strongly connected. This algorithm begins in any arbitrary node in the graph and makes a vector “low” which will be used  to store the supernode number of the node. The index in the vector “low” will correspond to the airport in the same index of the vector “file”. In order to traverse the directed graph the algorithm uses DFS (Depth-First Search) which allows the visit of each node exactly once. As the search traverses the graph, each node is accessed and added to a stack. The node is accessed and its respective route vector is accessed. This vector points to other nodes and therefore we can access other nodes from the vector. As we search through every node, we also check if the visited node is in the stack. If the node appears in the stack, the algorithm has found a loop which means that the nodes in the loop can access each other starting from any of those respective nodes. The nodes are all given the index value of the smallest node in the vector “low”. This means that the node in a corresponding index of “file” will belong to the group number depicted in the value of the index in “low”. 

    ### findSCC():
    ```C++
    vector<vector<string>> file = read_file();
    vector<pair<int,int>> routeFile = read_routes();
    Map airports(file, routeFile);
    airports.findSCC(file, routeFile);
    ```

    ![SCC Output](https://github-dev.cs.illinois.edu/cs225-sp21/alpizar2-bheng2-jorgejc2-miguel5/blob/master/supernode.JPG)










