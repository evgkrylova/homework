package g144.krylova;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Collection;

/**
 * Class realizing Collection as an AVLTree.
 * @param <Type> is comparable type of elements.
 */
public class AVLTree<Type extends Comparable<Type>> implements Collection<Type> {
    private AVLTreeNode root = null;
    private int size = 0;

    /**
     * Method adding a value to the collection.
     * @param value is value to add.
     * @return true if the value was successfully added and false otherwise.
     */
    @Override
    public boolean add(Type value) {
        if (isEmpty()) {
            root = new AVLTreeNode(value, null);
        } else {
            root.addNode(value);
        }
        size++;
        return true;
    }

    /**
     * Method adding all values of the 'col' collection to the current one.
     * @param col is collection containing values that should be added to the current collection.
     * @return true if values were successfully added and false otherwise.
     */
    @Override
    public boolean addAll(Collection<? extends Type> col) {
        boolean result = true;
        for (Type current : col) {
            result = result && add(current);
        }
        return result;
    }

    /**
     * Method clearing the collection.
     */
    @Override
    public void clear() {
        size = 0;
        root = null;
    }

    /**
     * Method returning is the value in the collection.
     * @param value is value to check.
     * @return true if the value in the collection and false otherwise.
     */
    @Override
    @SuppressWarnings("unchecked")
    public boolean contains(Object value) {
        return !isEmpty() && root.containsNode((Type) value);
    }

    /**
     * Method returning is the collection empty.
     * @return true if the collection is empty and false otherwise.
     */
    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * Method returning an Iterator over the elements in this collection.
     *
     * @return an Iterator.
     */
    @Override
    public Iterator<Type> iterator() {
        return new AVLTreeIterator();
    }

    /**
     * Method removing a value from the collection.
     * @param value is value to remove.
     * @return true if values were successfully removed and false otherwise.
     */
    @Override
    @SuppressWarnings("unchecked")
    public boolean remove(Object value) {
        return !isEmpty() && root.removeNode((Type) value);
    }

    /**
     * Method removing all values of the 'col' collection from the current one.
     * @param col is collection containing values that should be removed from the current collection.
     * @return true if values were successfully removed and false otherwise.
     */
    @Override
    public boolean removeAll(Collection<?> col) {
        boolean result = true;
        for (Object current : col) {
            result = result && remove(current);
        }
        return result;
    }

    /**
     * Method removing all values of the current collection except for 'col' collection values.
     * @param col is collection containing values that should be left in the current collection.
     * @return true if values were successfully retained and false otherwise.
     */
    @Override
    public boolean retainAll(Collection<?> col) {
        boolean result = false;
        for (Type current : this) {
            if (!col.contains(current)) {
                remove(current);
                result = true;
            }
        }
        return result;
    }

    /**
     * Method returning the elements number of the collection.
     */
    @Override
    public int size() {
        return size;
    }

    /**
     * Method merging all Objects of the collection into an array/
     * @return an array of the Objects.
     */
    @Override
    public Object[] toArray() {
        return toArray(new Object[size]);
    }

    /**
     * Method merging all values of the collection into an array/
     * @return an array of the values.
     */
    @Override
    @SuppressWarnings("unchecked")
    public <ValuesType> ValuesType[] toArray(ValuesType[] array) {
        ArrayList<ValuesType> arrayList = new ArrayList<>();
        for (Type temp : this) {
            arrayList.add((ValuesType) temp);
        }
        return arrayList.toArray(array);
    }

    /**
     * Method returning if all values of еру current collection is consisted in 'col' one.
     * @param col - entered collection, where elements from
     * @return true if the 'col's values are in the collection and false otherwise.
     */
    @Override
    public boolean containsAll(Collection<?> col) {
        boolean result = true;
        for (Object current : col) {
            result = result && contains(current);
        }
        return result;
    }

    /**
     * Method converting collection elements to the string.
     * @return a string version of the collection elements.
     */
    @Override
    public String toString() {
        return isEmpty() ? "null" : root.toString();
    }

    /**
     * Class containing realization of the AVL tree node and methods for work with it.
     */
    private class AVLTreeNode {
        private Type value;
        private AVLTreeNode parent;
        private AVLTreeNode leftChild = null;
        private AVLTreeNode rightChild = null;
        private int height = 1;

        AVLTreeNode(Type value, AVLTreeNode parent) {
            this.value = value;
            this.parent = parent;
        }

        /**
         * Method balancing heights of nodes.
         */
        private void balance() {
            updateHeight();

            if (balanceFactor() == 2) {
                if (leftChild.balanceFactor() < 0) {
                    leftChild.leftRotate();
                }
                rightRotate();
            } else if (balanceFactor() == -2) {
                if (rightChild.balanceFactor() > 0) {
                    rightChild.rightRotate();
                }
                leftRotate();
            }
        }

