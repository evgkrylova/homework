package g144.krylova;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class Controller {
    private Calculator calculator = new Calculator();
    private boolean isLastOperator = false;

    @FXML
    private Label expression;

    @FXML
    private Label currentValue;

    @FXML
    private Button sum;

    @FXML
    private Button dividing;

    @FXML
    private Button multiplication;

    @FXML
    private Button subtraction;

    @FXML
    private Button calculate;

    @FXML
    private Button clear;

    @FXML
    private Button digit_0;

    @FXML
    private Button digit_1;

    @FXML
    private Button digit_2;

    @FXML
    private Button digit_3;

    @FXML
    private Button digit_4;

    @FXML
    private Button digit_5;

    @FXML
    private Button digit_6;

    @FXML
    private Button digit_7;

    @FXML
    private Button digit_8;

    @FXML
    private Button digit_9;

    private Button[] values;
    private Button[] operators;

    /**
     * Method creating lists of buttons.
     */
    @FXML
    public void initialize() {
        values = new Button[]{digit_0, digit_1, digit_2, digit_3, digit_4, digit_5, digit_6, digit_7, digit_8, digit_9};
        operators = new Button[]{sum, subtraction, dividing, multiplication, calculate};
    }

    /**
     * Method for reacting to pressing digit button.
     * @param event is event for button.
     */
    @FXML
    public void pressDigit(ActionEvent event) {
        if (isLastOperator) {
            currentValue.setText("");
        }
        isLastOperator = false;
        currentValue.setText(currentValue.getText() + getButtonString(event));
        if (currentValue.getText().equals("0")){
            blockButtons(values);
        }
        expression.setText(expression.getText() + getButtonString(event));
        unblockButtons(operators);
    }

    /**
     * Method for reacting to pressing operand button.
     * @param event is event for button.
     */
    @FXML
    public void pressOperand(ActionEvent event) {
        try {
            double value = calculator.calculate(currentValue.getText());
            currentValue.setText(String.valueOf(value));
            calculator.setOperator(getButtonString(event).charAt(0));
            expression.setText(expression.getText() + " " + getButtonString(event) + " ");
            isLastOperator = true;
            unblockButtons(values);
        } catch (ArithmeticException e) {
            currentValue.setText("Error");
            blockButtons(values);
        }
        blockButtons(operators);
    }

    /**
     * Method for reacting to pressing equal button.
     * @param event is event for button.
     */
    @FXML
    public void pressCalculate(ActionEvent event) {
        blockButtons(values);
        blockButtons(operators);

        try {
            double value = calculator.calculate(currentValue.getText());
            currentValue.setText(String.valueOf(value));
            expression.setText(expression.getText() + " " + getButtonString(event) + " ");
        } catch (ArithmeticException e) {
            currentValue.setText("Error");
        }
    }

    /**
     * Method cleaning the memory of expression.
     * @param event is event for button.
     */
    @FXML
    public void pressClear(ActionEvent event) {
        expression.setText("");
        currentValue.setText("");
        calculator.clear();
        unblockButtons(operators);
        unblockButtons(values);
        isLastOperator = false;
    }

    /**
     * Method blocking buttons.
     * @param toBlock is array of buttons to block.
     */
    private void blockButtons(Button[] toBlock) {
        for (Button button : toBlock) {
            button.setDisable(true);
        }
    }

    /**
     * Method unblocking buttons.
     * @param toBlock is array of buttons to unblock.
     */
    private void unblockButtons(Button[] toBlock) {
        for (Button button : toBlock) {
            button.setDisable(false);
        }
    }

    /**
     * Method returning the string of button's value.
     * @param event is event for button.
     * @return button string.
     */
    private String getButtonString(ActionEvent event) {
        String string = event.getSource().toString();
        return Character.toString(string.charAt(string.length() - 2));
    }
}
