**Development Log for COVID Map Project**

1. **Log for 4/11/2021**
    * Jorge began setting up the Makefile
    
    * Brennan and Miguel began writing the code for ReadFile.cpp

    * Edson began began looking into how the maps are supposed to be outputted

1. **Log for 4/13/2021**
    * Jorge and Edson began making the files MapOutput, printtree while also creating the main.cpp file

    * Brennan and Miguel manipulated the dataset in order to isolate one specific datapoint as well as continued to work on Readfile

1. **Log for 4/18/2021**
    * Edson worked on the animation of the function as well as logging in state coordinates

    * Jorge worked on test files and also copied over binary tree files

    * Brennan and Miguel worked on MapOutput constructors in order to feed into a binary tree

1. **Log for 4/19/2021** 
    * Edson managed to finish coordinates and started working on the severity tolerances of the states

    * Jorge finished the AVL tree data entry

    * Miguel also worked on the AVL data entry

    * Brennan worked on finishing readfile in addition to the new sorted vector to sort the raw data vector

1. **Log for 4/25/2021**
    * Brennan worked on making makefile and readfile compatible

1. **Log for 4/27/2021**
    We decided we no longer want to pursue the animate function and we decided we wanted to use the data structure to map out the line of shortest
    path between two epicenters through our coordinates.
    * Brennan finished ReadFile and is working on paths.cpp to find shortest path of 2 COVID epicenters

1. **Log for 4/29/2021**
    As of today, our group decided on a concensus that we longer want to pursue our COVID map idea because it lacked the complexity in order to fulfill the requirements for this final project. We will resort to another proposal idea that has been updated in PROPOSAL.md

1. **Log for 5/3/2021 - 5/7/2021**
    As of today our group has finished the hash table function to better compress our data so our ews computer can run it. We have finished the BFS algorithm that traverses through the hash table to find **a** route from one destination to another. Miguel is still continuing to work on Strongly connected components so that we can see supernodes of certain airports. Dijkstras is almost finished but we are running into some cases where the algorithm does not calculate properly.

1. **Log for 5/9/2021**
    Brennan and Edson are continuing to work on Dijkstras. We are having trouble with our current implementation and currently we are working on minDistance which calculates the current minimum distance based on the routes available.
    Miguel and Jorge are continuing to work on strongly connected components and are close to finishing.

1. **Log for 5/11/2021**
    As of right now, Brennan and Edson has finished Dijkstras and refined the output stream for it. Jorge and Miguel have both finished Strongly Connected Components and have the refined output stream for it. Both algorithms completed as well as the BFS algorithm made by Jorge with an inputted source airport and outputted source airport. All algorithms done so what needs to be done tomorrow at the due date is finish up the video as well as the README.md file.

1. **Log for 5/12/2021**
    We are worked on our corresponding test cases for the graders to read. Edson finished the README.md file while I finished the RESULTS.md outline of each goal and function of how it worked. Jorge and Miguel worked on the main function so that its easier for the grader to test the cases and showcase our built algorithms. We have finished all our parts including making the video and are about to turn everything in.