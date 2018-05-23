#include <iostream>

#include<iostream>
using namespace std;
int count;
char board[9] = {'-','-','-','-','-','-','-','-','-'};

int Finish()
{
    for(int i =0;i<9;i++)
    {
        if(board[i]!='X')
        {
            if(board[i]!='O')
               {
                 return 0;
               }
        }
    }
return 1;
}

int user_won()
{
    for(int i=0;i<9;i+=3)
    {
        if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='O'))
            return 1;
    }
    for(int i=0;i<3;i++)
    {
        if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]=='O'))
            return 1;
    }
    if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]=='O'))
    {
        return 1;
    }
    if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]=='O'))
    {
        return 1;
    }
    return 0;
}

int computer_won()
{
    for(int i=0;i<9;i+=3)
    {
        if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='X'))
            return 1;
    }
    for(int i=0;i<3;i++)
    {
        if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]=='X'))
            return 1;
    }
    if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]=='X'))
    {
        return 1;
    }
    if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]=='X'))
    {
        return 1;
    }
    return 0;
}

void draw_board()
{
    cout<<endl;
    cout<<board[0]<<"  |  "<<board[1]<<" |  "<<board[2]<<endl;
    cout<<"---+----+---"<<endl;
    cout<<board[3]<<"  |  "<<board[4]<<" |  "<<board[5]<<endl;
    cout<<"---+----+---"<<endl;
    cout<<board[6]<<"  |  "<<board[7]<<" |  "<<board[8]<<endl;
}

int alphabeta(bool flag)
{

    int alpha=-1000,beta=1000;
    int i,j,value = 1;
    if(computer_won() == 1)
        {return -10;}
    else if(user_won() == 1)
        {return 10;}
    else if(Finish()== 1)
        {return 0;}
    int score[9] = {1,1,1,1,1,1,1,1,1};

        for(i=0;i<9;i++)
            {
                 if(board[i] == '-')
                {
                    if(beta>alpha)
                  {
                      if(flag == true)
                   {
                     board[i] = 'X';
                     value = alphabeta(false);
                   }
                    else
                    {
                      board[i] = 'O';
                      value = alphabeta(true);
                    }
                  board[i] = '-';
                  score[i] = value;
                 }
               }
            }

        if(flag == true)
        {
                 alpha = -1000;
                 for(j=0;j<9;j++)
                {
                    if(score[j] > alpha && score[j] != 1)
                    {
                        alpha = score[j];
                        count = j;
                    }
                }
                return alpha;
        }
        if(flag == false)
        {
                beta = 1000;
                for(j=0;j<9;j++)
                {
                    if(score[j] < beta && score[j] != 1)
                    {
                        beta = score[j];
                        count = j;
                    }
                }
            return beta;
        }
}

int main()
{
   int move,choice;

   cout<<endl<<"You=0      computer=X";
   cout<<endl<<"Choice : 1=Player first"<<endl<<"         2= Computer first:";
   cin>>choice;
   if(choice == 1)
   {
       draw_board();
      up:cout<<endl<<"Enter the move:";
         cin>>move;
         if(board[move-1]=='-')
         {
           board[move-1] = 'O';
           draw_board();
         }
         else
         {
             cout<<endl<<"Invalid Move......Try different move";
             goto up;
         }
   }

    while(true)
    {

        cout<<endl<<"opposite MOVE....";
        alphabeta(true);//oposite movve or computer move
        board[count] = 'X';
        draw_board();
        if(computer_won()==1)
        {
            cout<<endl<<"opposite WON.....";
            break;
        }
        if(Finish()==1)
        {
            cout<<endl<<"Draw....";
            break;
        }
go:  cout<<endl<<"Enter the move:";
        cin>>move;
        if(board[move-1]=='-')
         {
           board[move-1] = 'O';
           draw_board();
         }
         else
         {
             cout<<endl<<"Invalid Move......Try different move";
             goto go;
         }
         if(user_won()==1)
         {
             cout<<endl<<"You Won......";
             break;
         }
         if(Finish() == 1)
        {
            cout<<endl<<"Draw....";
            break;
        }
    }

}
