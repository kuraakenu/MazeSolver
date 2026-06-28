#include <iostream>
using namespace std;

const int ROW = 4;
const int COL = 4;

// Matriks maze
int maze[ROW][COL] =
{
    {1,0,0,0},
    {1,1,0,1},
    {0,1,0,0},
    {1,1,1,1}
};

// Menyimpan jalur solusi
int solution[ROW][COL] = {0};

// Mengecek apakah posisi valid
bool isSafe(int x, int y)
{
    return (x >= 0 &&
            x < ROW &&
            y >= 0 &&
            y < COL &&
            maze[x][y] == 1 &&
            solution[x][y] == 0);
}

// Fungsi Backtracking
bool solveMaze(int x, int y)
{
    // Jika sampai tujuan
    if (x == ROW - 1 && y == COL - 1 && maze[x][y] == 1)
    {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(x, y))
    {
        // Tandai jalur
        solution[x][y] = 1;

        // Bawah
        if (solveMaze(x + 1, y))
            return true;

        // Kanan
        if (solveMaze(x, y + 1))
            return true;

        // Atas
        if (solveMaze(x - 1, y))
            return true;

        // Kiri
        if (solveMaze(x, y - 1))
            return true;

        // Backtrack
        solution[x][y] = 0;
    }

    return false;
}

// Menampilkan matriks solusi
void printSolution()
{
    cout << "\nJalur yang ditemukan:\n\n";

    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "=== Maze Solver Menggunakan Backtracking ===\n\n";

    cout << "Maze:\n\n";

    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }

    cout << endl;

    if(solveMaze(0,0))
    {
        printSolution();
    }
    else
    {
        cout<<"Tidak ditemukan jalur menuju tujuan.";
    }

    return 0;
}