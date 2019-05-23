package g144.krylova;

import java.io.*;
import java.util.HashMap;
import java.util.ArrayList;

/**
 * Class containing the realization of the prefix tree — trie.
 */
public class Trie implements Serializable {
    private Node root = new Node();
    private ArrayList<String> words = new ArrayList<>();
    private int size = 0;

    /**
     * Method adding a string element to the trie.
     * @param element is the word to add.
     * @return true if the adding was successful and false otherwise.
     */
    public boolean add(String element) {
        if (contains(element)) {
            return false;
        }
        words.add(element);
        Node currentNode = root;
        currentNode.howManyIsPrefixFor++;
        for (int index = 0; index < element.length(); index++) {
            if (!currentNode.children.containsKey(element.charAt(index))) {
                String newString = currentNode.text + element.charAt(index);
                currentNode.children.put(element.charAt(index), new Node(newString));
            }
            currentNode = currentNode.children.get(element.charAt(index));
            currentNode.howManyIsPrefixFor++;
            if (!currentNode.isEndOfWord && currentNode.text.equals(element)) {
                currentNode.isEndOfWord = true;
                size++;
                return true;
            }
        }
        return false;
    }

    /**
     * Method checking if the word is among the elements of the trie.
     * @param element is word to check.
     * @return true if there is the word and false otherwise.
     */
    public boolean contains(String element) {
        int index = 0;
        Node currentNode = root;
        while (index < element.length()) {
            if (!currentNode.children.containsKey(element.charAt(index))) {
                return false;
            }
            currentNode = currentNode.children.get(element.charAt(index));
            index++;
        }
        return currentNode.isEndOfWord;
    }

    /**
     * Method removing a string element from the trie.
     * @param element is word to remove.
     * @return true if the adding was successful and false otherwise.
     */
    public boolean remove(String element) {
        if (!contains(element)) {
            return false;
        }
        words.remove(element);
        Node currentNode = root;
        root.howManyIsPrefixFor--;
        for (int i = 0; i < element.length(); ++i) {
            Node parent = currentNode;
            currentNode.howManyIsPrefixFor--;
            currentNode = currentNode.children.get(element.charAt(i));
            if (currentNode.howManyIsPrefixFor == 0) {
                parent.children.remove(element.charAt(i));
                size--;
                return true;
            }
        }
        currentNode.isEndOfWord = false;
        size--;
        return true;
    }

    /**
     * Method returning number of elements in the trie.
     * @return the size of the trie.
     */
    public int size() {
        return this.size;
    }

    /**
     * Method counting how many words in the trie have this prefix.
     * @param prefix is prefix to check.
     * @return the amount of the words beginning with this prefix.
     */
    public int howManyStartWithPrefix(String prefix) {
        Node current = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!current.children.containsKey(prefix.charAt(i))) {
                return 0;
            }
            current = current.children.get(prefix.charAt(i));
        }
        return current.howManyIsPrefixFor;
    }

    /**
     * Method printing the trie to the output stream.
     * @param out is stream for printing.
     */
    public void serialize(OutputStream out) throws IOException {
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(out));
        for (String currentWord: words) {
            output.write(currentWord + '\n');
        }
        output.close();
    }

    /**
     * Method reading the trie from the input stream.
     * @param in is stream for reading.
     */
    public void deserialize(InputStream in) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(in));
        Trie trie = new Trie();
        while (input.ready()) {
            trie.add(input.readLine());
        }
        root = trie.root;
        words = trie.words;
        size = trie.size;
        input.close();
    }

    /**
     * Constructor for trie node.
     */
    private class Node implements Serializable {
        private String text;
        private HashMap<Character, Node> children;
        boolean isEndOfWord;
        int howManyIsPrefixFor;

        Node() {
            text = "";
            children = new HashMap<>();
            howManyIsPrefixFor = 0;
            isEndOfWord = false;
        }

        Node(String string) {
            text = string;
            children = new HashMap<>();
            howManyIsPrefixFor = 0;
            isEndOfWord = false;
        }
    }
}