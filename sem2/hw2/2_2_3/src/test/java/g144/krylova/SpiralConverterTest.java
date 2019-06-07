package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.PrintStream;

class SpiralConverterTest {

    @Test
    void spiralFormTest() throws IOException, IncorrectSizeException{
        ByteArrayOutputStream testStream = new ByteArrayOutputStream();
        System.setOut(new PrintStream(testStream));
        int[][] inputArray = {{5, 4, 3}, {6, 1, 2}, {7, 8, 9}};
        String correctAnswer = "1 2 3 4 5 6 7 8 9 ";
        SpiralPrinter output = new ConsolePrinter();
        output.printSpiral(inputArray);
        assertEquals(correctAnswer, testStream.toString());
    }

    @Test
    void IncorrectSizeTest(){
        int[][] inputArray = {{5, 4}, {6, 1}};
        SpiralPrinter output = new ConsolePrinter();
        assertThrows(IncorrectSizeException.class, () -> output.printSpiral(inputArray));
    }
}