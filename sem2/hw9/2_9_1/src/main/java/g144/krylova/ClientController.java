package g144.krylova;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.net.Socket;

/**
 * Controller class for server half of the tic-tac-tor game (used sockets).
 */
public class ClientController {
    @FXML
    private Button[] buttons;

    @FXML
    private Button start;

    @FXML
    private Label status;

    @FXML
    private GridPane pane;

    private InputStream opponentStream;
    private PrintStream hostStream;
    private TicTacToe game;
    private static final int port = 10001;
    private int size;
    private Socket client;
    private boolean isNewGame = false;
    private boolean doClientExit = true;

    public void initialize() throws IOException{
        game = new TicTacToe();
        size = game.getSize();
        buttons = new Button[size * size];
        for (int i = 0; i < size * size; i++) {
            buttons[i] = (Button) pane.getChildren().get(i);
        }

        Alert message = new Alert(Alert.AlertType.INFORMATION);
        message.setContentText("Press OK to connect.");
        message.showAndWait();
        while (true) {
            client = new Socket("localhost", port);
            opponentStream = client.getInputStream();
            hostStream = new PrintStream(client.getOutputStream());
            break;
        }
        setDisable(true);
        status.setText("It is opponent's move.");
        waitForOpponentMove();
    }


    /**
     * Method starting new game.
     */
    @FXML
    private void newGame() {
        if (!isNewGame) {
            hostStream.print(9);
            hostStream.flush();
        }
        game = new TicTacToe();
        for (int i = 0; i < size * size; i++) {
            buttons[i].setText("");
        }

        status.setText("It is opponent's move.");
        isNewGame = false;
        setDisable(true);
        waitForOpponentMove();
    }

    /**
     * Method realizing reaction to the move.
     * @param event is event with pressed button.
     */
    @FXML
    private void pressButton(ActionEvent event) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                Button currentButton = buttons[i * size + j];
                if (event.getSource().equals(currentButton)) {
                    if (game.makeMove(i, j)) {
                        currentButton.textProperty().setValue(game.getNextSymbol());
                        hostStream.print(i * size + j);
                        hostStream.flush();
                        status.setText("It is opponent's move.");
                        setDisable(true);
                        if (game.hasWinner() == TicTacToe.ProcessState.PLAYING) {
                            waitForOpponentMove();
                        }
                        isEnded();
                    }
                }
            }
        }
    }

    /**
     * Method realizing active waiting of opponent turn (used threads).
     */
    private void waitForOpponentMove() {
        new Thread(() -> {
            int indexOfButton = 'e';
            while (true) {
                try {
                    if (opponentStream.available() == 0) {
                        try {
                            indexOfButton = opponentStream.read() - '0';
                        } catch(java.net.SocketException e) {
                            doClientExit = false;
                        }
                        break;
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            int finalIndex = indexOfButton;
            Platform.runLater(() -> reactToOpponentMove(finalIndex));
        }).start();
    }

    /**
     * Method realizing reacting to the opponent move.
     * @param indexOfButton is index of pressed earlier button.
     */
    private void reactToOpponentMove(int indexOfButton) {
        if (indexOfButton == 9) {
            isNewGame = true;
            newGame();
        } else if (indexOfButton >= 0 && indexOfButton < 9) {
            game.makeMove(indexOfButton / 3, indexOfButton % 3);
            buttons[indexOfButton].textProperty().setValue(game.getNextSymbol());
            status.setText("Make your move.");
            setDisable(false);
            isEnded();
        } else {
            Alert exitMessage = new Alert(Alert.AlertType.INFORMATION);
            exitMessage.setTitle("Game over.");
            exitMessage.setContentText("Game was interrupted.");
            exitMessage.showAndWait();
            doClientExit = false;
            Platform.exit();
        }
    }

    /**
     * Method checking if the game was ended.
     * Do nothing if the game is in the process.
     */
    private void isEnded() {
        if (game.hasWinner() == TicTacToe.ProcessState.DRAW) {
            endGame("There is no winner.");
        } else if (game.hasWinner() == TicTacToe.ProcessState.X) {
            endGame("X-player has won.");
        } else if (game.hasWinner() == TicTacToe.ProcessState.O) {
            endGame("O-player has won.");
        }
    }

    /**
     * Method reacting to the end of the game.
     */
    private void endGame(String string) {
        isNewGame = true;
        Alert finishMessage = new Alert(Alert.AlertType.INFORMATION);
        finishMessage.setTitle("Game over.");
        finishMessage.setHeaderText("Game over.");
        finishMessage.setContentText(string);
        finishMessage.showAndWait();
        newGame();
    }

    /**
     * Method checking if the exit was done.
     * @return true if the exit was done and false otherwise.
     */
    public boolean isExited() {
        return this.doClientExit;
    }

    /**
     * Method sending message about an exit to the opponent.
     */
    public void sendExitMessage() {
        hostStream.print('e');
        hostStream.flush();
    }

    /**
     * Method closing the connection.
     */
    public void closeConnection() {
        try {
            client.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Method making all buttons disabled or available.
     * @param argument is true if buttons should be blocked and false otherwise.
     */
    private void setDisable(boolean argument) {
        for (int i = 0; i < size * size; i++) {
            pane.getChildren().get(i).setDisable(argument);
        }
        start.setDisable(argument);
    }
}
