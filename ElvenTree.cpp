#include <iostream>

class Branch
{
    Branch* parent = nullptr;
    int branchCount = 0;
    Branch** branches = nullptr;

public:
    Branch* getBranch(int index) 
    {
        if (index < 0) return nullptr;
        if (index > branchCount) return nullptr;
        return branches[index];
    }

    int getCount()
    {
        return branchCount;
    }

    static Branch* createBranch(Branch* par, int count)
    {
        Branch* branch = new Branch;
        branch->parent = par;
        branch->branchCount = count;
        branch->branches = new Branch*[count];
            
    }
};

int main()
{
    std::cout << "Hello World!\n";
}