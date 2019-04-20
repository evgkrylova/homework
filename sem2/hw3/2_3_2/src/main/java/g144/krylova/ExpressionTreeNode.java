package g144.krylova;

/**
 * Interface containing realisation of main methods for work with expression tree node.
 */
public interface ExpressionTreeNode {
    /**
     * Method calculating the node.
     */
    int calculateNode() throws IncorrectInputException;

    /**
     * Method printing the node.
     */
    void printNode();
}
