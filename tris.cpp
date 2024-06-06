#include <iostream>

using namespace std;

/*Variabili globali: 
Queste variabili saranno visibili in tutte le funzioni,in genere si sconsiglia questo approccio
nei programmi più complessi.
*/
const int SIZE = 3; //Quantità dei caselli per ogni riga
char board[SIZE][SIZE]; //Dichiara la griglia
char currentPlayer = 'X'; // Il giocatore dove ha il turno,il primo turno in questo caso spetta sempre a X

void initializeBoard() 
{
    for (int i = 0; i < SIZE; ++i) 
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            board[i][j] = ' '; // Setta tutte le caselle vuote.
        }
    }
}

//Stampa a schermo la griglia
void printBoard() {
    for (int i = 0; i < SIZE; ++i) 
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--+---+--" << endl;
    }
}

bool isWinner() 
{
    // Controllo righe e colonne
    for (int i = 0; i < SIZE; ++i) 
    {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) 
        {
            return true;
        }
    }
    // Controllo diagonali
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) 
    {
        return true;
    }
    return false;
}

bool isBoardFull() 
{
    for (int i = 0; i < SIZE; ++i) 
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            if (board[i][j] == ' ') 
            {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() 
{
    if (currentPlayer == 'X') 
    {
        currentPlayer = 'O';
    } 
    else 
    {
        currentPlayer = 'X';
    }

}

void makeMove() 
{
    int row, col;
    while (true) 
    {
        cout << "Giocatore " << currentPlayer << ", inserisci la riga e la colonna (0, 1, 2): ";
        cin >> row >> col;
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') 
        {
            board[row][col] = currentPlayer; //Scrivi la casella che il giocatore ha selezionato
            break;
        } 
        else 
        {
            cout << "Mossa non valida. Riprova." << endl;
        }
    }
}

int main() 
{
    initializeBoard();
    while (true) 
    {
        printBoard();
        makeMove();
        if (isWinner()) 
        {
            printBoard();
            cout << "Giocatore " << currentPlayer << " vince!" << endl;
            break;
        }
        if (isBoardFull()) 
        {
            printBoard();
            cout << "Pareggio!" << endl;
            break;
        }
        switchPlayer();
    }
    return 0;
}
