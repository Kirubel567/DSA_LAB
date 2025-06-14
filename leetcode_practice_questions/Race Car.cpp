#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int racecar(int target) {
        // Each state: {stepsTaken, currentPosition, currentSpeed}
        queue<vector<int>> states;
        states.push({0, 0, 1});

        while (!states.empty()) {
            auto current = states.front();
            states.pop();

            int steps = current[0];
            int position = current[1];
            int speed = current[2];

            // If we've reached the target position, return steps taken
            if (position == target) return steps;

            // Prune states that have overshot too far
            if (abs(position) > target * 2) continue;

            // Accelerate: move forward with double speed
            states.push({steps + 1, position + speed, speed * 2});

            // Decide if we should reverse direction
            bool passedTarget = (position + speed > target && speed > 0) || 
                                (position + speed < target && speed < 0);

            if (passedTarget) {
                // Reverse speed direction, reset speed to +/-1
                int newSpeed = speed > 0 ? -1 : 1;
                states.push({steps + 1, position, newSpeed});
            }
        }

        return 0; // fallback, though problem guarantees a solution
    }
};
