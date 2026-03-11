import java.io.*;
import java.nio.file.*;
import java.util.*;

public class java_code {
    static void quicksort(int[] a, int left, int right) {
        if (left >= right) return;
        int pivot = a[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (a[j] <= pivot) {
                i++;
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
        int tmp = a[i + 1];
        a[i + 1] = a[right];
        a[right] = tmp;
        int p = i + 1;
        quicksort(a, left, p - 1);
        quicksort(a, p + 1, right);
    }

    public static void main(String[] args) throws Exception {
        int[] a = Files.lines(Paths.get("numbers.txt"))
                       .mapToInt(Integer::parseInt)
                       .toArray();

		System.out.println("Reading done.\nSorting...");
        long start = System.nanoTime();
        quicksort(a, 0, a.length - 1);
        long ns = System.nanoTime() - start;

        System.out.println(ns+" nanoseconds");
    }
}

