**CS 225 Data Structures**

**Project Proposal (alpizar2-bheng2-jorgejc2-miguel5)**

1. **Leading Question** Given a dataset of locations and routes, we will be able to find any path from one location to another (given that no location is isolated), and be able to connect multiple locations by their shortest path. We will present our solutions using a dataset of Airports and routes. 

1. **Dataset Acquisition and Processing** We propose using an Airplane dataset from https://data.world. We will focus on the Airports that reside in the United States and look at routes between US airports. We will be downloading a CSV file and using the airport ID’s and the coordinates for the airports so we can find the distance between two airports. Our data will be organized by using arrays and an AVL tree. 

1. **Graph Algorithms** Once we obtain the distance between airports we will be assigning that distance to be the weight of the path. This will be used so we can then create Djkstra’s algorithm to find the shortest route between two airports. We will be make a map of all the airports in the United States as well as their routes, and use BFS to find a path given any two airports. Lastly our last algorithm will be implemented as a Eulerian Path. This algorithm will connect all the airports but will not create a cycle between the paths. 

1. **Timeline**

  * April 5/April 28 - Got all the code we would need from previous labs and reworked our final                         project idea.

  * April 29 - Finished and tested our ReadFile functions as well as our BFS traversal  

  * April 30- Meet with our mentor and show him our progress

  * May 2 - Work on Dijkstra's algorithm and discuss how we will code Eulerain Path  

  * May 4 - Finish up code for Eulearian Path and plan out the recording for our final                       presentation 

  * May 9 - make sure everything is functioning for final project submission 

  * May 10- make final changes to presentation and submit final project 
