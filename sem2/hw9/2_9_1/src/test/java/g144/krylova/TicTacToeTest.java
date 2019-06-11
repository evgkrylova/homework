package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TicTacToeTest {

    @Test
    void verticalHasWinnerTest() {
        TicTacToe game = new TicTacToe();
        game.field[0] = 'X';
        game.field[3] = 'X';
        game.field[6] = 'X';
        assertTrue(game.hasWinner());
        assertTrue(game.hasVertical());
    }

    @Test
    void diagonalHasWinnerTest() {
        TicTacToe game = new TicTacToe();
        game.field[0] = 'X';
        game.field[4] = 'X';
        game.field[8] = 'X';
        assertTrue(game.hasWinner());
        assertTrue(game.hasDiagonal());
    }

    @Test
    void gorizontalHasWinnerTest() {
        TicTacToe game = new TicTacToe();
        game.field[3] = 'X';
        game.field[4] = 'X';
        game.field[5] = 'X';
        assertTrue(game.hasWinner());
        assertTrue(game.hasGorizontal());
    }

    @Test
    void drawHasWinnerTest() {
        TicTacToe game = new TicTacToe();
        game.field[0] = 'O';
        game.field[3] = 'X';
        game.field[6] = 'O';
        game.field[1] = 'X';
        game.field[4] = 'X';
        game.field[7] = 'O';
        game.field[2] = 'O';
        game.field[5] = 'O';
        game.field[8] = 'X';
        assertFalse(game.hasWinner());
    }

    @Test
    void processHasWinnerTest() {
        TicTacToe game = new TicTacToe();
        game.field[0] = 'O';
        game.field[3] = 'X';
        game.field[6] = 'O';
        game.field[4] = 'X';
        game.field[7] = 'O';
        game.field[8] = 'X';
        assertFalse(game.hasWinner());
    }
}