#include <string>
#include <vector>
#include "controlgroup.cpp"

using namespace std;

class Group : ControlGroup {
    public:
        string name;
    private:
        vector<ControlGroup> members;
};