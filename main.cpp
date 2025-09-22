#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> dailyTemps;
    ifstream file("data.txt");

    if (!file) {
        cerr << "Error: could not open data.txt\n";
        return 1;
    }

    // Read numbers from file into the vector
    int value;
    while (file >> value) {
        dailyTemps.push_back(value);
    }
    file.close();

    // Show basic info
    cout << "Size: " << dailyTemps.size() << endl;
    cout << "First day temp: " << dailyTemps.front() << endl;
    cout << "Last day temp: " << dailyTemps.back() << endl;

    // Calculate average temperature
    double avg = accumulate(dailyTemps.begin(), dailyTemps.end(), 0.0) / dailyTemps.size();
    cout << "Average temperature: " << avg << endl;

    // Sort values in ascending order
    sort(dailyTemps.begin(), dailyTemps.end());
    cout << "Sorted temps: ";
    for (int t : dailyTemps) cout << t << " ";
    cout << endl;

    // Display highest and lowest temps
    cout << "Max temp: " << *max_element(dailyTemps.begin(), dailyTemps.end()) << endl;
    cout << "Min temp: " << *min_element(dailyTemps.begin(), dailyTemps.end()) << endl;

    return 0;
}
