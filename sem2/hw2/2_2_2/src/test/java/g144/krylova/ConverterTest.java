package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ConverterTest {

    @Test
    void getPostfixNotationTest() throws IncorrectInputException{
        String input = "(5+8)*2-4/2";
        String correctAnswer = "58+2*42/-";
        String answer = Converter.getPostfixNotation(input);
        assertEquals(correctAnswer, answer);
    }
}