package g144.krylova;

/**
 * Class containing methods to calculate expression.
 */
public class Calculator {
    private double value = 0;
    private char operator = '\0';

    /**
     * Method calculating the result of basic operations.
     * @param inputValue is the new operand.
     * @return result of calculating.
     * @throws ArithmeticException if the divider is zero.
     */
    public double calculate(String inputValue) throws ArithmeticException{
        int newValue = Integer.parseInt(inputValue);
        switch (operator) {
            case '+': {
                value += newValue;
                return value;
            }
            case '-': {
                value -= newValue;
                return value;
            }
            case '*': {
                value *= newValue;
                return value;
            }
            case '/': {
                if (newValue == 0) {
                    throw new ArithmeticException();
                }
                value /= newValue;
                return value;
            }
            default: {
                value = newValue;
                return value;
            }
        }
    }

    /**
     * Method setting operator.
     * @param operator is new operator.
     */
    public void setOperator(char operator) {
        this.operator = operator;
    }

    /**
     * Method setting operand.
     * @param value is new operand.
     */
    public void setValue(double value) {
        this.value = value;
    }

    /**
     * Method clearing the calculator.
     */
    public void clear() {
        value = 0;
        operator = '\0';
    }
}
