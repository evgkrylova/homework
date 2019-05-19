package g144.krylova;

import javafx.scene.control.Button;
import java.util.ArrayList;

/**
 * Class containing states of the game.
 */
public class TicTacToe {
    private String nextSymbol = "X";
    private final int SIZE = 3;
    private String[] table = new String[SIZE * SIZE];

    TicTacToe() {
        for (int i = 0; i < SIZE * SIZE; i++) {
            this.table[i] = "";
        }
    }

    /**
     * Method getting next symbol.
     * @return symbol to print.
     */
    public String getNextSymbol() {
        return nextSymbol;
    }

    /**
     * Method updating next symbol.
     */
    public void rewriteNextSymbol() {
        if (nextSymbol.equals("X")) {
            this.nextSymbol = "O";
            return;
        }
        this.nextSymbol = "X";
    }

    /**
     * Method setting new symbol.
     * @param index is index of button.
     * @param newSymbol is character to set.
     */
    public void setState(int index, String newSymbol) {
        this.table[index] = newSymbol;
    }

    /**
     * Method checking if there is already a winner.
     * @param index is the index of last button.
     * @return winner if he exists and null otherwise.
     */
    public String hasWinner(int index) {
        String current = this.table[index];
        boolean isVertical = true;
        boolean isHorizontal = true;
        for (int i = 0; i < table.length; i++) {
            isHorizontal = isHorizontal && !(!current.equals(table[i]) && index / SIZE == i / SIZE);
            isVertical = isVertical && !(!current.equals(table[i]) && index % SIZE == i % SIZE);
        }
        if (hasDiagonal() || isVertical || isHorizontal) {
            return current;
        }
        return null;
    }

    /**
     * Method checking if there is the diagonal of 'X'-es or 'O'-es.
     * @return true if there is such diagonal and false otherwise.
     */
    private boolean hasDiagonal() {
        String centreSymbol = this.table[4];
        if (centreSymbol == null || centreSymbol.equals("")) {
            return false;
        }
        return (centreSymbol.equals(table[8]) && centreSymbol.equals(table[0])) || (centreSymbol.equals(table[2]) && centreSymbol.equals(table[6]));
    }

    /**
     * Method clearing gaming field.
     * @param buttons is list of gaming field buttons.
     */
    public void clear(ArrayList<Button> buttons) {
        nextSymbol = "X";
        for (Button button : buttons) {
            button.setText("");
        }
        for (int i = 0; i < SIZE * SIZE; i++) {
            this.table[i] = null;
        }
    }
}
