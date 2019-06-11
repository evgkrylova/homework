package g144.krylova;

import javafx.fxml.FXML;
import java.io.*;
import java.net.*;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.event.ActionEvent;


public class ClientController {
    @FXML
    private GridPane parent;

    @FXML
    private Button startButton;

    @FXML
    private Label status;

    private Socket client;
    private static final int port = 10000;
    private GameProcess game;

    private InputStream inputStream;
    private PrintStream outputStream;

    public void initialize() {
        game = new GameProcess(parent, startButton, status, "client");
        Alert message = new Alert(Alert.AlertType.INFORMATION);
        message.setTitle("connection");
        message.setHeaderText("You should connect with the server.");
        message.setContentText("Click OK to connect.");
        message.showAndWait();

        while (true) {
            try {
                client = new Socket("localhost", port);
                inputStream = client.getInputStream();
                outputStream = new PrintStream(client.getOutputStream());
                game.setStreams(inputStream, outputStream);
                break;
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        game.setDisable(true);
        status.setText("It's the opponent's move.");
        game.waitOpponentMove();
    }

    /**
     * Method realizing reaction to the move.
     * @param event is event with pressed button.
     */
    @FXML
    private void pressButton(ActionEvent event) {
        game.pressCellButton(event);
    }

    /**
     * Method starting new game.
     */
    @FXML
    private void newGame() {
        game.startNewGame();
    }

    /**
     * Method checking if the game is ended.
     * @return true if it is not and false otherwise.
     */
    public boolean progressStatus() {
        return game.getProgressStatus();
    }

    /**
     * Method realizing reaction to the exit.
     */
    public void reactToExit() {
        outputStream.print(-1);
        outputStream.flush();
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
}