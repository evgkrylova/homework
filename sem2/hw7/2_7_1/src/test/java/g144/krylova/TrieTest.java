package g144.krylova;

import org.junit.jupiter.api.Test;

import java.io.FileOutputStream;
import java.io.*;

import static org.junit.jupiter.api.Assertions.*;

class TrieTest {

    @Test
    void addTest() {
        Trie trie = new Trie();
        assertTrue(trie.add("she"));
        assertTrue(trie.add("he"));
        assertTrue(trie.add("her"));
        assertEquals(3, trie.size());
    }

    @Test
    void containsTest() {
        Trie trie = new Trie();
        trie.add("she");
        trie.add("he");
        trie.add("her");
        assertTrue(trie.contains("she"));
        assertTrue(trie.contains("her"));
        assertFalse(trie.contains("er"));
    }

    @Test
    void removeTest() {
        Trie trie = new Trie();
        trie.add("she");
        trie.add("he");
        trie.add("her");
        assertTrue(trie.remove("he"));
        assertEquals(2, trie.size());
        assertTrue(trie.remove("she"));
        assertTrue(trie.remove("her"));
        assertFalse(trie.remove("her"));
        assertEquals(0, trie.size());
    }

    @Test
    void sizeTest() {
        Trie trie = new Trie();
        trie.add("she");
        trie.add("he");
        trie.add("her");
        assertEquals(3, trie.size());
    }

    @Test
    void howManyStartWithPrefixTest() {
        Trie trie = new Trie();
        trie.add("she");
        trie.add("he");
        trie.add("her");
        trie.add("shelter");
        assertEquals(2, trie.howManyStartWithPrefix("h"));
        assertEquals(2, trie.howManyStartWithPrefix("she"));
    }
}