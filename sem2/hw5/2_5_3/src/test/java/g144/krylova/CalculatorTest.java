package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {

    @Test
    void calculateSumTest() {
        Calculator calculator = new Calculator();
        calculator.setValue(2);
        calculator.setOperator('+');
        assertEquals(6, calculator.calculate("4"));
    }

    @Test
    void calculateDividingTest() {
        Calculator calculator = new Calculator();
        calculator.setValue(8);
        calculator.setOperator('/');
        assertEquals(4, calculator.calculate("2"));
    }

    @Test
    void calculateMultiplicationTest() {
        Calculator calculator = new Calculator();
        calculator.setValue(2);
        calculator.setOperator('*');
        assertEquals(8, calculator.calculate("4"));
    }

    @Test
    void calculateZeroDividingTest() {
        Calculator calculator = new Calculator();
        calculator.setValue(8);
        calculator.setOperator('/');
        assertThrows(ArithmeticException.class, () -> calculator.calculate("0"));
    }
}