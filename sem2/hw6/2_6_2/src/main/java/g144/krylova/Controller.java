package g144.krylova;

import javafx.event.ActionEvent;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.fxml.FXML;
import java.util.ArrayList;

public class Controller {
    @FXML
    private Label message;

    @FXML
    private Button button_0;

    @FXML
    private Button button_1;

    @FXML
    private Button button_2;

    @FXML
    private Button button_3;

    @FXML
    private Button button_4;

    @FXML
    private Button button_5;

    @FXML
    private Button button_6;

    @FXML
    private Button button_7;

    @FXML
    private Button button_8;

    @FXML
    public void initialize() {
        buttons.add(button_0);
        buttons.add(button_1);
        buttons.add(button_2);
        buttons.add(button_3);
        buttons.add(button_4);
        buttons.add(button_5);
        buttons.add(button_6);
        buttons.add(button_7);
        buttons.add(button_8);
        message.setAlignment(Pos.CENTER);
        message.setText("Press Start");

        for (Button button : buttons) {
            button.setOnAction(event -> move(button));
            button.setDisable(true);
        }
    }

    private ArrayList<Button> buttons = new ArrayList<>();
    private TicTacToe game = new TicTacToe();

    private final String MOVE_X = "Move of X-player";
    private final String MOVE_O = "Move of O-player";
    private int numberOfPressedButtons = 0;

    /**
     * Method changing player.
     */
    private void changePlayer() {
        if (message.getText().equals(MOVE_X)) {
            message.setText(MOVE_O);
            return;
        }
        if (message.getText().equals(MOVE_O)) {
            message.setText(MOVE_X);
            return;
        }
    }

    /**
     * Method realizing reaction to the move.
     * @param button is pressed button.
     */
    @FXML
    public void move(Button button) {
        if (button.getText().equals("")) {
            button.setText(game.getNextSymbol());
            game.setState(buttons.indexOf(button), button.getText());
            if (game.hasWinner(buttons.indexOf(button)) == null) {
                changePlayer();
                game.rewriteNextSymbol();
                numberOfPressedButtons++;
                if (numberOfPressedButtons == 9) {
                    reactToDraw();
                }
            } else {
                reactToWin(game.hasWinner(buttons.indexOf(button)));
            }
            button.setDisable(true);
        }
    }

    /**
     * Method realizing reacting to the win.
     * @param winner is player that took the win.
     */
    private void reactToWin(String winner) {
        message.setText(winner + "-player has won. Press 'Start'.");
        for (Button button : buttons) {
            button.setDisable(true);
        }
    }

    /**
     * Method realizing reacting to the draw.
     */
    private void reactToDraw() {
        message.setText("There is no winner. Press 'Start'.");
        for (Button button : buttons) {
            button.setDisable(true);
        }
    }

    /**
     * Method starting the game.
     * @param event is action with 'start' button.
     */
    @FXML
    public void start(ActionEvent event) {
        for (Button button : buttons) {
            button.setDisable(false);
        }
        game.clear(buttons);
        message.setText(MOVE_X);
        this.numberOfPressedButtons = 0;
    }
}
