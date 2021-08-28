 #include "ReadFile.h"
 
using namespace std;
namespace functions {
vector<pair<int,int> > read_routes()  {
    //creating file pointer
    ifstream file;

    //opens file to be read
    //Gives us Source airport ID,Destination airport ID
    file.open("routes_filtered.csv");

    //Creates a vector of pairs
    vector<pair<int,int> > TotalFile;
    //Creates pair
    pair<int,int> datapair(0,0);
    //creates a temporary string called line to take each cell
    string line;
    //counter to determine place in airport
    int counter = 0;
    //reads while the file still has values to be read
    int i = 0;
    //while(file.good() && i < 3255){
    while(file.good()){
        while(getline(file,line) ) {
            stringstream ss(line);
            counter = 0;
            while (getline(ss,line,',') ) {
                if(counter == 0) {
                    int x = stoi(line);
                    datapair.first = x;
                }
                else if(counter == 1) {
                    int x = stoi(line);
                    datapair.second = x;
                }
                counter++;
            }
            TotalFile.push_back(datapair);
            datapair.first = 0;
            datapair.second = 0;
        }    
        i++;
    }
    return TotalFile;
};

vector<pair<int,int> > read_routes_test()  {
    //creating file pointer
    ifstream file;

    //opens file to be read
    //Gives us Source airport ID,Destination airport ID
    file.open("Testing_routes.csv");

    //Creates a vector of pairs
    vector<pair<int,int> > TotalFile;
    //Creates pair
    pair<int,int> datapair(0,0);
    //creates a temporary string called line to take each cell
    string line;
    //counter to determine place in airport
    int counter = 0;
    //reads while the file still has values to be read
    int i = 0;
    //while(file.good() && i < 3255){
    while(file.good()){
        while(getline(file,line) ) {
            stringstream ss(line);
            counter = 0;
            while (getline(ss,line,',') ) {
                if(counter == 0) {
                    int x = stoi(line);
                    datapair.first = x;
                }
                else if(counter == 1) {
                    int x = stoi(line);
                    datapair.second = x;
                }
                counter++;
            }
            TotalFile.push_back(datapair);
            datapair.first = 0;
            datapair.second = 0;
        }    
        i++;
    }
    return TotalFile;
};

vector<vector<string>> read_file_test() {
    //creating file pointer
    ifstream file;

    //opens file to be read
    file.open("Testing_airports.csv");

    //Created two vectors, TotalFile creates a vector of vectors that takes in each row called a vector datapoint
    //datapoint creates a set of values enumerated by ',' which means each index of the datapoint will be date, state, and deaths
    vector<vector<string> > TotalFile;
    vector<string> line;
    //reads while the file still has values to be read
    int i = 0;
    while(file.good()){
        // if(i == 50)
        // break;
        //creates a temporary string called line to take each 
        string datapoint;
        while(getline(file,datapoint)){
            std::stringstream ss(datapoint);
            while(getline(ss,datapoint, ',')){
                line.push_back(datapoint);
            }
            //uncomment this if you want to select a specific country
            // if(line[2] == "Peru"){
            //     TotalFile.push_back(line);
            // }
            // uncomment this if you want all airports
            vector<string> temp;
            temp.push_back(line[0]);
            temp.push_back(line[1]);
            temp.push_back(line[line.size()-3]);
            temp.push_back(line[line.size()-2]);
            temp.push_back(line[line.size()-1]);
            TotalFile.push_back(temp);
            //leave this line clear at all times
            line.clear();
            
        }
        i++;

    }
    return TotalFile;
};

vector<vector<string>> read_file() {
    //creating file pointer
    ifstream file;

    //opens file to be read
    file.open("airports_filtered.csv");

    //Created two vectors, TotalFile creates a vector of vectors that takes in each row called a vector datapoint
    //datapoint creates a set of values enumerated by ',' which means each index of the datapoint will be date, state, and deaths
    vector<vector<string> > TotalFile;
    vector<string> line;
    //reads while the file still has values to be read
    int i = 0;
    while(file.good()){
        // if(i == 50)
        // break;
        //creates a temporary string called line to take each 
        string datapoint;
        while(getline(file,datapoint)){
            std::stringstream ss(datapoint);
            while(getline(ss,datapoint, ',')){
                line.push_back(datapoint);
            }
            //uncomment this if you want to select a specific country
            // if(line[2] == "Peru"){
            //     TotalFile.push_back(line);
            // }
            // uncomment this if you want all airports
            vector<string> temp;
            temp.push_back(line[0]);
            temp.push_back(line[1]);
            temp.push_back(line[line.size()-3]);
            temp.push_back(line[line.size()-2]);
            temp.push_back(line[line.size()-1]);
            TotalFile.push_back(temp);
            //leave this line clear at all times
            line.clear();
            
        }
        // for(int count = 0; count < 5; count++){
        //     std::getline(file, datapoint, ',');
        //     line.push_back(datapoint); 
        // }
        // if(line[2] == "United States"){
        //     TotalFile.push_back(line);
        // }
        // line.clear();
        i++;

    }

    //TotalFile.resize(20);
    return TotalFile;
};

vector<string> read_date(string full_date) {
    std::istringstream ss(full_date);
    string token;
    vector<string> dates;
    while(std::getline(ss, token, '/')) {
        dates.push_back(token);
    }

    return dates;
};
int returnDateIndex(string month, string year){
int x = stoi(month); 
--x;
if(year == "2020"){
    return x;
}
else{
x = x + 12;
return x;
}
return -1;
}
void clean_data() {
    
};
}