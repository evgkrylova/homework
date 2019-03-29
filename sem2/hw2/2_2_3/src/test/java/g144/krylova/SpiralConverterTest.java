package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SpiralConverterTest {

    @Test
    void spiralFormTest() throws IncorrectSizeException{
        int[][] input = {{5, 4, 3}, {6, 1, 2}, {7, 8, 9}};
        String correctAnswer = "1 2 3 4 5 6 7 8 9 ";
        String answer = SpiralConverter.spiralForm(input);
        assertEquals(correctAnswer, answer);
    }

    @Test
    void IncorrectSizeTest(){
        int[][] input = {{5, 4}, {6, 1}};
        assertThrows(IncorrectSizeException.class, () -> SpiralConverter.spiralForm(input));
    }
}