// Name : Charlie Tuesares
// ID : 1123532
// Date : 11/27/2024

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Task structure to store profit and deadline
struct Task {
    int profit;
    int deadline;
};

// Comparator for the max heap
struct Compare {
    bool operator()(const Task& a, const Task& b) {
        return a.profit < b.profit; // Max heap: prioritize higher profit
    }
};

// Function to schedule tasks and calculate maximum profit
pair<int, vector<int>> scheduleTasks(const vector<Task>& tasks, int maxDeadline) {
    // Max heap to prioritize tasks by profit
    priority_queue<Task, vector<Task>, Compare> maxHeap;
    
    // Add all tasks to the max heap
    for (const auto& task : tasks) {
        maxHeap.push(task);
    }
    
    // Array to track which slots are free
    vector<int> slots(maxDeadline + 1, -1); // -1 indicates the slot is free
    vector<int> scheduledProfits; // Profits of scheduled tasks
    int totalProfit = 0;
    
    // Process tasks in order of maximum profit
    while (!maxHeap.empty()) {
        Task currentTask = maxHeap.top();
        maxHeap.pop();

        // Try to schedule the task in the latest possible free slot
        for (int slot = currentTask.deadline; slot > 0; --slot) {
            if (slots[slot] == -1) { // If the slot is free
                slots[slot] = currentTask.profit; // Assign this task
                totalProfit += currentTask.profit; // Add the profit
                scheduledProfits.push_back(currentTask.profit); // Record profit
                break;
            }
        }
    }

    return {totalProfit, scheduledProfits};
}

int main() {
    int n;
    cout << "Enter the number of tasks: ";
    cin >> n;

    vector<Task> tasks(n);
    int maxDeadline = 0;

    cout << "Enter profit and deadline for each task:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].profit >> tasks[i].deadline;
        maxDeadline = max(maxDeadline, tasks[i].deadline); // Track maximum deadline
    }

    // Schedule tasks and get the result
    pair<int, vector<int>> result = scheduleTasks(tasks, maxDeadline);

    // Output the results
    cout << "Maximum Profit: " << result.first << endl;
    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < result.second.size(); ++i) {
        cout << result.second[i];
        if (i < result.second.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
