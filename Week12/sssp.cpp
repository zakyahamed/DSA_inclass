#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent a weighted edge
struct Edge {
    int destination;
    int weight;
};

// Dijkstra's algorithm function
vector<int> dijkstra(const vector<vector<Edge>>& graph, int source) {
    int numNodes = graph.size();
    vector<int> distances(numNodes, INT_MAX);
    vector<bool> visited(numNodes, false);
    distances[source] = 0;

    for (int i = 0; i < numNodes; ++i) {
        int minDist = INT_MAX;
        int minNode = -1;
        for (int j = 0; j < numNodes; ++j) {
            if (!visited[j] && distances[j] < minDist) {
                minDist = distances[j];
                minNode = j;
            }
        }

        visited[minNode] = true;
        for (const auto& edge : graph[minNode]) {
            int destination = edge.destination;
            int weight = edge.weight;
            if (!visited[destination] && distances[minNode] != INT_MAX && distances[minNode] + weight < distances[destination]) {
                distances[destination] = distances[minNode] + weight;
            }
        }
    }

    return distances;
}

// Function to calculate the average time from each source city to the other cities
vector<double> calculateAverageTime(const vector<vector<Edge>>& graph, int numNodes) {
    vector<double> averageTimes(numNodes);
    for (int source = 0; source < numNodes; ++source) {
        vector<int> distances = dijkstra(graph, source);
        int totalDistance = 0;
        for (int i = 0; i < numNodes; ++i) {
            if (i != source) {
                totalDistance += distances[i];
            }
        }
        double averageTime = static_cast<double>(totalDistance) / (numNodes - 1);
        averageTimes[source] = averageTime;
    }
    return averageTimes;
}

int main() {
    // Create the graph
    int numNodes = 6;
    vector<vector<Edge>> graph(numNodes);
    graph[0] = {{1, 10}, {4, 15}, {5, 5}};
    graph[1] = {{0, 10}, {2, 10}, {3, 30}};
    graph[2] = {{1, 10}, {3, 12}, {4, 5}};
    graph[3] = {{1, 30}, {2, 12}, {5, 20}};
    graph[4] = {{0, 15}, {2, 5}};
    graph[5] = {{0, 5}, {3, 20}};

    // Calculate the shortest paths from each source city
    for (int source = 0; source < numNodes; ++source) {
        vector<int> distances = dijkstra(graph, source);
        cout << "Shortest times from City " << source << " to all other cities:\n";
        for (int city = 0; city < numNodes; ++city) {
            if (city != source) {
                cout << "City " << city << ": " << distances[city] << "\n";
            }
        }
        cout << "Average time taken: ";
        double totalDistance = 0;
        for (int i = 0; i < numNodes; ++i) {
            if (i != source) {
                totalDistance += distances[i];
            }
        }
        double averageTime = totalDistance / (numNodes - 1);
        cout << averageTime << "\n\n";
    }

    // Calculate the average times from each source city to the other cities
    vector<double> averageTimes = calculateAverageTime(graph, numNodes);

    // Find the city/cities with the smallest average time
    double minAverageTime = INT_MAX;
    vector<int> minAverageCities;
    for (int source = 0; source < numNodes; ++source) {
        double averageTime = averageTimes[source];
        if (averageTime < minAverageTime) {
            minAverageTime = averageTime;
            minAverageCities.clear();
            minAverageCities.push_back(source);
        } else if (averageTime == minAverageTime) {
            minAverageCities.push_back(source);
        }
    }

    // Display the city/cities with the smallest average time
    cout << "City/cities with the smallest average time:\n";
    for (int city : minAverageCities) {
        cout << "City " << city << "\n";
    }

    return 0;
}
