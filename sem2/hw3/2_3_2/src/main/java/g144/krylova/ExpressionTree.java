package g144.krylova;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * Class describing binary tree for calculating an expression in postfix form.
 */
public class ExpressionTree {
    private ExpressionTreeNode root;

    public ExpressionTree() {
        root = null;
    }

    public ExpressionTree(String expression) throws IncorrectInputException {
        AtomicInteger index = new AtomicInteger(0);
        if (Character.isDigit(expression.charAt(index.get()))) {
            root = new OperandNode(expression, index);
        } else {
            root = new OperatorNode(expression, index);
        }
    }

    /**
     * Method calculating the expression from the tree.
     * @throws IncorrectInputException if the input expression is impossible to calculate.
     */
    public int calculate() throws IncorrectInputException {
        return root.calculateNode();
    }

    /**
     * Method printing the tree.
     */
    public void print() {
        root.printNode();
    }
}
