package g144.krylova;

/**
 * Class containing shunting-yard algorithm - method that allows to convert expression to the postfix notation.
 */
public class Converter {
    /**
     * Method converting an infix expression to the postfix form.
     * @param expression is expression that should be converted to the postfix form.
     * @return the string that is the postfix form of the expression.
     * @throws EmptyStackException if the method top or pop was used in relation to the empty stack.
     */
    public static String getPostfixNotation(String expression) throws EmptyStackException{
        Stack<Character> operatorStack = new ListStack<>();
        int length = expression.length();
        StringBuffer resultedString = new StringBuffer();
        resultedString.setLength(lengthWithoutBrackets(expression));
        int index = 0;

        for (int i = 0; i < length; i++) {
            Character currentElement = expression.charAt(i);

            if (Character.isDigit(currentElement)) {
                resultedString.setCharAt(index++, currentElement);
            }

            else if (currentElement == '(') {
                operatorStack.push(currentElement);
            }

            else if (currentElement == ')') {
                while (operatorStack.top() != '(') {
                    resultedString.setCharAt(index++, operatorStack.pop());
                }
                operatorStack.pop();
            }

            else if (isBinaryOperator(currentElement)) {
                while ((operatorStack.getLength() > 0) && (isBinaryOperator(operatorStack.top())) && (priority(currentElement) <= priority(operatorStack.top()))) {
                    resultedString.setCharAt(index++, operatorStack.pop());
                }
                operatorStack.push(currentElement);
            }
        }

        int endLength = operatorStack.getLength();
        for (int i = 0; i < endLength; i++) {
            resultedString.setCharAt(index + i, operatorStack.pop());
        }

        return resultedString.toString();
    }

    /**
     * Method returning is the symbol a binary operator.
     * @param c is symbol to check.
     * @return true if the symbol is a binary operator and false otherwise.
     */
    private static boolean isBinaryOperator(Character c) {
        return (c == '+') || (c == '-') || (c == '*') || (c == '/');
    }

    /**
     * Method returning the number of priority for the binary operator.
     * @param c is symbol to check.
     * @return 0 if the operator has a low priority and 1 otherwise.
     */
    private static int priority(Character c) {
        if ((c == '+') || (c == '-')) {
            return 0;
        }
        return 1;
    }

    /**
     * Method returning the length of the expression without brackets.
     * @param expression is string to count symbols.
     * @return the number of expression symbols without brackets.
     */
    private static int lengthWithoutBrackets(String expression) {
        //String[] arrayExpression = expression.split(" ");
        int length = expression.length();
        int result = 0;

        for (int i = 0; i < length; i++) {
            if ((expression.charAt(i) != '(') && (expression.charAt(i) != ')')) {
                result++;
            }
        }
        return result;
    }
}