        /**
         * Method updating the element height.
         */
        private void updateHeight() {
            int leftHeight = leftChild == null ? 0 : leftChild.height;
            int rightHeight = rightChild == null ? 0 : rightChild.height;
            height = 1 + Integer.max(leftHeight, rightHeight);
        }

        /**
         * Method calculating the balance factor of the node.
         */
        private int balanceFactor() {
            int leftHeight = leftChild == null ? 0 : leftChild.height;
            int rightHeight = rightChild == null ? 0 : rightChild.height;
            return leftHeight - rightHeight;
        }

        /**
         * Method realizing right rotate.
         */
        private void rightRotate() {
            AVLTreeNode current = leftChild;
            if (current.rightChild != null) {
                current.rightChild.parent = this;
            }
            leftChild = current.rightChild;
            current.rightChild = this;

            if (parent != null) {
                if (equals(parent.leftChild)) {
                    parent.leftChild = current;
                } else {
                    parent.rightChild = current;
                }
            } else {
                root = current;
            }
            current.parent = parent;
            parent = current;
            current.updateHeight();
            this.updateHeight();
        }

        /**
         * Method realizing left rotate.
         */
        private void leftRotate() {
            AVLTreeNode current = rightChild;
            if (current.leftChild != null)
                current.leftChild.parent = this;
            rightChild = current.leftChild;
            current.leftChild = this;
            if (parent == null) {
                root = current;
            } else {
                if (equals(parent.rightChild)) {
                    parent.rightChild = current;
                } else {
                    parent.leftChild = current;
                }
            }
            current.parent = parent;
            parent = current;
            this.updateHeight();
            current.updateHeight();
        }

        /**
         * Method adding a value to the tree.
         * @param value is value to add.
         */
        public void addNode(Type value) {
            if (value.compareTo(this.value) < 0) {
                if (leftChild == null) {
                    leftChild = new AVLTreeNode(value, this);
                } else {
                    leftChild.addNode(value);
                }
            } else {
                if (rightChild == null) {
                    rightChild = new AVLTreeNode(value, this);
                } else {
                    rightChild.addNode(value);
                }
            }
            balance();
        }

        /**
         * Method changing the current node to the new named 'n'.
         * @param n is node to change to.
         */
        private void swapNode(AVLTreeNode n) {
            if (n == null) {
                if (parent != null) {
                    if (this.equals(parent.leftChild)) {
                        parent.leftChild = null;
                    } else {
                        parent.rightChild = null;
                    }
                } else {
                    root = null;
                }
                return;
            }

            value = n.value;
            if (n.equals(n.parent.leftChild)) {
                n.parent.leftChild = n.leftChild;
            } else {
                n.parent.rightChild = n.rightChild;
            }
        }

        /**
         * Method removing a value to the tree.
         * @param value is value to remove.
         */
        public boolean removeNode(Type value) {
            if (value.compareTo(this.value) < 0) {
                leftChild.removeNode(value);
                return true;
            }
            if (value.compareTo(this.value) > 0) {
                rightChild.removeNode(value);
                return true;
            }
            if (leftChild != null && rightChild != null) {
                AVLTreeNode minRight = rightChild;
                while (minRight.leftChild != null) {
                    minRight = minRight.leftChild;
                }
                swapNode(minRight);
            } else if (leftChild != null) {
                swapNode(leftChild);
            } else if (rightChild != null) {
                swapNode(rightChild);
            } else {
                swapNode(null);
            }
            balance();
            size--;
            return true;
        }

        /**
         * Method returning is the value in the tree.
         * @param value is value to check.
         * @return true if the value in the tree and false otherwise.
         */
        public boolean containsNode(Type value) {
            if (value.equals(this.value)) {
                return true;
            }

            if (value.compareTo(this.value) < 0) {
                return (leftChild != null) && leftChild.containsNode(value);
            } else {
                return (rightChild != null) && rightChild.containsNode(value);
            }
        }

        /**
         * Method adding all lower values to array.
         * @param node is start node.
         * @param array is array to add to.
         */
        private void toArray(AVLTreeNode node, ArrayList<Type> array) {
            if (node == null) {
                return;
            }
            node.toArray(node.leftChild, array);
            array.add(node.value);
            node.toArray(node.rightChild, array);
        }

        /**
         * A method that converts node to the string
         * @return node in a line representation
         */
        @Override
        public String toString() {
            String result = "(" + value.toString() + " ";
            result += leftChild == null ? "null" : leftChild.toString();
            result += " ";
            result += rightChild == null ? "null" : rightChild.toString();
            return result + ")";
        }
    }

    /**
     * Class containing realization of the AVL tree iterator and methods for work with it.
     */
    private class AVLTreeIterator implements Iterator<Type> {
        ArrayList<Type> array;

        AVLTreeIterator() {
            array = new ArrayList<>();
            root.toArray(root, array);
        }

        @Override
        public boolean hasNext() {
            return !array.isEmpty();
        }

        @Override
        public Type next() {
            if (isEmpty()) {
                return null;
            }
            return array.remove(0);
        }
    }
}


