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
    int func(Employee* u, vector<Employee*>&employees, int id)
    {
        int sum=0;
        sum+=u->importance;

        for(auto it: u->subordinates)
        {
            sum+=getImportance(employees, it);
        }

        return sum;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sum=0;

        for(auto it: employees)
        {
            if(it->id==id)
            {
                sum+=func(it, employees, id);
            }
        }

        return sum;
    }
};
