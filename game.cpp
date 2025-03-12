#include <iostream>
#include <cstdlib> 
#include "myfunctions.h"
#include <vector>
#include <string>
using namespace std;

// if 3 turns in a row with value of sum, then will at first have +3, then +2, then +1 , 
// then 0, that forces computer to make discounting turns too

//  Complile proj steps: 
//  Step 1:  Open the terminal or command prompt. 
//  Step 2:  Navigate to the dir where your proj lives. 
//  Step 3:  Compile using the following command: 
//  g++ game.cpp -o game 
//  Step 4:  Run the executable file using the following command: 
//  ./game 
// Enjoy the terminal version of program  
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

vector<int> GenerateRandomNums(int size) {
  vector<int> randoms;
  for (int i = 0; i < size; i++) {
    int random = rand() % 6 + 1;
    randoms.push_back(random);
  }
  return randoms;
} 

void PrintGameTree(GameTree* node, int level) {
    // Print the current node data with indentation based on level
    for (int i = 0; i < level * 2; ++i) {
        cout << " ";
    }
    for (int i=0; i<node->data.size(); i++){
        cout << node->data.at(i) << " ";
    }
    cout << endl;

    // Recurs. printing of the child nodes
    // for (GameTree* child : node->children) {
    //   PrintGameTree(child, level + 1);
    // }

    // Control the level of the tree (In case ind. lvl is too high it will print each vector separetly)
    if (level < 10){
      for (GameTree* child : node->children) {
        PrintGameTree(child, level + 1);
      }
    }
}

// the ~clean version of the filling tree function
void FullfillGameTreeBackup(GameTree* node, vector<int> data) {
  for (int i = 0; i < data.size(); i+=2) {
    vector<int> temporary = data;
    temporary[i] = temporary[i] + temporary[i+1];
    if (temporary[i]>6){
      temporary[i] = temporary[i] % 6;
    }
    temporary.erase(temporary.begin() + i + 1);
    node->AddChild(new GameTree(temporary));
  }
  for (GameTree* child : node->children) {
      FullfillGameTreeBackup(child, child->data);
  }
}

void FullfillGameTree(GameTree* node, vector<int> data) {
   
    for (int i = 0; i < data.size(); i+=2) {
      if (data.size()%2 == 1) {
        cout << "Choose option: " <<endl;
        cout << "1. Sum two numbers" << endl;
        cout << "2. Delete the number that does not have a pair" << endl;
        int option;
        cin >> option;
        if (option == 1) {
            vector<int> temporary = data;
            temporary[i] = temporary[i] + temporary[i+1];
            if (temporary[i]>6){
              temporary[i] = temporary[i] % 6;
            }
            temporary.erase(temporary.begin() + i + 1);
            node->AddChild(new GameTree(temporary));
        } else if (option == 2) {
            vector<int> temporary = data;
            temporary.erase(temporary.begin() + data.size() - 1);
            node->AddChild(new GameTree(temporary));
        } else {
            cout << "\u001b[31mInvalid option, Debil, only 1 and 2 allowed:/\u001b[0m" << endl;
            break;
        }
      } else { // sum is only option
        vector<int> temporary = data;
      temporary[i] = temporary[i] + temporary[i+1];
      temporary.erase(temporary.begin() + i + 1);
      node->AddChild(new GameTree(temporary));
      }
    }
      for (GameTree* child : node->children) {
        FullfillGameTree(child, child->data);
    }

    //   vector<int> temporary = data;
    //   temporary[i] = temporary[i] + temporary[i+1];
    //   temporary.erase(temporary.begin() + i + 1);
    //   node->AddChild(new GameTree(temporary));
    // }
    // for (GameTree* child : node->children) {
    //     FullfillGameTree(child, child->data);
    // }
  
}


// void DeleteTree(TreeNode* node) {
//     for (TreeNode* child : node->Children) {
//         DeleteTree(child);
//     }
//     delete node;
// }

int main() {
    int size;
    cout << "Enter the size of the array: (15-25): ";
    cin >> size;
    vector<int> randoms;
    randoms = GenerateRandomNums(size);
    cout << "Random numbers between 1 and 6: ";
    for (int i = 0; i < randoms.size(); i++) {
      cout << randoms[i] << " ";
    }
    cout << endl;

    GameTree* roots = new GameTree(randoms);
    FullfillGameTreeBackup(roots, randoms);
    cout<<"\nGame Tree:"<<endl;
    PrintGameTree(roots, 0);

    return 0;
}
