#include "LL.h"
#include<iostream>
    using namespace std;


template <typename T> 
void printBoard(LL<T> b[], int c) {

    int temp = c;

    for (int i = 0; i < c; i++) {
        cout << endl;
        temp = temp-1;
        for (int j = 0; j < c; j++) {
            int boardSize = b[j].getSize();
            
            if (boardSize == 0 && temp == 0) {
                cout << " - ";
            }
            
            else if (boardSize <= temp){
                cout << " - ";
            } else {
               T TorF = b[j].getNode(temp);
                if (TorF == 0) 
                cout << " R ";

                if (TorF == 1) 
                cout << " B ";

            }
        }
    }

    cout << endl << endl << " A " << " B " << " C " << " D " << " E " << " F " << " G" << endl;

}

template <typename T>
void redPlayer(LL<T> b[], int c, int& p) {

    bool invalidEntry = true;
    int selection = 0;
    char row = '\0';
    cin >> row;

    while (invalidEntry == true) {

    if (int(row) > 64 && int(row) < 72) {
    selection = int(row) - 65;
    invalidEntry = false;
    }

    if (int(row) > 96 && int(row) < 104) {
    selection = int(row) - 97;
    invalidEntry = false;
    }

    if (invalidEntry == true) {
        cout << "Invalid Column" << endl;
        cout << "Red Player Select a row: ";       
        cin >> row;
        }

    if (b[selection].getSize() == c) {
        cout << "Invalid Move" << endl;
        cout << "Red Player Select a row: ";
        cin >> row;
        invalidEntry = true;
    }

    }


    b[selection].tailInsert(false);
    p++;

}

template <typename T>
void bluePlayer(LL<T> b[], int c, int& p) {

    bool invalidEntry = true;
    int selection = 0;
    char row = '\0';
    cin >> row;

    while (invalidEntry == true) {

        if (int(row) > 64 && int(row) < 72) {
        selection = int(row) - 65;
        invalidEntry = false;
        }

        if (int(row) > 96 && int(row) < 104) {
        selection = int(row) - 97;
        invalidEntry = false;
        }

        if (invalidEntry == true) {
            cout << "Invalid Column" << endl;
            cout << "Blue Player Select a row: ";   
            cin >> row;
        }

        if (b[selection].getSize() == c) {
        cout << "Invalid Move" << endl;
        cout << "Blue Player Select a row: ";
        cin >> row;
        invalidEntry = true;
    }

    }

    b[selection].tailInsert(true);
    p++;

}

template <typename T>
bool checkForWinner(LL<T> b[], const int columns, int p) {

bool gameOver = false;

if (p == columns*columns) {
    cout << endl << "Tie.";
    gameOver = true;
}

if (gameOver == false) {
    gameOver = checkVertical(b, columns);
}

if (gameOver == false) {
    gameOver = checkHorizontal(b, columns);
};


if (gameOver == false) {
    gameOver = checkDiagonalfromBase(b, columns);
};

if (gameOver == false) {
    gameOver = checkDiagonalfromTop(b, columns);
};



return gameOver;
}

template <typename T>
bool checkVertical(LL<T> b[], const int columns) {

    bool winner = false;

    for (int i = 0; i < columns; i++) {

    int sizeOfColumn = b[i].getSize();
    int count = 0;
    int inRow = 0;
    bool endOfColumn = false;


    if (sizeOfColumn > 3) {
    typename LL<T>::Iterator iteratorStart = b[i].begin();
    typename LL<T>::Iterator iteratorNext = b[i].begin();

    while (*iteratorNext == *iteratorStart && endOfColumn == false) {
        count++;
        inRow++;
        iteratorNext++;

        if (inRow == 4) {
            winner = true;

            if (*iteratorStart == false) {
            cout << endl << "Red Wins!";
            } else {
            cout << endl << "Blue Wins!";
            }
        }

        if (*iteratorNext != *iteratorStart) {
            inRow = 0;
            iteratorStart = iteratorNext;
            }

        if (count == sizeOfColumn) {
            endOfColumn = true;
        }
    }

    }
    };

    return winner;
}

template <typename T>
bool checkHorizontal(LL<T> b[], const int columns){

    bool winner = false;
    bool endOfRow = false;
    int  counter = 0;

    for (int i = 0; i <= columns; i++) {
        int inRow = 0;
        bool stillCheck = true;
        int z = 0;
        counter++;

        if ((b[i].getSize() > z) && (b[i+1].getSize() > z) && (b[i+2].getSize() > z) && (b[i+3].getSize() > z) && (counter <= columns - 3)) {
        typename LL<T>::Iterator iterator1 = b[i].begin();
        typename LL<T>::Iterator iterator2 = b[i+1].begin();
        typename LL<T>::Iterator iterator3 = b[i+2].begin();
        typename LL<T>::Iterator iterator4 = b[i+3].begin();
        
            
            while ((b[i].getSize() > z) && (b[i+1].getSize() > z) && (b[i+2].getSize() > z) && (b[i+3].getSize() > z) && (counter <= columns - 3) && (stillCheck == true)){          


                if ((*iterator1 == *iterator2) && (*iterator1 == *iterator3) && (*iterator1 == *iterator4) && (winner == false)) {
                
                if (*iterator1 == false) {
                cout << endl << "Red Wins!" << endl;
                } else {
                cout << endl << "Blue Wins!" << endl;    
                };

                winner = true;
                }

            iterator1++;
            iterator2++;
            iterator3++;
            iterator4++;
            z++;
    
            }
        }
    }

    return winner;

}


