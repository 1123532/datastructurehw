// Name : Charlie Tuesares
// ID : 1123532
// Date : 11/27/2024

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Define a structure to store elements in the heap
struct Element {
    int value;      // Value of the element
    int arrayIndex; // Index of the array the element belongs to
    int elementIndex; // Index of the element in the array

    // Comparator for the priority queue (min heap)
    bool operator>(const Element& other) const {
        return value > other.value; // Min heap based on the value
    }
};

// Function to merge K sorted arrays
vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap; // Min heap
    vector<int> result; // Result array

    // Initialize the heap with the first element of each array
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    // Process the heap until it is empty
    while (!minHeap.empty()) {
        // Extract the smallest element
        Element current = minHeap.top();
        minHeap.pop();
        result.push_back(current.value);

        // Insert the next element from the same array into the heap
        if (current.elementIndex + 1 < arrays[current.arrayIndex].size()) {
            int nextValue = arrays[current.arrayIndex][current.elementIndex + 1];
            minHeap.push({nextValue, current.arrayIndex, current.elementIndex + 1});
        }
    }

    return result;
}

int main() {
    int k;
    cout << "Enter the number of sorted arrays: ";
    cin >> k;

    vector<vector<int>> arrays(k);
    cout << "Enter the sorted arrays:" << endl;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n; // Number of elements in the array
        arrays[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> arrays[i][j];
        }
    }

    // Merge the sorted arrays
    vector<int> mergedArray = mergeKSortedArrays(arrays);

    // Output the merged array
    cout << "Merged Array: [";
    for (size_t i = 0; i < mergedArray.size(); ++i) {
        cout << mergedArray[i];
        if (i < mergedArray.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
