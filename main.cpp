#include "TemperatureDatabase.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

// Description: Reads information from file and stores values in 2D vector
// Input: Filename, number of rows and columns
// Output: 2D vector with elevation numbers
vector<vector<int> > loadImage(int &numRows, int &numColumns, string fileName) {
    // Start infile stream and load with given filename
    ifstream inFile (fileName);

    // Check if able to open
    if (!inFile.is_open()) {
        cout << "Unable to open " << fileName << endl;
        exit(1);
    }

    // Create vector to store data
    vector<vector<int> > values(numRows, vector<int> (numColumns));

    // Store elevation data in 2d vector
    int elevation = -1;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            inFile >> elevation;
            values.at(i).at(j) = elevation;
        }
    }

    // Close file stream
    inFile.close();

    // Return the pixel values
    return values;
}

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Usage: " << argv[0] << " data_file query_file" << endl;
		return 1;
	} else {
		TemperatureDatabase database;
		database.loadData(argv[1]);
		database.performQuery(argv[2]);
	}


}
