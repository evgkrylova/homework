package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TicTacToeTest {

    @Test
    void verticalHasWinnerTest() {
        TicTacToe game = new TicTacToe();
        game.table[0] = "X";
        game.table[3] = "X";
        game.table[6] = "X";
        assertEquals("X", game.hasWinner(6));
    }

    @Test
    void drawHasWinnerTest() {
        TicTacToe game = new TicTacToe();
        game.table[0] = "O";
        game.table[3] = "X";
        game.table[6] = "O";
        game.table[1] = "X";
        game.table[4] = "X";
        game.table[7] = "O";
        game.table[2] = "O";
        game.table[5] = "O";
        game.table[8] = "X";
        assertEquals(null, game.hasWinner(8));
    }

    @Test
    void processHasWinnerTest() {
        TicTacToe game = new TicTacToe();
        game.table[0] = "O";
        game.table[3] = "X";
        game.table[6] = "O";
        game.table[4] = "X";
        game.table[7] = "O";
        game.table[8] = "X";
        assertEquals(null, game.hasWinner(4));
    }

    @Test
    void diagonalHasWinnerTest() {
        TicTacToe game = new TicTacToe();
        game.table[0] = "X";
        game.table[4] = "X";
        game.table[8] = "X";
        assertEquals("X", game.hasWinner(4));
    }

    @Test
    void gorizontalHasWinnerTest() {
        TicTacToe game = new TicTacToe();
        game.table[3] = "X";
        game.table[4] = "X";
        game.table[5] = "X";
        assertEquals("X", game.hasWinner(3));
    }
}