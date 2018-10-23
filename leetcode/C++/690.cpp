#include <vector>
using namespace std;
class Employee
{
  public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution
{

  public:
    int sum = 0;
    int getImportance(vector<Employee *> employees, int id)
    {
        sum_e(employees, find_e(employees, id));
        return sum;
    }
    Employee *find_e(vector<Employee *> empls, int id)
    {
        for (auto e : empls)
        {
            if (e->id == id)
                return e;
        }
    }
    void sum_e(vector<Employee *> empls, Employee *e)
    {
        sum += e->importance;
        if (!e->subordinates.empty())
        {
            for (auto i : e->subordinates)
            {
                sum_e(empls, find_e(empls, i));
            }
        }
    }
};