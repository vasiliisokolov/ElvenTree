#include <iostream>
#include <cassert>
#include <vector>

//class for tree and branches:
class Branch
{
    Branch* parent = nullptr;
    int branchCount = 0;
    std::vector<Branch*> branches;
    std::string elvenName = "";

public:
    //get index of the branch
    Branch* getBranch(int index)
    {
        if (index < 0) return nullptr;
        if (index >= branchCount) return nullptr;
        return branches[index];
    }

    int getCount()
    {
        return branchCount;
    }
    
    //input Elf's name
    void loadElf()
    {
        std::cout << "Enter elf's name: ";
        std::cin >> elvenName;
    }

    //load branches
    void loadBranches(Branch* input)
    {
        branches.push_back(input);
    }
   
    //search parent
    Branch* getTopBranch()
    {
        //Если это дерево
        if (parent == nullptr) return nullptr;
        //Если это средняя ветка
        if (parent->parent == nullptr) return parent;
        //Если это маленькая ветка
        return parent->getTopBranch();
    }

    

    Branch(Branch* inParent, int inCount)
    {

        parent = inParent;
        branchCount = inCount;
        /* for (int i = 0; i < branchCount; i++)
        {
            Branch* childBranch = new Branch (parent, childCount);
            branches.push_back(childBranch);
        }*/
    }
};

class Forest
{
    std::vector<Branch*> wood;

public:

    void makeWood()
    {
        
        for (int i = 0; i < 5; i++)
        {
            //make one tree
            int largeBranchCount = (3 + rand() % 5);
            Branch* tree = new Branch(nullptr, largeBranchCount);
            for (int j = 0; j < largeBranchCount; j++)
            {
                //make one large branch
                int mediumBranchCount = (2 + rand() % 3);
                Branch* largeBranch = new Branch(tree, mediumBranchCount);
                for (int k = 0; k < mediumBranchCount; k++)
                {
                    //make one medium branch
                    Branch* mediumBranch = new Branch(largeBranch, 0);
                    largeBranch->loadBranches(mediumBranch);
                }
                tree->loadBranches(largeBranch);
            }
            wood.push_back(tree);
        }
    }
};

int main()
{
    Branch* branch = new Branch(nullptr,4);
}