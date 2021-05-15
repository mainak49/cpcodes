/*
Tic-tac-toe is a game played between two players on a 3×3 grid. In a turn, a player chooses an empty cell and places their symbol on the cell. The players take alternating turns, where the player with the first turn uses the symbol X and the other player uses the symbol O. The game continues until there is a row, column, or diagonal containing three of the same symbol (X or O), and the player with that token is declared the winner. Otherwise if every cell of the grid contains a symbol and nobody won, then the game ends and it is considered a draw.

You are given a tic-tac-toe board A after a certain number of moves, consisting of symbols O, X, and underscore(_). Underscore signifies an empty cell.

Print
1: if the position is reachable, and the game has drawn or one of the players won.
2: if the position is reachable, and the game will continue for at least one more move.
3: if the position is not reachable.

Note:
Starting from an empty board, reachable position means that the grid is possible after a finite number of moves in the game where the players may or may not be playing optimally.
The answer for each testcase should be with respect to the present position and independent of the results in the further successive moves.
Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains 3 lines of input where each line contains a string describing the state of the game in ith row.
Output
For each test case, output in a single line 1, 2 or 3 as described in the problem.

Constraints
1≤T≤39
Aij∈{X,O,_}
Subtasks
Subtask #1 (100 points): Original Constraints

Sample Input
3
XOX
XXO
O_O
XXX
OOO
___
XOX
OX_
XO_

Sample Output
2
3
1
Explanation
Test Case 1: The board is reachable, and although no player can win from this position, still the game continues.

Test Case 2: There can't be multiple winners in the game.

Test Case 3: The first player is clearly a winner with one of the diagonals.*/

#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t,m,n,u,x,o,ans;
    char ar[3][3];
    cin >> t; 
    while(t--)
    {
        m=0;n=0,u=0,x=0,o=0,ans=0;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin >> ar[i][j];
                if(ar[i][j]=='_')
                    u++;
                if(ar[i][j]=='X')
                    x++;
                if(ar[i][j]=='O')
                    o++;
            }
        }
        if(ar[0][0]=='X' && ar[0][1]=='X' && ar[0][2]=='X')
            m=1;
        if(ar[1][0]=='X' && ar[1][1]=='X' && ar[1][2]=='X')
            m=1;   
        if(ar[2][0]=='X' && ar[2][1]=='X' && ar[2][2]=='X')
            m=1;
        if(ar[0][0]=='X' && ar[1][0]=='X' && ar[2][0]=='X')
            m=1;
        if(ar[0][1]=='X' && ar[1][1]=='X' && ar[2][1]=='X')
            m=1;
        if(ar[0][2]=='X' && ar[1][2]=='X' && ar[2][2]=='X')
            m=1;
        if(ar[0][0]=='X' && ar[1][1]=='X' && ar[2][2]=='X')
            m=1;
        if(ar[2][0]=='X' && ar[1][1]=='X' && ar[0][2]=='X')
            m=1;

        if(ar[0][0]=='O' && ar[0][1]=='O' && ar[0][2]=='O')
            n=1;
        if(ar[1][0]=='O' && ar[1][1]=='O' && ar[1][2]=='O')
            n=1;   
        if(ar[2][0]=='O' && ar[2][1]=='O' && ar[2][2]=='O')
            n=1;
        if(ar[0][0]=='O' && ar[1][0]=='O' && ar[2][0]=='O')
            n=1;
        if(ar[0][1]=='O' && ar[1][1]=='O' && ar[2][1]=='O')
            n=1;
        if(ar[0][2]=='O' && ar[1][2]=='O' && ar[2][2]=='O')
            n=1;
        if(ar[0][0]=='O' && ar[1][1]=='O' && ar[2][2]=='O')
            n=1;
        if(ar[2][0]=='O' && ar[1][1]=='O' && ar[0][2]=='O')
            n=1;

        if((m==1 && n==1) || (x-o)<0 || (x-o)>2  )
            ans=3;
        else if(m==1 && n==0 && x>o)
            ans=1;
        else if(m==0 && n==1 && x==o)
            ans=1;
        else if(m==0 && n==0 && u==0)
            ans=1;
        else if(m==0 && n==0 && u>0)
            ans=2;
        else
            ans=3;
        cout << ans << endl;
    }
}
