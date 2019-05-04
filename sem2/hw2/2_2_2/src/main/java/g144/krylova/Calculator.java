package g144.krylova;

/**
 * Class containing calculator algorithm using stack for the postfix expression.
 */
public class Calculator {

    /**
     * Method calculating a postfix expression.
     * @param expression is expression that should be converted to the postfix form.
     * @return the result of a calculation.
     * @throws IncorrectInputException if the method top or pop was used in relation to the empty stack.
     */
    public static Float calculate(String expression) throws IncorrectInputException{
        ListStack<Float> stack = new ListStack<>();
        int length = expression.length();

        for (int i = 0; i < length; i++) {
            Character currentElement = expression.charAt(i);

            if (Character.isDigit(currentElement)) {
                Float addingElement = (float)(Character.getNumericValue(currentElement));
                stack.push(addingElement);
            }
            else if (isBinaryOperator(currentElement)) {
                try {
                    Float secondOperand = stack.pop();
                    Float firstOperand = stack.pop();
                    stack.push(calculateBasicOperations(firstOperand, secondOperand, currentElement));
                } catch (EmptyStackException e) {
                    throw new IncorrectInputException();
                }
            }
        }

        try {
            return stack.pop();
        } catch (EmptyStackException e) {
            throw new IncorrectInputException();
        }
    }

    /**
     * Method calculating basic binary operations.
     * @param a is the first operand.
     * @param b is the second operand.
     * @param binaryOperator is the operator.
     * @return the result of a calculation.
     */
    private static float calculateBasicOperations(float a, float b, Character binaryOperator) {
        switch (binaryOperator) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                return -1;
        }
    }

    /**
     * Method returning is the symbol a binary operator.
     * @param c is symbol to check.
     * @return true if the symbol is a binary operator and false otherwise.
     */
    private static boolean isBinaryOperator(Character c) {
        return (c == '+') || (c == '-') || (c == '*') || (c == '/');
    }
}
