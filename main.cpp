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

    int value;
    while (file >> value) {
        dailyTemps.push_back(value);   // add values dynamically
    }
    file.close();

    cout << "Size: " << dailyTemps.size() << endl;
    cout << "First day temp: " << dailyTemps.front() << endl;
    cout << "Last day temp: " << dailyTemps.back() << endl;

    double avg = accumulate(dailyTemps.begin(), dailyTemps.end(), 0.0) / dailyTemps.size();
    cout << "Average temperature: " << avg << endl;

    sort(dailyTemps.begin(), dailyTemps.end());
    cout << "Sorted temps: ";
    for (int t : dailyTemps) cout << t << " ";
    cout << endl;

    cout << "Max temp: " << *max_element(dailyTemps.begin(), dailyTemps.end()) << endl;
    cout << "Min temp: " << *min_element(dailyTemps.begin(), dailyTemps.end()) << endl;

    return 0;
}
