/*
Find the minimum number of points needed to cover all given segments on a line.
Input: A sequence of n segments [l1,r1],...,[ln,rn] on a line.
Output: A set of points of minimum size such that each segment [li,ri] contains a point,
i.e., there exists a point x from this set such that li ≤ x ≤ ri.


*/
#include <iostream>
#include <vector>
#include <algorithm>

struct line {
    int li;
    int ri;
    //line(int l, int r) : li(l), ri(r) {}
};

bool rightPointsCompare(const line& a, const line& b) {
    return a.ri < b.ri;
}

void coveringSegmentsByPoints(std::vector<line>& arr) {
    // Sort the segments based on their right end point
    std::sort(arr.begin(), arr.end(), rightPointsCompare);

    // To store the points
    std::vector<int> points;

    // Start with the right end point of the first segment
    int currentPoint = arr[0].ri;
    points.push_back(currentPoint); // Add the first point

    // Iterate through each segment
    for(size_t i=1; i < arr.size(); ++i) {
        // If the currentPoint is not within the current segment, add a new point
        if(currentPoint < arr[i].li) {
            currentPoint = arr[i].ri;
            points.push_back(currentPoint);
        }
    }
    std::cout << points.size() << '\n';
    for(int p : points) {
        std::cout << p << " ";
    }
    std::cout << '\n';
}

int main()
{   
    int n;
    std::cin>>n;
    std::vector<line> coordinates(n);
    for(int i=0; i<n; ++i) {
        int left, right;
        std::cin >> left >> right;
        coordinates[i] = {left, right};
    }
    coveringSegmentsByPoints(coordinates);

    return 0;
}