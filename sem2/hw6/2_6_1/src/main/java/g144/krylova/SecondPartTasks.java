package g144.krylova;

import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.stream.Collectors;
import java.util.stream.Stream;

final class SecondPartTasks {

    // Найти строки из переданных файлов, в которых встречается указанная подстрока.
    static List<String> findQuotes(List<String> paths, CharSequence sequence) {
        return paths
                .stream()
                .filter(string -> string.contains(sequence))
                .collect(Collectors.toList());
    }

    // В квадрат с длиной стороны 1 вписана мишень.
    // Стрелок атакует мишень и каждый раз попадает в произвольную точку квадрата.
    // Надо промоделировать этот процесс с помощью класса java.util.Random и посчитать, какова вероятность попасть в мишень.
    static double piDividedBy4() {
        int AMOUNT_SHOTS = 1000000;
        double RADIUS = 0.5;
        Random random = new Random();

        double amountHits = (double) Stream.generate(() ->
                (Math.pow(random.nextDouble() - RADIUS, 2) + Math.pow(random.nextDouble() - RADIUS, 2)))
                .limit(AMOUNT_SHOTS)
                .filter(distance -> distance <= Math.pow(RADIUS, 2))
                .count();
        return amountHits / AMOUNT_SHOTS;
    }

    // Дано отображение из имени автора в список с содержанием его произведений.
    // Надо вычислить, чья общая длина произведений наибольшая.
    static String findPrinter(Map<String, List<String>> compositions) {
        return compositions
                .entrySet()
                .stream()
                .max(Comparator.comparingInt(entry -> entry.getValue()
                                .stream()
                                .mapToInt(String::length).sum()
                        )
                )
                .map(Map.Entry::getKey)
                .orElse("");
    }

    // Вы крупный поставщик продуктов. Каждая торговая сеть делает вам заказ в виде Map<Товар, Количество>.
    // Необходимо вычислить, какой товар и в каком количестве надо поставить.
    public static Map<String, Integer> calculateGlobalOrder(List<Map<String, Integer>> orders) {
        return orders.stream()
                .flatMap(order -> order.entrySet()
                        .stream())
                .collect(Collectors.groupingBy(Map.Entry::getKey, Collectors.summingInt(Map.Entry::getValue)));
    }
}
