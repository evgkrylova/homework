package g144.krylova;

import org.junit.jupiter.api.Test;

import static g144.krylova.Calculator.calculate;
import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {

    @Test
    void calculateSumTest() {
        assertEquals(6, calculate(2, 4, '+'));
    }

    @Test
    void calculateDividingTest() {
        assertEquals(4, calculate(8, 2, '/'));
    }

    @Test
    void calculateMultiplicationTest() {
        assertEquals(8, calculate(2, 4, '*'));
    }
}