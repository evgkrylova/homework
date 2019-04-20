package g144.krylova;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class ExpressionTreeTest {

    @Test
    void calculateTest() throws IncorrectInputException{
        ExpressionTree tree = new ExpressionTree("(* (+ 1 1) 2)");

        assertEquals(4, tree.calculate());
    }
}
