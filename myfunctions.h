using namespace std;
void Intro(){
    cout<<"\u001b[33mAuthor: Lidija Sokolova\n";
    cout<<"Program: Game Artifical Inteligence\n";
    cout<<"Date: March, 8. 2025\n";
    cout<<"Brief: This program simulates a minimax, alpha-beta algorithm game.\n";
    cout<<"Description: In the beggining of the game, the program generates the sequence of numbers from 1 to 6. \nTotal 15 to 25 numbers are generated. The user and the computer take turns to \n1) Sum two numbers (1 and 2, 3 and 4, 5 and 6 etc) and receive 1 point. \n2) Delete the number that does not have a pair and take away 1 point from the enemy \nThe player who has the biigest amount of points win the game. \nThe computer uses the minimax algorithm to determine the best move, while the user can choose any turn.\n\u001b[0m]";
}

// class GameTree {
//     public:
//       vector<int> data;
//       vector<GameTree*> children;
//       GameTree(vector<int> data) {
//         this->data = data;
//       }
//       void AddChild(GameTree* child) {
//         children.push_back(child);
//       }
//   };
// vector<int> GenerateRandomNums(int size) {
//     vector<int> randoms;
//     for (int i = 0; i < size; i++) {
//       int random = rand() % 6 + 1;
//       randoms.push_back(random);
//     }
//     return randoms;
// } 