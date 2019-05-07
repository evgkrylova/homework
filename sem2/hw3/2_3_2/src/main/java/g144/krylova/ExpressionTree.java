package g144.krylova;

/**
 * Class describing binary tree for calculating an expression in postfix form.
 */
public class ExpressionTree {
    private ExpressionTreeNode root;

    public ExpressionTree(String expression) throws IncorrectInputException {
        IndexBoxer index = new IndexBoxer();
        if (Character.isDigit(expression.charAt(index.getIndex()))) {
            root = new OperandNode(expression, index);
        } else {
            root = new OperatorNode(expression, index);
        }
    }

    /**
     * Method calculating the expression from the tree.
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
