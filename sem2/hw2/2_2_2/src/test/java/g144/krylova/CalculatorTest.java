package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {

    @Test
    void calculatorTest() throws EmptyStackException{
        String input = "58+2*42/-";
        Float correctAnswer = (float)(24);
        Float answer = Calculator.calculate(input);
        assertEquals(correctAnswer, answer);
    }
}