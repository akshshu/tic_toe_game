#include <iostream>
using namespace std;
int count=0;
int win;
int checkwin(char square[])
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
            && square[4] != '4' && square[5] != '5' && square[6] != '6'
            && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}
void board(char square[])
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}
int main()
{   char y;
    do
    {   int stop=0;
        char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
        int player=1,i,choice;
        char mark;
        while(stop==0)
        {
            int count2=0;
            board(square);
            player=(player%2)?1:2;
            cout<<"Player"<<player<<"Choice ";
            cin>>choice;
            mark=(player==1)?'X':'O';
            for(i=1;i<=9;i++)
            {
                if(choice==i && square[i]==i+48)
                {
                square[i]=mark;
                }
                else
                {
                count2++;
                }
            }
            if(count2==9)
            {
                cout<<"INVALID MOVE....PRESS ENTER AND TRY AGAIN";
                player--;
                cin.ignore();
                cin.get();
            }
            else
            {
                count++;
                win=checkwin(square);
            }
            if(win==1)
            {
                board(square);
                cout<<"***************************PLAYER "<<player<<" WON*************************** "<<endl;
                stop=1;
            }
            else if(win==0)
            {
                board(square);
                cout<<"***************************GAME DRAW***************************"<<endl;
                stop=1;
            }
            else if(win==-1)
                player++;

        }
        cout<<"ENTER Y TO PLAY AGAIN"<<endl;
        cin>>y;
    }
    while(y=='y'||y=='Y');

    return 0;
}
