class Board {
  private:
    char grid[10][10];
  public:
    Board();
    void drawGrid(int showShips);
    void playerGuess(char y, char x);
    void placeShip(char y, char x, char h, int length);
    int gameOver();
};
