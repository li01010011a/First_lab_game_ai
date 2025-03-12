//Author: Lidija Sokolova
//Date: 12/03/2025
//First working version backup
//Don't touch it
#include <iostream>
#include <cstdlib> 
#include "myfunctions.h"
#include <vector>
#include <string>
using namespace std;

//  To compile and run the C++ program, you need to follow the steps given below: 
//  Step 1:  Open the terminal or command prompt. 
//  Step 2:  Navigate to the directory where you have saved the C++ program. 
//  Step 3:  Compile the C++ program using the following command: 
//  g++ game.cpp -o game 
//  The above command will compile the C++ program and generate an executable file named  game . 
//  Step 4:  Run the executable file using the following command: 
//  ./game 
//  The above command will run the C++ program, and you will see the output on the terminal or command prompt.



using namespace std;

class TreeNode {
public:
    string Data;
    vector<TreeNode*> Children;

    // Constructor to initialize node with data
    TreeNode(string data) {
        Data = data;
    }

    // Method to add a child to this node
    void AddChild(TreeNode* child) {
        Children.push_back(child);
    }
};

class GameTree {
  public:
    vector<int> data;
    vector<GameTree*> children;
    GameTree(vector<int> data) {
      this->data = data;
    }
    void AddChild(GameTree* child) {
      children.push_back(child);
    }
};

void PrintGameTree(GameTree* node, int level) {
    // Print the current node's data with indentation based on level
    for (int i = 0; i < level * 2; ++i) {
        cout << " ";
    }
    for (int i=0; i<node->data.size(); i++){
        cout << node->data.at(i) << " ";
    }
    cout << endl;

    // Recursively print the child nodes
    if (level < 1){
      for (GameTree* child : node->children) {
        PrintGameTree(child, level + 1);
      }
    }
}

void FullfillGameTree(GameTree* node, vector<int> data) {
    for (int i = 0; i < data.size(); i+=2) {
      vector<int> temporary = data;
      temporary[i] = temporary[i] + temporary[i+1];
      temporary.erase(temporary.begin() + i + 1);
      node->AddChild(new GameTree(temporary));
    }
    for (GameTree* child : node->children) {
        FullfillGameTree(child, child->data);
    }
}

// Function to print the tree structure
void PrintTree(TreeNode* node, int level) {
    // Print the current node's data with indentation based on level
    for (int i = 0; i < level * 2; ++i) {
        cout << " ";
    }
    cout << node->Data << endl;

    // Recursively print the child nodes
    for (TreeNode* child : node->Children) {
        PrintTree(child, level + 1);
    }
}
void DeleteTree(TreeNode* node) {
    for (TreeNode* child : node->Children) {
        DeleteTree(child);
    }
    delete node;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int random = rand() % 7;
    vector<int> randoms;
    for (int i = 0; i < size; i++) {
      random = rand() % 6 + 1;
      cout << random << endl;
      randoms.push_back(random);
    }
    cout << "Random number between 1 and 6: ";
    for (int i = 0; i < randoms.size(); i++) {
      cout << randoms[i] << " ";
    }

    GameTree* roots = new GameTree(randoms);
    // for (int i = 0; i < randoms.size(); i+=2) {
    //   vector<int> temporary = randoms;
    //   temporary[i] = temporary[i] + temporary[i+1];
    //   temporary.erase(temporary.begin() + i + 1);
    //   roots->AddChild(new GameTree(temporary));
    // }
    FullfillGameTree(roots, randoms);
    GameTree* childs1 = new GameTree({1, 2});
    GameTree* childs2 = new GameTree({3, 4});
    roots->AddChild(childs1);
    roots->AddChild(childs2);
    cout<<"\nGame Tree:"<<endl;
    PrintGameTree(roots, 0);
    // Create the root node
    // TreeNode* root = new TreeNode("Root");

    // Create child nodes for the root
    // TreeNode* child1 = new TreeNode("Child 1");
    // TreeNode* child2 = new TreeNode("Child 2");

    // Add the child nodes to the root node
    // root->AddChild(child1);
    // root->AddChild(child2);

    // string str = "Child :";
    // for (int i = 0; i < randoms.size(); i++) {
    //   root->AddChild(new TreeNode("Random number: " + to_string(randoms[i])));
    //   str += to_string(randoms[i]) + " ";
    // }
    // root->AddChild(new TreeNode("Another node: " + str));

    // Add child nodes to "Child 1"
    // TreeNode* child1_1 = new TreeNode("Child 1.1");
    // TreeNode* child1_2 = new TreeNode("Child 1.2");
    // child1->AddChild(child1_1);
    // child1->AddChild(child1_2);

    // // Add child node to "Child 2"
    // TreeNode* child2_1 = new TreeNode("Child 2.1");
    // child2->AddChild(child2_1);

    // Print the tree
    // PrintTree(root, 0);

    // Cleanup memory (important to delete dynamic memory used)
    // DeleteTree(root);

    return 0;
}
