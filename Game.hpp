class Game
{
    Board currGame;
    public:
    Game(void) {}
    void play(void)
    {
        string name1, name2;
        cout << "Enter name of player 1 : ";
        cin >> name1;
        cout << "Enter name of player 2 : ";
        cin >> name2;
        cout << '\n';
        Player player1(name1), player2(name2); 
        currGame.show();
        system("pause");
        int row, col;
        for (int turn = 0; turn < 9; turn++)
        {
            system("cls");
            if (!(turn & 1))
            {
                player1.askToPlay();
                cin >> row >> col;
                --row;
                --col;
                try
                {
                    currGame.play(1, row, col);
                    currGame.show();
                    if (turn >= 4 && currGame.isWinner(1))
                    {
                        player1.shoutout();
                        player2.condolences();
                        return;
                    }
                }
                catch(int errorNo)
                {
                    cout << "Error " << errorNo << " .\n";
                    player1.reprimand();
                    turn--;
                }          
            }
            else
            {
                player2.askToPlay();
                cin >> row >> col;
                --row;
                --col;
                try
                {
                    currGame.play(2, row, col);
                    currGame.show();
                    if (turn >= 5 && currGame.isWinner(2))
                    {
                        player2.shoutout();
                        player1.condolences();
                        return;
                    }
                }
                catch(int errorNo)
                {
                    cout << "Error " << errorNo << " .\n";
                    player2.reprimand();
                    turn--;
                }
            }
            system("pause");
        }
        cout << "Nobody Wins. Its a draw.\n";
        return;
    }
    ~Game() {}
};