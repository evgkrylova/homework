package g144.krylova;

/**
 * Class containing methods for working with node with operand symbol.
 */
public class OperandNode implements ExpressionTreeNode {
    private int value;

    public OperandNode(String expression, IndexBoxer index) throws IncorrectInputException {
        try {
            char currentSymbol = expression.charAt(index.getIndex());

            if (currentSymbol == ')' || currentSymbol == ' ' || currentSymbol == '(') {
                index.setIndex(index.getIndex() + 1);
                currentSymbol = expression.charAt(index.getIndex());
            }

            StringBuffer currentNumber = new StringBuffer();
            while ((Character.isDigit(currentSymbol) || currentSymbol == '-')){
                currentNumber.append(currentSymbol);
                index.setIndex(index.getIndex() + 1);
                if ((index.getIndex() < expression.length())){
                    currentSymbol = expression.charAt(index.getIndex());
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
