#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

int main() {
    vector<int> vec(100000);
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = vec.size() - i;
    }

    auto startTime = chrono::high_resolution_clock::now();
    sort(vec.begin(), vec.end());
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    cout << "Execution time of STL sort: " << duration.count() << " microseconds" << endl;
    cout << "First 10 integers: ";
    for (int i = 0; i < 10; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    cout << "Last 10 integers: ";
    for (int i = vec.size() - 10; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    vec.clear();
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = vec.size() - i;
    }

    startTime = chrono::high_resolution_clock::now();
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
    endTime = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    cout << "Execution time of Bubble Sort: " << duration.count() << " microseconds" << endl;
    cout << "First 10 integers: ";
    for (int i = 0; i < 10; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    cout << "Last 10 integers: ";
    for (int i = vec.size() - 10; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}

