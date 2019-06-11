package g144.krylova;

/**
 * Class containing realization of the tic-tac-toe game methods.
 */
public class TicTacToe {
    private final int SIZE = 9;
    private final int SIDE = 3;
    private char[] field = new char[SIZE];
    private char nextSymbol = 'O';
    private int emptyCells = SIZE;
    public enum ProcessState {WIN, DRAW, PLAYING, UNKNOWN}

    /**
     * Method changing the next symbol.
     */
    public void changeCurrentPlayer() {
        if (nextSymbol == 'X') {
            nextSymbol = 'O';
        }
        else {
            nextSymbol = 'X';
        }
    }

    /**
     * Method realizing reaction to the move.
     * @param index is the index of pressed button.
     */
    public boolean makeMove(int index) {
        if (index < 0 || index > 8 || field[index] == 'X' || field[index] == 'O') {
            return false;
        }

        field[index] = nextSymbol;
        emptyCells--;
        changeCurrentPlayer();
        return true;
    }

    /**
     * Method checking if there is already a winner.
     * @return the current game status.
     */
    public ProcessState getProcessState() {
        if (hasWinner()) {
            return ProcessState.WIN;
        }

        if (isFieldFull()) {
            return ProcessState.DRAW;
        }

        return ProcessState.PLAYING;
    }

    /**
     * Method checking if the field of the game is full.
     * @return true if it is and false otherwise.
     */
    public boolean isFieldFull() {
        return emptyCells == 0;
    }

    /**
     * Method checking if there is already a winner.
     * @return winner if he exists and null otherwise.
     */
    public boolean hasWinner() {
        return hasDiagonal() || hasVertical() || hasGorizontal();
    }

    /**
     * Method checking if there is the diagonal of 'X'-es or 'O'-es.
     * @return true if the diagonal exists and false otherwise.
     */
    private boolean hasDiagonal() {
        char centreSymbol = this.field[4];
        if (centreSymbol == '\0') {
            return false;
        }
        if ((centreSymbol == field[8] && centreSymbol == field[0]) || (centreSymbol == field[2] && centreSymbol == field[6])) {
            return true;
        }
        return false;
    }

    /**
     * Method checking if there is the column of 'X'-es or 'O'-es.
     * @return true if the vertical exists and false otherwise.
     */
    private boolean hasVertical() {
        for (int column = 0; column < SIZE / SIDE; column++) {
            if (field[column] != '\0' &&  field[column + SIDE] != '\0' &&  field[column + SIDE * 2] != '\0') {
                if (field[column] == field[column + SIDE] && field[column] == field[column + SIDE * 2]) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * Method checking if there is the row of 'X'-es or 'O'-es.
     * @return true if the gorizontal exists and false otherwise.
     */
    private boolean hasGorizontal() {
        for (int row = 0; row < SIZE / SIDE; row++) {
            if (field[row * SIDE] != '\0' && field[row * SIDE + 1] != '\0' && field[row * SIDE + 2] != '\0') {
                if (field[row * SIDE] == field[row * SIDE + 1] && field[row * SIDE] == field[row * SIDE + 2]) {
                    return true;
                }
            }
        }
        return false;
    }

    public int getSize() {
        return SIZE;
    }

    public char getNextSymbol() {
        return nextSymbol;
    }
}