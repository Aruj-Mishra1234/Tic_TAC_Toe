class Board
{
    char **board = nullptr;
    public:
    Board(void) : board(new char*[3])
    {
        // allocte space for all 3 rows with 3 cells in each
        // also initialise them with blank spaces
        for (int row = 0; row < 3; row++)
        {
            board[row] = new char[3];
            for (int col = 0; col < 3; col++) board[row][col] = ' ';
        }
    }
    void show(void)
    {
        cout << ' ';
        for (int col = 0; col < 3; col++) cout << " -  ";
        cout << '\n';
        for (int row = 0; row < 3; row++)
        {
            cout << "| ";
            for (int col = 0; col < 3; col++) cout << board[row][col] << " | ";
            cout << '\n' << ' ';
            for (int col = 0; col < 3; col++) cout << " -  ";
            cout << '\n';
        }
        cout << '\n';
    }
    void play(int player, int row, int col)
    {
        if (row < 0 || col < 0 || row > 2 || col > 2 || board[row][col] != ' ') throw 211;
        if (player == 1) board[row][col] = 'X';
        else board[row][col] = 'O';
    }
    bool isWinner(int player)
    {
        char winChar = (player == 1) ? 'X' : 'O';
        bool check;
        // check for rows
        for (int row = 0; row < 3; row++)
        {
            check = true;
            for (int col = 0; col < 3; col++)
            {
                if (board[row][col] != winChar)
                {
                    check = false;
                    break;
                }
            }
            if (check) return true;
        }
        // check for columns
        for (int col = 0; col < 3; col++)
        {
            check = true;
            for (int row = 0; row < 3; row++)
            {
                if (board[row][col] != winChar)
                {
                    check = false;
                    break;
                }
            }
            if (check) return true;
        }
        // check for principal diagonal
        check = true;
        if (board[0][0] != winChar || board[1][1] != winChar || board[2][2] != winChar) check = false;
        if (check) return true;
        // check for secondary diagonal
        check = true;
        if (board[0][2] != winChar || board[1][1] != winChar || board[2][0] != winChar) check = false;
        if (check) return true;
        return false;
    }
    ~Board()
    {
        // free each row of board
        for (int row = 0; row < 3; row++) delete[] board[row];
        // free space allocated to board
        delete[] board;
        board = nullptr;
    }
};