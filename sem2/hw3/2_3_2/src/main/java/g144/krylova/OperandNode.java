package g144.krylova;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * Class containing methods for working with node with operand symbol.
 */
public class OperandNode implements ExpressionTreeNode {
    private int value;

    public OperandNode(int operand) {
        value = operand;
    }

    public OperandNode(String expression, AtomicInteger index) throws IncorrectInputException {
        try {
            char currentSymbol = expression.charAt(index.get());

            if (currentSymbol == ')' || currentSymbol == ' ' || currentSymbol == '(') {
                index.set(index.get() + 1);
                currentSymbol = expression.charAt(index.get());
            }

            StringBuffer currentNumber = new StringBuffer();
            while ((Character.isDigit(currentSymbol) || currentSymbol == '-')){
                currentNumber.append(currentSymbol);
                index.set(index.get() + 1);
                if ((index.get() < expression.length())){
                    currentSymbol = expression.charAt(index.get());
                } else{
                    break;
                }
            }

            value = Integer.parseInt(currentNumber.toString());

        } catch (NumberFormatException e){
            throw new IncorrectInputException("Expression is incorrect.");
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public int calculateNode() {
        return value;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void printNode() {
        System.out.print(value);
    }
}
