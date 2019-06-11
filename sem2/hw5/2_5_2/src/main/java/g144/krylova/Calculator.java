package g144.krylova;

/**
 * Class containing method returning result of operation with two values.
 */
public class Calculator {
    /**
     * Method calculating the result of basic operations.
     * @param a is the first operand.
     * @param b is the second operand.
     * @param operation is operation to calculate.
     * @return result of calculating.
     * @throws ArithmeticException if the divider is zero.
     * @throws WrongOperatorException if the divider is zero.
     */
    public static double calculate(double a, double b, char operation) throws ArithmeticException, WrongOperatorException{
        switch (operation){
            case '+':{
                return a + b;
            }
            case '-':{
                return a - b;
            }
            case '*':{
                return a * b;
            }
            case '/':{
                if (b == 0){
                    throw new ArithmeticException();
                }
                return a / b;
            }
            default:{
                throw new WrongOperatorException("There is no such operator.");
            }
        }
    }
}
