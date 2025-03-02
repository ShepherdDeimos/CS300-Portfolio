#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open the input file (FahrenheitTemperature.txt) in the same directory as the executable
    ifstream inputFile("FahrenheitTemperature.txt");

    // Check if the file is opened successfully
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Open the output file (CelsiusTemperature.txt) in the same directory as the executable
    ofstream outputFile("CelsiusTemperature.txt");

    // Check if the file is opened successfully
    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    // Conversion factor from Fahrenheit to Celsius
    const double FAHRENHEIT_TO_CELSIUS = 5.0 / 9.0;

    // Read and process data from the input file
    string city;
    int fahrenheit;
    while (inputFile >> city >> fahrenheit) {
        // Convert Fahrenheit to Celsius using the formula
        double celsius = (fahrenheit - 32.0) * FAHRENHEIT_TO_CELSIUS;

        // Write the city and its temperature in Celsius to the output file
        outputFile << city << " " << celsius << endl;
    }

    // Close both input and output files
    inputFile.close();
    outputFile.close();

    cout << "Conversion completed. Data written to CelsiusTemperature.txt." << endl;

    return 0;
}
