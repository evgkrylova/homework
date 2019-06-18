package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;
import static g144.krylova.SecondPartTasks.*;
import java.util.*;

class SecondPartTasksTest {

    @Test
    void findQuotesTest() {
        assertEquals(Arrays.asList("banner", "tyrannosaurus", "Cannes"), findQuotes(Arrays.asList("banner", "tyrannosaurus", "banana", "Cannes"), "ann"));
        assertEquals(Arrays.asList("banner", "anniversary", "tyrannosaurus", "Cannes"), findQuotes(Arrays.asList("banner", "anniversary", "tyrannosaurus", "Cannes"), "ann"));
        assertEquals(Arrays.asList(), findQuotes(Arrays.asList("sustain", "nanometre", "belladonna", "banana"), "ann"));
    }

    @Test
    void piDividedBy4Test() {
        assertEquals(Math.PI / 4, piDividedBy4(), 0.001);
    }

    @Test
    void findPrinterTest() {
        Map<String, List<String>> compositions = new HashMap<>();
        List<String> bibliographyDazai = Arrays.asList("No Longer Human", "The Setting Sun", "Flowers of Buffonery");
        List<String> bibliographySartre = Arrays.asList("Dirty Hands", "The Words", "Nausea");
        List<String> bibliographyPlatonov = Arrays.asList("Chevengur", "The Foundation Pit", "The Return", "Fourteen Little Red Huts");
        compositions.put("Dazai", bibliographyDazai);
        compositions.put("Sartre", bibliographySartre);
        compositions.put("Platonov", bibliographyPlatonov);

        assertEquals("Platonov", SecondPartTasks.findPrinter(compositions));
    }

    @Test
    void calculateGlobalOrderTest() {
        List<Map<String, Integer>> orders = new ArrayList<>();

        orders.add(Map.of(
                "flour", 350,
                "egg", 100,
                "margarine", 70));

        orders.add(Map.of(
                "egg", 150,
                "milk", 500,
                "jerky", 825));

        orders.add(Map.of(
                "jerky", 2500,
                "olive", 50,
                "egg", 500));

        Map<String, Integer> correctResult = Map.of(
                "flour", 350,
                "egg", 750,
                "margarine", 70,
                "jerky", 3325,
                "olive", 50,
                "milk", 500);

        assertEquals(correctResult, SecondPartTasks.calculateGlobalOrder(orders));
    }
}
