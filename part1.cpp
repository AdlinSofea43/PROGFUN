// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT1L 
// Names: YASMIN IRDINA BINTI ZULKIPPLI | AIDA MAISARAH BINTI HISAM | ADLIN SOFEA BINTI ADAM SAFFIAN 
// IDs: 1221302357 | 1211103282 | 1211103656
// Emails: 1221302357@student.mmu.edu.my | 1211103282@student.mmu.edu.my | 1211103656@student.mmu.edu.my
// Phones: 0123053403 | 01119534599 | 0192834238
// ********************************************************* 

#include "pf/helper.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <iomanip> 
#include <map>
using namespace std;

int column = 5; int row = 5; int numofZombie = 1; char alien = 'A';
int currentRow, currentCol; const int ROW = 10, COL = 10; char gameBoard[ROW][COL];

class Gameboard
{
  private:
   vector< vector<char> > map_; 
   int dimX_, dimY_; 
  
  public:
    Gameboard(int dimX = column, int dimY = row);  
    void init(int dimX, int dimY);  
    void display(); void displaydefaultSettings();
    void displayMainMenu(); void howtoplay();
    void zombie(int dimX, int dimY, int zombie = numofZombie);
    void command(int currentRow, int currentCol);
};

Gameboard::Gameboard(int dimX, int dimY)
{
    init(dimX, dimY);
}

void Gameboard::init(int dimX, int dimY)
{
   dimX_ = column;
   dimY_ = row; 

   char objects[15] = {' ',' ',' ',' ',' ',' ',' ',' ','R','H','P','>','<','^','v'};
   int noOfObjects = 16; 
   
   map_.resize(dimY_); 
   for (int i = 0; i < dimY_; ++i)
    { map_[i].resize(dimX_); }
    
   for (int i = 0; i < dimY_; ++i)
    {
     for (int j = 0; j < dimX_; ++j)
      {
       int objNo = rand() % noOfObjects;
       map_[i][j] = objects[objNo];
      }
    }

    int midR= row/2;
    int midC= column/2;

    map_[midR][midC]= 'A';
}

void Gameboard::command(int currentRow, int currentCol)
{
    string command; char alien = 'A'; int dimx; int dimy; char run; 
    char choice; char direction; char help; char trail = '.'; 
    // char arrow, save, load, quit;
    
    int midR = row/2;
    int midC = column/2;
    map_[midR][midC] = alien;

    int newRow; int newCol;

    cout << "Are you ready to play? (y/n) = " ;    
    cin >> command;
    system("pause");
    
    if (command == "y" || command == "Y")
      while (run = true) 
      {
        
        if (midR >= 0 && midR < row && midC >= 0 && midC < column) 
        { map_[midR][midC] = alien; }
        else
        { std::cerr << "Error: midR and midC are out of bounds." << std::endl; }
    
        char directionAlien;
        cout << "\n\nYou can only type out one of these following commands;\nleft, right, up, down or quit. \nEnter your command : ";
        cin >> command;

        if (command == "right" || command == "right")
        { map_[midR][midC] = trail; midC -= 1; map_[midR][midC] = alien;}
        
        else if (command == "left" || command == "Left")
        { map_[midR][midC] = trail; midC += 1; map_[midR][midC] = alien;}
    
        else if (command == "up" || command == "Up")
        { map_[midR][midC] = trail; midR -= 1; map_[midR][midC] = alien;}
    
        else if (command == "down" || command == "Down")
        { map_[midR][midC] = trail; midR += 1; map_[midR][midC] = alien;}
    
        else if (command == "quit" || command == "Quit")
        {
            break;
        }

        else
        { cout << "Alien try to get out of border" << endl; run = false; }
        
        system("cls"); display();
        
        gameBoard[currentRow][currentCol] = trail;

        currentRow = newRow;
        currentCol = newCol;

        gameBoard[currentRow][currentCol] = 'A';

        cout << endl;
        cout << " ";
        for (int j = column - 1; j <= column + 1; ++j)
        { cout << "+-"; }
        cout << "+" << endl;

        cout << setw(1) << (dimY_ - row);
        for (int j = column - 1; j <= column + 1; ++j)
        { cout << "|" << map_[row][j]; }
        cout << "|" << endl;

        cout << " ";
        for (int j = column - 1; j <= column + 1; ++j)
        { cout << "+-"; }
        cout << "+" << endl;
    }
}

// void Gameboard::zombie(int dimX, int dimY, int zombie)
// {
//     int x; int y; int zombienum; int zombiecolumn; int zombierow;
//     zombie = zombienum + 1; dimX = zombiecolumn; dimY = zombierow;
    
//     x = rand() % zombiecolumn;
//     y = rand() % zombierow;

//     char zombies[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
//     // int noOfObjects = 9;
//     // for (int i = 0; i < dimY_; ++i)
//     // {
//     //     for (int j = 0; j < dimX_; ++j)
//     //     {
//     //         int objNo = rand() % noOfObjects;
//     //         map_[i][j] = zombies[numofZombie];
//     //     }
//     // }

//     for (int z = 0; z <= zombienum; ++z)
//         while (z != zombienum + 1)
//             { cout << map_[x][y] << zombies[z]; }
    
// }

