﻿#include <iostream>
#include <cassert>
#include <vector>

//class for tree and branches:
class Branch
{
    Branch* parent;
    int branchCount;
    std::vector<Branch*> branches;
    std::string elvenName;

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
        std::string temp;
        std::cout << "Enter elf's name: ";
        std::cin >> temp;
        if (temp == "None");
        else elvenName = temp;
    }

    std::string getName()
    {
        return elvenName;
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
       
    //constructor
    Branch(Branch* inParent, int inCount)
    {

        parent = inParent;
        branchCount = inCount;
        elvenName = "";
        /* for (int i = 0; i < branchCount; i++)
        {
            Branch* childBranch = new Branch (parent, childCount);
            branches.push_back(childBranch);
        }*/
        
    }

    //search elf
    Branch* searchElf(std::string target)
    {
        
        for (int i = 0; i < branchCount; i++)
        {
            if (branches[i]->getName() == target)
                return branches[i];
            for (int j = 0; j < branches[i]->getCount(); j++)
            {
                branches[i]->getBranch(j)->searchElf(target);
            }
        }
        return nullptr;
    }

    //search elf's neighbours:
    int neighboursSearch()
    {
        int count = 0;
        if (branchCount > 0)
        {
            for (int i = 0; i < branchCount; i++)
            {
                if (branches[i]->getName() != "") count++;
            }
        }
        else
        {
            parent->neighboursSearch();
            count--;
        }
        return count;
        
    }
};

class Forest
{
    std::vector<Branch*> wood;

public:

    void makeWood()
    {
        std::string n;
        for (int i = 0; i < 5; i++)
        {
            std::cout << "Tree #" << i << std::endl;
            //make one tree
            int largeBranchCount = (3 + rand() % 3);
            std::cout << "lBranches:" << largeBranchCount << std::endl;
            Branch* tree = new Branch(nullptr, largeBranchCount);
            for (int j = 0; j < largeBranchCount; j++)
            {
                //make one large branch
                int mediumBranchCount = (2 + rand() % 2);
                std::cout << "mBranches:" << mediumBranchCount << std::endl;
                Branch* largeBranch = new Branch(tree, mediumBranchCount);
                largeBranch->loadElf();
                for (int k = 0; k < mediumBranchCount; k++)
                {
                    //make one medium branch
                    Branch* mediumBranch = new Branch(largeBranch, 0);
                    mediumBranch->loadElf();
                    largeBranch->loadBranches(mediumBranch);
                }
                tree->loadBranches(largeBranch);
            }
            wood.push_back(tree);
        }
    }

    Branch* getTree(int index)
    {
        return wood[index];
    }

    Branch* find(std::string target)
    {
              
        for (int i = 0; i < 5; i++)
        {
            return wood[i]->searchElf(target);
            
        }
        return nullptr;
    }
    
};

int main()
{
    std::cout << "Let's make wood and populate them." << std::endl;
    Forest forest;
    forest.makeWood();
    std::string target;
    std::cout << "Choose elven's name: ";
    std::cin >> target;
    
    std::cout << "This Elf has " << forest.find(target)->neighboursSearch() << "neighbours!" << std::endl;
}