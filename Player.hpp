class Player
{
    string name;
    public:
    Player(string _name) : name(_name){}
    void askToPlay(void)
    {
        // ask the player to make a move
        cout << this -> name << ", its your turn. Enter a row (1 - 3) and a column (1 - 3) : ";
    }
    void shoutout(void)
    {
        // congratulate the winner
        cout << "Congratulations " << this -> name << ". You Won!!\n";
    }
    void condolences(void)
    {
        // condolence the loser
        cout << "Better luck next time, " << this -> name << ".\n";
    }
    void reprimand(void)
    {
        // Direct the player to make a valid move
        cout << "Invalid Move " << this -> name << ". Make a move on an unmarked cell with row number between 1 to 3 and column number between 1 to 3.\n";
    }
    ~Player() {}
};