void Gameboard::howtoplay()
{
    system("cls");
    cout << endl;
    cout << "+---------------------------------------------+" << endl;
    cout << "|                 How to Play?                |" << endl;
    cout << "|=============================================|" << endl;
    cout << "| These are the commands that you can use     |" << endl;
    cout << "| while playing the game !                    |" << endl;
    cout << "+---------------------------------------------+" << endl;
    cout << "| Command |            Function               |" << endl;
    cout << "+---------------------------------------------+" << endl;
    cout << "| up      | Move your Alien upwards           |" << endl;
    cout << "| down    | Move your Alien downwards         |" << endl;
    cout << "| left    | Move your Alien to the left       |" << endl;
    cout << "| right   | Move your Alien to the right      |" << endl;
    cout << "| arrow   | Change the direction of an arrow  |" << endl;
    cout << "| help    | Display these commands again      |" << endl;
    cout << "| save    | Save your current game progress   |" << endl;
    cout << "| load    | Load your previously saved game   |" << endl;
    cout << "| quit    | Quit your current game            |"<< endl;
    cout << "+---------------------------------------------+" << endl;
    cout << endl;

    system("pause");
    system("cls");
}

void Gameboard::display() 
{
    
    system("cls");
    cout << endl; 
    cout << " ----------------_" << endl;
    cout << "  (ФwФ):Alien VS Zombie:[¬º-°]¬ " << endl;
    cout << " ----------------_" << endl;
    cout << endl;
    
    for (int i = 0; i < dimY_; ++i)
    {
        cout << " ";
        for (int j = -1; j < dimX_; ++j)
        { cout << "+-"; }
        cout << "+" << endl;
        
        cout << setw(2) << (dimY_ - i) << " ";
        
        for (int j = 0; j < dimX_; ++j)
        { cout << "|" << map_[i][j]; }
        cout << "|" << endl;
    }
    
    cout << " ";
    for (int j = -1; j < dimX_; ++j)
    { cout << "+-"; }
    cout << "+" << endl;
    
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        
        if (digit == 0)
            cout << " ";
        else
            cout << setw(2) << digit << " ";
    }

    cout << endl;
    cout << " ";
    for (int j = -1; j < dimX_; ++j)
    { cout << " " << (j + 1) % 10; }
    cout << endl << endl;
}

void Gameboard::displayMainMenu()
{
    char choice;

    cout << endl;
    cout << "+---------------------------------------------+" << endl;
    cout << "|                  Welcome ~~                 |" << endl;
    cout << "|=============================================|" << endl;
    cout << "| Select:                                     |" << endl;
    cout << "|                                             |" << endl;
    cout << "| 1 => Play Alien VS Zombie                   |" << endl;
    cout << "| 2 => How to Play?                           |" << endl;
    cout << "|---------------------------------------------|" << endl;
    cout << "| 3 => Quit                                   |" << endl;
    cout << "+---------------------------------------------+" << endl;
    cout << endl;

    cout << "Your choice => ";
    cin >> choice;
    choice = toupper(choice);
    cout << endl;
    switch (choice)
    {
    case '1':
        displaydefaultSettings();
        break;
    case '2':
        howtoplay();
        displayMainMenu();
    case '3':
        cout << "Do come & play again!";
        break;
    }  
};

void Gameboard::displaydefaultSettings() 
{
    char yesorno;
    
    system("cls");
    cout << endl;
    cout << "+---------------------------------------------+" << endl;
    cout << "|            Default Game Settings            |" << endl;
    cout << "|=============================================|" << endl;
    cout << "| Board Rows    : "<<setw(3)<<row<<"                         |" << endl;                  
    cout << "|---------------------------------------------|" << endl;
    cout << "| Board Columns : "<<setw(3)<<column<<"                         |" << endl;                
    cout << "|---------------------------------------------|" << endl;
    cout << "| Zombie Count  : "<<setw(3)<<numofZombie<<"                         |" << endl;                               
    cout << "+---------------------------------------------+" << endl;
    cout << endl;
   
    cout << "Do you want to change the settings? (y/n) = " ; 
    cin >> yesorno ;

    if (yesorno == 'y')
    {
        system ("cls");
        cout << "\nEnter number of rows = " ;
        cin >> row;
        while (row % 2 ==0)
        {
            cout << "\nInvalid number! Please enter odd numbers only" << endl;
            cout << "Enter number of rows =  " ;
            cin >> row;
        }
        
        cout << "\nEnter number of column = "; 
        cin >> column;
        while (column % 2 ==0)
        {
            cout << "\nInvalid number! Please enter odd numbers only" << endl;
            cout << "Enter number of column = ";
            cin >> column;
        }
        
        cout << "\nEnter number of zombie(s) = ";
        cin >> numofZombie;
        while (numofZombie > 9)
        {
            cout << "\nInvalid! You can only have at most 9 zombies" << endl;
            cout << "Enter number of zombie(s) = ";
            cin >> numofZombie;
        }

        system("cls");
        cout << "Let's Play !" << endl;
        init(column, row);
        //zombie(column, row, numofZombie);
        displaydefaultSettings();
    }
    
    else if (yesorno == 'n')
    {
        cout << "Let's play the game !!" << endl;
        display();
        //zombie(column, row, numofZombie);
        //command(row, column);
    }
    
    else 
    {
        cout << "Invalid input !" << endl;
        displaydefaultSettings();
    }
}

int main()
{
    Gameboard g;

    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    // pf::Pause();

    srand(time(NULL));
    g.displayMainMenu();
    g.command(row, column);
}
