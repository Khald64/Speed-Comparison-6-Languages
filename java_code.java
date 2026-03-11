import java.io.*;
import java.util.*;
import java.nio.file.*;
import java.util.stream.*;
import java.util.concurrent.TimeUnit;

public class java_code {
    public static void main(String[] args) throws Exception {
        int[] a = Files.lines(Paths.get("numbers.txt"))
                .mapToInt(Integer::parseInt)
                .toArray();
		System.out.println("Reading done.\nSorting...");
        long start = System.nanoTime();
        Arrays.sort(a);
        long ns = System.nanoTime() - start;

        System.out.println(ns+" nanoseconds");
    }
}