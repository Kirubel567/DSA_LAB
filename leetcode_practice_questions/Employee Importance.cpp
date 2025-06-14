#include<iostream> 
#include<vector> 
#include<queue>
#include<unordered_set>
#include<numeric> 
#include<algorithm> 
#include<unordered_map>
using namespace std;


class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
private:
    int calculateImportance(Employee* emp, vector<Employee*>& employees) {
        int totalImportance = emp->importance;

        for (int subId : emp->subordinates) {
            totalImportance += getImportance(employees, subId);
        }

        return totalImportance;
    }

public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto emp : employees) {
            if (emp->id == id) {
                return calculateImportance(emp, employees);
            }
        }
        return 0; // If employee not found
    }
};