template <typename T>
bool checkDiagonalfromBase(LL<T> b[], const int columns) {

    bool winner = false;
    bool endOfRow = false;
    int  counter = 0;

    for (int i = 0; i <= columns; i++) {
        int inRow = 0;
        bool firstCheck = true;
        int z = 0;
        counter++;

        if ((b[i].getSize() > z) && (b[i+1].getSize() > z) && (b[i+2].getSize() > z) && (b[i+3].getSize() > z) && (counter <= columns - 3)) {
        typename LL<T>::Iterator iterator1 = b[i].begin();
        typename LL<T>::Iterator iterator2 = b[i+1].begin();
        typename LL<T>::Iterator iterator3 = b[i+2].begin();
        typename LL<T>::Iterator iterator4 = b[i+3].begin();
        
            
            while ((b[i].getSize() > z) && (b[i+1].getSize() > z+1) && (b[i+2].getSize() > z+2) && (b[i+3].getSize() > z+3) && (counter <= columns - 3) && (winner == false)){          

                if (firstCheck == true) {
                    iterator2++;
                    iterator3++;
                    iterator3++;
                    iterator4++;
                    iterator4++;
                    iterator4++;
                    firstCheck = false;
                }

                if ((*iterator1 == *iterator2) && (*iterator1 == *iterator3) && (*iterator1 == *iterator4) && (winner == false)) {
                
                if (*iterator1 == false) {
                cout << endl << "Red Wins!" << endl;
                } else {
                cout << endl << "Blue Wins!" << endl;    
                };

                winner = true;
                }

                iterator1++;
                iterator2++;
                iterator3++;
                iterator4++;
                z++;
            }
        }
    }

    return winner;
}

template <typename T>
bool checkDiagonalfromTop(LL<T> b[], const int columns) {

    bool winner = false;
    bool endOfRow = false;
    int  counter = 0;

    for (int i = 0; i <= columns; i++) {
        int inRow = 0;
        bool firstCheck = true;
        int z = 4;
        counter++;

        int board0 = b[i].getSize();
        int board1 = b[i+1].getSize();
        int board2 = b[i+2].getSize();
        int board3 = b[i+3].getSize();

        if ((b[i].getSize() >= z) && (b[i+1].getSize() >= z-1) && (b[i+2].getSize() >= z-2) && (b[i+3].getSize() >= z-3) && (counter <= columns - 3)) {
        typename LL<T>::Iterator iterator1 = b[i].begin();
        typename LL<T>::Iterator iterator2 = b[i+1].begin();
        typename LL<T>::Iterator iterator3 = b[i+2].begin();
        typename LL<T>::Iterator iterator4 = b[i+3].begin();
        
            
            while ((b[i].getSize() >= z) && (b[i+1].getSize() >= z-1) && (b[i+2].getSize() >= z-2) && (b[i+3].getSize() >= z-3) && (counter <= columns - 3) && (winner == false)){          

                if (firstCheck == true) {
                    iterator1++;
                    iterator1++;
                    iterator1++;
                    iterator2++;
                    iterator2++;
                    iterator3++;
                    firstCheck = false;
                }

                if ((*iterator1 == *iterator2) && (*iterator1 == *iterator3) && (*iterator1 == *iterator4) && (winner == false)) {
                
                if (*iterator1 == false) {
                cout << endl << "Red Wins!" << endl;
                } else {
                cout << endl << "Blue Wins!" << endl;    
                };

                winner = true;
                }

                iterator1++;
                iterator2++;
                iterator3++;
                iterator4++;
                z++;
            }
        }
    }

    return winner;




}


int main() {
/*
LL<int> test;

test.headInsert(0);
test.headInsert(1);
test.headInsert(2);
test.headInsert(3);

LL<int> test2 = test;

test2.printLL();*/





    const int columns = 7;
    int pieces = 0;
    bool gameOver = false;

    LL<bool> board[columns];

    printBoard(board, columns);
    while (gameOver != true) {
    
    cout << endl << "Red Player Select a row: ";
    redPlayer(board, columns, pieces);
    printBoard(board, columns);
    gameOver = checkForWinner(board, columns, pieces);

    if (gameOver != true) {
    cout << endl << "Blue Player Select a row: ";
    bluePlayer(board, columns, pieces);
    printBoard(board, columns);
    gameOver = checkForWinner(board, columns, pieces);
    }
    }


return 0;
    }
