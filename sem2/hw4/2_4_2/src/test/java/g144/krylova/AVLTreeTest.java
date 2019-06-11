package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class AVLTreeTest {

    @Test
    public void addNodeTest() {
        AVLTree<Integer> tree = new AVLTree<>();
        String answer = "(4 (2 (1 null null) (3 null null)) (8 (6 (5 null null) (7 null null)) (9 null (10 null null))))";
        for (int i = 1; i <= 10; i++) {
            tree.add(i);
        }

        assertEquals(answer, tree.toString());
    }

    @Test
    public void containsNodeTest() {
        AVLTree<Integer> tree = new AVLTree<>();
        for (int i = 1; i <= 5; i++) {
            tree.add(i);
        }
        assertTrue(tree.contains(1));
        assertTrue(tree.contains(5));
        assertTrue(tree.contains(2));
        assertFalse(tree.contains(7));
    }

    @Test
    public void removeNodeTest() {
        AVLTree<Integer> tree = new AVLTree<>();
        for (int i = 1; i <= 10; i++) {
            tree.add(i);
        }
        assertTrue(tree.remove(1));
        assertEquals("(4 (2 null (3 null null)) (8 (6 (5 null null) (7 null null)) (9 null (10 null null))))", tree.toString());

        assertTrue(tree.remove(4));
        assertEquals("(5 (2 null (3 null null)) (8 (6 null (7 null null)) (9 null (10 null null))))", tree.toString());

        assertTrue(tree.remove(8));
        String str = tree.toString();
        assertEquals("(5 (2 null (3 null null)) (9 (6 null (7 null null)) (10 null null)))", tree.toString());
    }

    @Test
    public void sizeTest() {
        AVLTree<Integer> tree = new AVLTree<>();
        for (int i = 1; i <= 4; i++) {
            tree.add(i);
        }
        assertEquals(4, tree.size());
        tree.remove(2);
        assertEquals(3, tree.size());
    }
}