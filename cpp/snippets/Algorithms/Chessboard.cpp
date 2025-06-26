//N-Queen Problem in C++ Program
#include <iostream>
using namespace std;

#define QUEEN_SIGN 'Q'
#define BLANK_SIGN '_'

#define N 8


//Set a Board with all Blank
void setBoardBlank(char Board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Board[i][j] = BLANK_SIGN;
		}
	}
}


//Print a Board to screen
void printBoard(char Board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Board[i][j] << "  ";
		}
		cout << endl;
	}
}


//Check Queen if at postion [RowIndex][ColumIndex] is Safe or not
bool isQueenSafeAtPosition(char Board[N][N], int RowIndex, int ColumnIndex)
{
	//Check safe at Row and Column
	for (int i = 0; i < N; i++)
	{
		if (Board[RowIndex][i] == QUEEN_SIGN)
		{
			return false;
		}

		if (Board[i][ColumnIndex] == QUEEN_SIGN)
		{
			return false;
		}
	}

	//Check safe at first diagonal
	for (int i = RowIndex, j = ColumnIndex; (i >= 0) && (j >= 0); i--, j--)
	{
		if (Board[i][j] == QUEEN_SIGN)
		{
			return false;
		}
	}

	for (int i = RowIndex, j = ColumnIndex; (i < N) && (j < N); i++, j++)
	{
		if (Board[i][j] == QUEEN_SIGN)
		{
			return false;
		}
	}

	//Check safe at second diagonal
	for (int i = RowIndex, j = ColumnIndex; (i >= 0) && (j < N); i--, j++)
	{
		if (Board[i][j] == QUEEN_SIGN)
		{
			return false;
		}
	}

	for (int i = RowIndex, j = ColumnIndex; (i < N) && (j >= 0); i++, j--)
	{
		if (Board[i][j] == QUEEN_SIGN)
		{
			return false;
		}
	}

	return true;
}


//Solve N-Queen Problem, Backtracking here!
bool solveNQueenProblem(char Board[N][N], int RowIndex)
{
	if (RowIndex >= N)
	{
		return true;
	}

	for (int j = 0; j < N; j++)
	{
		if (isQueenSafeAtPosition(Board, RowIndex, j) == true)
		{
			Board[RowIndex][j] = QUEEN_SIGN;
			if (solveNQueenProblem(Board, RowIndex + 1) == true)
			{
				return true;
			}
			else
			{
				Board[RowIndex][j] = BLANK_SIGN;
			}
		}
	}

	return false;
}


//Entry Point
int main()
{
	char Board[N][N];

	setBoardBlank(Board);

	if (solveNQueenProblem(Board, 0) == false)
	{
		cout << "Can't find any solution!" << endl;
	}
	else
	{
		printBoard(Board);
	}

	return 0;
}