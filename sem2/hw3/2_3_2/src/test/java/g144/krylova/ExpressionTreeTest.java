package g144.krylova;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class ExpressionTreeTest {

    @Test
    void firstCalculateTest() throws IncorrectInputException{
        ExpressionTree tree = new ExpressionTree("(* (+ 1 1) 2)");
        assertEquals(4, tree.calculate());
    }

    @Test
    void secondCalculateTest() throws IncorrectInputException{
        ExpressionTree tree = new ExpressionTree("+ 7 - / 5 2 / / * 8 9 4 3");
        assertEquals(3, tree.calculate());
    }

    @Test
    void thirdCalculateTest() throws IncorrectInputException{
        ExpressionTree tree = new ExpressionTree("- - 4 3 / 5 1");
        assertEquals(-4, tree.calculate());
    }

    @Test
    void emptyTreeCalculateTest() throws IncorrectInputException{
        OperatorNode root = new OperatorNode('*');
        OperandNode left = new OperandNode(3);
        OperandNode right = new OperandNode(2);
        root.setLeftChild(left);
        root.setRightChild(right);
        ExpressionTree tree = new ExpressionTree(root);
        assertEquals(6, tree.calculate());
    }
}
