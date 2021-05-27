package com.company;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        String w1, w2;

        w1 = "koralegosi";
        w2 = "miskoralgol";

        System.out.println(lcs(w1, w2).length() + " " + lcs(w1, w2));

    }

    public static int[][]arr_lcs (String w1, String w2) {
        int r1 = w1.length(), r2 = w2.length();
        int[][] S =  new int[r1 + 1][r2 + 1];

        for(int i = 1; i <= r1; i++) {
            for(int j = 1; j <= r2; j++) {
                if(w1.charAt(i - 1) ==  w2.charAt(j - 1))S[i][j] =  S[i - 1][j -1] + 1;
                    else
                if(S[i - 1][j] > S[i][j - 1]) S[i][j] = S[i - 1][j];
                    else S[i][j] = S[i][j - 1];
            }
        }

        return S;
    }

    public static String lcs(String w1, String w2) {
        int[][] S = arr_lcs(w1, w2);
        String res = "";

        int i = w1.length(), j = w2.length();

        do {
            if(w1.charAt(i - 1) == w2.charAt(j - 1)) {
                res += w1.charAt(i - 1);
                i--;
                j--;
            }
                else
            if(S[i - 1][j] >= S[i][j - 1]) i--;
                else j--;
        } while(S[i][j] != 0);

        return res;
    }
}
