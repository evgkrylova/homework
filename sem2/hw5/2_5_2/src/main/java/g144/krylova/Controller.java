package g144.krylova;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class Controller {
    @FXML
    private Spinner<Double> firstSpinner;
    @FXML
    private Spinner<Double> secondSpinner;
    @FXML
    private TextField resultField;
    @FXML
    private ComboBox<String> actionBox;

    /**
     * Method initializing elements.
     */
    @FXML
    public void initialize(){
        actionBox.getItems().addAll("+", "-", "*", "/");
        actionBox.getSelectionModel().select(0);
        firstSpinner.setValueFactory(new SpinnerValueFactory.DoubleSpinnerValueFactory(Double.MIN_VALUE - Double.MAX_VALUE, Double.MAX_VALUE, 0.0, 1.0));
        secondSpinner.setValueFactory(new SpinnerValueFactory.DoubleSpinnerValueFactory(Double.MIN_VALUE - Double.MAX_VALUE, Double.MAX_VALUE,0.0, 1.0));
        ChangeListener<Double> valueListener = ((observable, oldValue, newValue) -> calculate());
        ChangeListener<String> actionListener = ((observable, oldValue, newValue) -> calculate());
        firstSpinner.valueProperty().addListener(valueListener);
        secondSpinner.valueProperty().addListener(valueListener);
        actionBox.valueProperty().addListener(actionListener);


        calculate();
    }

    /**
     * Method calculating the result of operators and operand that are getting from spinners and comboBox.
     */
    public void calculate() {
        try {
            double firstValue = firstSpinner.getValue();
            double secondValue = secondSpinner.getValue();
            char action = actionBox.getValue().charAt(0);
            double result = Calculator.calculate(firstValue, secondValue, action);
            resultField.setText(Double.toString(result));
        }  catch (ArithmeticException e){
            resultField.setText("error");
        }
    }
}