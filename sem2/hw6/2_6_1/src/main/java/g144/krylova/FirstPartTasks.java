package g144.krylova;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

final class FirstPartTasks {
    private FirstPartTasks() {
    }

    // Список названий альбомов
    static List<String> allNames(Stream<g144.krylova.Album> albums) {
        return albums
                .map(Album::getName)
                .collect(Collectors.toList());
    }

    // Список названий альбомов, отсортированный лексикографически по названию
    static List<String> allNamesSorted(Stream<Album> albums) {
        return albums
                .map(Album::getName)
                .sorted()
                .collect(Collectors.toList());
    }

    // Список треков, отсортированный лексикографически по названию, включающий все треки альбомов из 'albums'
    static List<String> allTracksSorted(Stream<Album> albums) {
        return albums
                .flatMap(album -> album.getTracks()
                        .stream())
                .map(Track::getName)
                .sorted()
                .collect(Collectors.toList());
    }

    // Список альбомов, в которых есть хотя бы один трек с рейтингом более 95, отсортированный по названию
    static List<Album> sortedFavorites(Stream<Album> albums) {
        return albums
                .filter(album -> album.getTracks()
                        .stream()
                        .anyMatch(track -> track.getRating() > 95))
                .sorted(Comparator.comparing(Album::getName))
                .collect(Collectors.toList());
    }

    // Сгруппировать альбомы по артистам
    static Map<Artist, List<Album>> groupByArtist(Stream<Album> albums) {
        return albums
                .collect(Collectors.groupingBy(Album::getArtist));
    }

    // Сгруппировать альбомы по артистам (в качестве значения вместо объекта 'Artist' использовать его имя)
    static Map<Artist, List<String>> groupByArtistMapName(Stream<Album> albums) {
        return albums
                .collect(Collectors.groupingBy(Album::getArtist, Collectors.mapping(Album::getName, Collectors.toList())));
    }

    // Число повторяющихся альбомов в потоке
    static long countAlbumDuplicates(Stream<Album> albums) {
        return albums
                .collect(Collectors.groupingBy(Object::toString, Collectors.toList()))
                .values()
                .stream()
                .filter(albums1 -> albums1.size() > 1)
                .count();
    }

    // Альбом, в котором максимум рейтинга минимален
    // (если в альбоме нет ни одного трека, считать, что максимум рейтинга в нем --- 0)
    static Optional<Album> minMaxRating(Stream<Album> albums) {
        return albums
                .min(Comparator.comparing(album -> album.getTracks()
                        .stream()
                        .mapToInt(Track::getRating)
                        .max()
                        .orElse(0)));
    }

    // Список альбомов, отсортированный по убыванию среднего рейтинга его треков (0, если треков нет)
    static List<Album> sortByAverageRating(Stream<Album> albums) {
        return albums
                .sorted(Comparator.comparingDouble(album -> -album.getTracks()
                        .stream()
                        .mapToInt(Track::getRating)
                        .average()
                        .orElse(0)))
                .collect(Collectors.toList());
    }

    // Произведение всех чисел потока по модулю 'modulo'
    // (все числа от 0 до 10000)
    static int moduloProduction(IntStream stream, int modulo) {
        return stream
                .reduce((firstNumber, secondNumber) -> (firstNumber * secondNumber) % modulo)
                .orElse(-1);
    }

    // Вернуть строку, состояющую из конкатенаций переданного массива, и окруженную строками "<", ">"
    // см. тесты
    static String joinTo(String... strings) {
        return Arrays.stream(strings)
                .collect(Collectors.joining(", ", "<", ">"));
    }

    // Вернуть поток из объектов класса 'clazz'
    static <R> Stream<R> filterIsInstance(Stream<?> stream, Class<R> clazz) {
        return stream.
                filter(clazz::isInstance).
                map(clazz::cast);
    }
}
