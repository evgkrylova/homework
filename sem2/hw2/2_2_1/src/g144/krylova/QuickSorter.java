package g144.krylova;

/**
 * A class containing method sorting array with quick sort.
 */
public class QuickSorter implements Sorter {
    @Override
    public void sort(int[] array) {
        quickSort(array, 0, array.length - 1);
    }

    private void quickSort(int[] array, int left, int right) {
        int leftHold = left;
        int rightHold = right;
        int comparing = array[left];
        while (left < right) {
            while ((array[right] >= comparing) && (left < right)) {
                right--;
            }
            if (left != right) {
                array[left] = array[right];
                left++;
            }
            while ((array[left] <= comparing) && (left < right)) {
                left++;
            }
            if (left != right) {
                array[right] = array[left];
                right--;
            }
        }
        array[left] = comparing;
        comparing = left;
        left = leftHold;
        right = rightHold;
        if (left < comparing) {
            quickSort(array, left, comparing - 1);
        }
        if (right > comparing) {
            quickSort(array, comparing + 1, right);
        }
    }
}
