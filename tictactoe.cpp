#include<iostream>
using namespace std;
char board[3][3];
int t=1;
class tictactoe
{
	char p1[10];
	char p2[10];
	
	public:
		void board_display();
		void game_rules();
		void accept_player_details();
		void print();
		int diagnol();
		int check(int,int);
		void turns();
};
void tictactoe:: board_display()
    {
        cout<<"  1 2 3"<<endl;
        cout<<"1 _ _ _"<<endl;
        cout<<"2 _ _ _"<<endl;
        cout<<"3 _ _ _"<<endl;
        cout<<"\n The indexes displayed along the rows and columns will be the reference\n";
    }
void tictactoe::game_rules()
    {
        cout<<"RULES"<<endl;
        cout<<"1. The location of insertion of their X/O should be based on their indexes mentioned."<<endl;
        cout<<"2. Player 1 gets to make their first move by default."<<endl;
    }
void tictactoe::accept_player_details ()
{
	game_rules();
        cout<<"Enter name of Player1\n";
        cin>>p1;
        cout<<"\nEnter name of Player2\n";
        cin>>p2;
        cout<<"Player 1 (X) : "<<p1<<"\n";
        cout<<"Player 2 (O) : "<<p2<<"\n";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                board[i][j]='_';
            }
        }
        board_display();
}
void tictactoe::print()
{
    	cout<<"\t\t\t\t\t";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<"\n\t\t\t\t\t";
        }
}
int tictactoe::diagnol()
{
        if((board[0][0]==board[1][1] && board[1][1]==board[2][2]) || (board[0][2]==board[1][1] && board[1][1]==board[2][0]))
        {
            return 1;
        }
        else 
        {
            return 0;
        }
}
int tictactoe::check(int a,int b)
{
        if((board[a-1][0]==board[a-1][1] && board[a-1][1]==board[a-1][2]) || (board[0][b-1]==board[1][b-1] && board[1][b-1]==board[2][b-1]) || diagnol() )
        {
            return 1;
        }
        else
        return 0;
}
void tictactoe::turns()
    {
        
        int win=0;
        while(t<=9 && win!=1)
        {
            if(t%2==1)
            {
                 cout<<"\n"<<p1<<"'s turn";
            }
            else
            {
                 cout<<"\n"<<p2<<"'s turn";
            }
            int x,y;
                int ch=1;
                
                while(ch==1)
                {
                   
                     cin>>x>>y;
                    if(x<=0 || x>=4 || y<=0 || y>=4 || board[x-1][y-1]!='_')
                    {
                        cout<<"\nInvalid entry of reference positions please try again\n";
                        
                    }
                    else
                    {
                        ch=0;
                        if(t%2==1)
                        {
                            board[x-1][y-1]='X';
                        }
                        else
                        {
                            board[x-1][y-1]='O';
                        }
                        print();
                    
                    }
                }
                if(t>=5)
                {
                    win=check(x,y);
                    if(win==1)
                    {
                        
                        if(t%2==1)
                        {
                            cout<<p1<<" is the WINNER\n";
                        }
                        else
                        {
                            
                            cout<<p2<<" is the WINNER\n";
                        }
                    }
                }
                
                t++;
        }
        if(t==10 && win==0) 
        {
            cout<<"match was a DRAW";
        }
}
main()
{
	tictactoe t;
	t.accept_player_details();
	t.turns();
}

