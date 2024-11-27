// Name : Charlie Tuesares
// ID : 1123532
// Date : 11/27/2024

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Comparator for the max heap
struct TaskComparator {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        return a.first < b.first; // Max heap: higher priority comes first
    }
};

void manageTasks(const vector<string>& operations) {
    // Max heap to store tasks as (priority, task_name)
    priority_queue<pair<int, string>, vector<pair<int, string>>, TaskComparator> maxHeap;

    for (const string& operation : operations) {
        if (operation.substr(0, 3) == "ADD") {
            // Parse the ADD command
            istringstream ss(operation);
            string command, taskName;
            int priority;
            ss >> command >> taskName >> priority;

            maxHeap.push({priority, taskName}); // Add task to the heap
        } else if (operation == "GET") {
            // Handle GET command
            if (!maxHeap.empty()) {
                cout << maxHeap.top().second << endl; // Output the highest-priority task name
                maxHeap.pop(); // Remove it from the heap
            } else {
                cout << "No tasks available" << endl; // No tasks in the heap
            }
        }
    }

    // Collect and display remaining tasks
    vector<pair<int, string>> remainingTasks;
    while (!maxHeap.empty()) {
        remainingTasks.push_back(maxHeap.top());
        maxHeap.pop();
    }

    // Output remaining tasks in descending order of priority
    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remainingTasks.size(); ++i) {
        cout << "('" << remainingTasks[i].second << "', " << remainingTasks[i].first << ")";
        if (i < remainingTasks.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline after the integer input

    vector<string> operations(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, operations[i]); // Read each operation
    }

    // Process the operations
    manageTasks(operations);

    return 0;
}
