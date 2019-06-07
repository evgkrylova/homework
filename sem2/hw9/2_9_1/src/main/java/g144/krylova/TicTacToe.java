package g144.krylova;

/**
 * Class containing realization of the tic-tac-toe game process.
 */
public class TicTacToe {
    private String nextSymbol = "X";
    private final int SIZE = 3;
    private String[] table = new String[SIZE * SIZE];
    public enum ProcessState {X, O, DRAW, PLAYING, UNKNOWN}

    public TicTacToe() {
        for (int i = 0; i < SIZE * SIZE; i++) {
            this.table[i] = "";
        }
    }

    /**
     * Method returning the size of the game field.
     * @return how many cells there are by te side of the field.
     */
    public int getSize() {
        return SIZE;
    }

    /**
     * Method checking if there is already a winner.
     * @return winner if he exists and null otherwise.
     */
    public ProcessState hasWinner() {
        ProcessState diagonalWinner = hasDiagonal();
        if (diagonalWinner != ProcessState.UNKNOWN) {
            return diagonalWinner;
        }

        ProcessState verticalWinner = hasVertical();
        if (verticalWinner != ProcessState.UNKNOWN) {
            return verticalWinner;
        }

        ProcessState gorizontalWinner = hasGorizontal();
        if (gorizontalWinner != ProcessState.UNKNOWN) {
            return gorizontalWinner;
        }

        boolean isEnded = true;
        for (int i = 0; i < SIZE * SIZE; i++) {
            if (table[i].equals("")) {
                isEnded = false;
            }
        }
        if (isEnded) {
            return ProcessState.DRAW;
        }
        return ProcessState.PLAYING;
    }

    /**
     * Method checking if there is the diagonal of 'X'-es or 'O'-es.
     * @return name of winner or null if there is no one.
     */
    private ProcessState hasDiagonal() {
        String centreSymbol = this.table[4];
        if (centreSymbol == null || centreSymbol.equals("")) {
            return ProcessState.UNKNOWN;
        }
        if ((centreSymbol.equals(table[8]) && centreSymbol.equals(table[0])) || (centreSymbol.equals(table[2]) && centreSymbol.equals(table[6]))) {
            if (centreSymbol.equals("X")) {
                return ProcessState.X;
            }
            return ProcessState.O;
        }
        return ProcessState.UNKNOWN;
    }

    /**
     * Method checking if there is the column of 'X'-es or 'O'-es.
     * @return name of winner or null if there is no one.
     */
    private ProcessState hasVertical() {
        for (int column = 0; column < SIZE; column++) {
            if (!table[column].equals("") &&  !table[column + SIZE].equals("") &&  !table[column + SIZE * 2].equals("")) {
                if (table[column].equals(table[column + SIZE]) && table[column].equals(table[column + SIZE * 2])) {
                    if (table[column].equals("X")) {
                        return ProcessState.X;
                    }
                    return ProcessState.O;
                }
            }
        }
        return ProcessState.UNKNOWN;
    }

    /**
     * Method checking if there is the row of 'X'-es or 'O'-es.
     * @return name of winner or null if there is no one.
     */
    private ProcessState hasGorizontal() {
        for (int row = 0; row < SIZE; row++) {
            if (!table[row * SIZE].equals("") &&  !table[row * SIZE + 1].equals("") &&  !table[row * SIZE + 2].equals("")) {
                if (table[row * SIZE].equals(table[row * SIZE + 1]) && table[row * SIZE].equals(table[row * SIZE + 2])) {
                    if (table[row * SIZE].equals("X")) {
                        return ProcessState.X;
                    }
                    return ProcessState.O;
                }
            }
        }
        return ProcessState.UNKNOWN;
    }

    /**
     * Method realizing the reaction to the move.
     * @param row of the move.
     * @param column of the move.
     * @return true if the move was successfully made and false otherwise.
     */
    public boolean makeMove(int row, int column) {
        if (nextSymbol.equals("X")) {
            nextSymbol = "O";
        } else {
            nextSymbol = "X";
        }
        table[row * SIZE + column] = nextSymbol;
        return true;
    }

    public String getNextSymbol() {
        return this.nextSymbol;
    }
}