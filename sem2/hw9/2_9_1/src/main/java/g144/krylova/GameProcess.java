package g144.krylova;

import java.io.*;
import javafx.scene.control.*;
import java.net.*;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.scene.layout.GridPane;

/**
 * Class containing realization of the tic-tac-toe algorithm methods.
 */
public class GameProcess {
    private int size;
    private Button start;
    private Label infoStatus;
    private GridPane pane;
    private Button[] buttons;
    private TicTacToe field;

    private boolean newGameStarted = false;
    private boolean isInProcess = true;

    private String user;
    private InputStream inStream;
    private PrintStream outStream;

    public GameProcess(GridPane parent, Button start, Label status, String user) {
        pane = parent;
        this.start = start;
        infoStatus = status;
        this.field = new TicTacToe();
        size = field.getSize();
        this.user = user;

        buttons = new Button[size];
        for (int i = 0; i < size; i++) {
            buttons[i] = (Button) parent.getChildren().get(i);
        }
    }

    /**
     * Method starting the new game.
     */
    public void startNewGame() {
        if (!newGameStarted) {
            outStream.print(size);
            outStream.flush();
        }

        field = new TicTacToe();
        for (int i = 0; i < size; i++) {
            buttons[i].setText("");
        }
        newGameStarted = false;

        if (user.equals("client")) {
            infoStatus.setText("It's the opponent's move.");
            setDisable(true);
            waitOpponentMove();
        } else {
            infoStatus.setText("Make your move.");
            setDisable(false);
        }
    }

    /**
     * Method realizing reaction to the move.
     * @param event is event with pressed button.
     */
    public void pressCellButton(ActionEvent event) {
        for (int i = 0; i < size; i++) {
            if (buttons[i].equals(event.getSource())) {
                if (field.makeMove(i)) {
                    field.makeMove(i);
                    buttons[i].setDisable(true);
                    buttons[i].setText(String.valueOf(field.getNextSymbol()));
                    outStream.print(i);
                    outStream.flush();

                    if (user.equals("client")) {
                        infoStatus.setText("It's the opponent's move.");
                        setDisable(true);
                        if (field.getProcessState() == TicTacToe.ProcessState.PLAYING) {
                            waitOpponentMove();
                        }
                    } else {
                        if (field.getProcessState() == TicTacToe.ProcessState.PLAYING) {
                            waitOpponentMove();
                        }
                        infoStatus.setText("It's the opponent's move.");
                        setDisable(true);
                    }
                    reactToWin();
                }
                break;
            }
        }
    }

    /**
     * Method making all buttons disabled or available.
     * @param argument is true if buttons should be blocked and false otherwise.
     */
    protected void setDisable(boolean argument) {
        for (int i = 0; i < size; i++) {
            pane.getChildren().get(i).setDisable(argument);
        }
        start.setDisable(argument);
    }

    /**
     * Method realizing active waiting of opponent turn (used threads).
     */
    public void waitOpponentMove() {
        new Thread(() -> {
            int position = 'x';
            while (true) {
                try {
                    if (inStream.available() == 0) {
                        try {
                            position = inStream.read() - '0';
                        } catch (SocketException e) {
                            isInProcess = false;
                        }
                        break;
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            int finalPosition = position;
            Platform.runLater(() -> reactToOpponentMove(finalPosition));
        }).start();
    }

    /**
     * Method realizing reacting to the opponent move.
     * @param indexOfButton is index of pressed earlier button.
     */
    private void reactToOpponentMove(int indexOfButton) {
        if (indexOfButton == 9) {
            newGameStarted = true;
            startNewGame();

        } else if (indexOfButton >= 0 && indexOfButton <= 8) {
            field.makeMove(indexOfButton);
            buttons[indexOfButton].setText(String.valueOf(field.getNextSymbol()));

            infoStatus.setText("Make your move.");
            setDisable(false);
            reactToWin();

        } else {
            Alert message = new Alert(Alert.AlertType.INFORMATION);
            message.setTitle("game over");
            message.setContentText("The connection is lost.");
            message.showAndWait();
            isInProcess = false;
            Platform.exit();
        }
    }

    /**
     * Method realizing reacting to the win.
     */
    private void reactToWin() {
        if (field.getProcessState() == TicTacToe.ProcessState.WIN) {;
            reactToEnd(field.getNextSymbol() + "-player has won. Press 'Start'.");
        } else if (field.getProcessState() == TicTacToe.ProcessState.DRAW) {
            reactToEnd("There is no winner.");
        }
    }

    /**
     * Method realizing reacting to the end of the game.
     * @param message
     */
    private void reactToEnd(String message) {
        newGameStarted = true;
        Alert gameMessage = new Alert(Alert.AlertType.INFORMATION);
        gameMessage.setTitle("game over");
        gameMessage.setHeaderText("Game over.");
        gameMessage.setContentText(message);
        gameMessage.showAndWait();
        setDisable(true);
        start.setDisable(false);
    }

    /**
     * Method setting streams.
     * @param in is the input stream.
     * @param out is the output stream
     */
    public void setStreams(InputStream in, PrintStream out) {
        inStream = in;
        outStream = out;
    }

    /**
     * Method checking if the game is playing yet.
     * @return true if it is and false otherwise.
     */
    public boolean getProgressStatus() {
        return isInProcess;
    }
}