package g144.krylova;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * Class containing methods for working with node with operator symbol.
 */
public class OperatorNode implements ExpressionTreeNode {
    private ExpressionTreeNode leftChild;
    private ExpressionTreeNode rightChild;
    private char operator;

    public OperatorNode(char operator) {
        this.operator = operator;
    }

    public OperatorNode(ExpressionTreeNode leftChild, ExpressionTreeNode rightChild, char operation) {
        this.operator = operation;
        this.leftChild = leftChild;
        this.rightChild = rightChild;
    }

    public void setLeftChild(ExpressionTreeNode leftChild) {
        this.leftChild = leftChild;
    }

    public void setRightChild(ExpressionTreeNode rightChild) {
        this.rightChild = rightChild;
    }

    public OperatorNode(String expression, AtomicInteger index) throws IncorrectInputException {
        skip(expression, index);
        char currentSymbol = expression.charAt(index.get());

        if (currentSymbol != '+' && currentSymbol != '-' && currentSymbol != '*' && currentSymbol != '/'){
            throw new IncorrectInputException("Expression is incorrect.");
        }
        operator = currentSymbol;

        index.set(index.get() + 1);
        skip(expression, index);
        currentSymbol = expression.charAt(index.get());

        if (Character.isDigit(currentSymbol)) {
            leftChild = new OperandNode(expression, index);
        } else {
            leftChild = new OperatorNode(expression, index);
        }

        skip(expression, index);
        currentSymbol = expression.charAt(index.get());
        if (Character.isDigit(currentSymbol)) {
            rightChild = new OperandNode(expression, index);
        } else {
            rightChild = new OperatorNode(expression, index);
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public int calculateNode() throws IncorrectInputException{
        switch (operator) {
            case '+':
                return leftChild.calculateNode() + rightChild.calculateNode();
            case '-':
                return leftChild.calculateNode() - rightChild.calculateNode();
            case '*':
                return leftChild.calculateNode() * rightChild.calculateNode();
            case '/':
                return leftChild.calculateNode() / rightChild.calculateNode();
            default:
                return 0;
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void printNode(){
        System.out.print("(" + operator + " ");
        leftChild.printNode();
        System.out.print(" ");
        rightChild.printNode();
        System.out.print(")");
    }

    /**
     * Method skipping brackets and spaces in the expression.
     * @param expression is the prefix expression which is calculating.
     * @param index is reading now symbol's index.
     */
    private void skip(String expression, AtomicInteger index){
        char currentSymbol = expression.charAt(index.get());
        while (currentSymbol == ')' || currentSymbol == ' ' || currentSymbol == '(') {
            index.set(index.get() + 1);
            currentSymbol = expression.charAt(index.get());
        }
    }
}
