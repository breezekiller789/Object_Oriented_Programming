// package com.yiibai;

import java.io.DataInput;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*; 

//  Reference :
//  https://www.geeksforgeeks.org/linked-list-in-java/
//  https://stackoverflow.com/questions/21438078/how-to-read-char-from-standard-input-in-java

public class hw1 {
   public static void main(String[] args) throws Exception {
      
        // Creating object of class linked list 
        LinkedList<String> list = new LinkedList<String>(); 

        int ch;
        while ((ch = System.in.read()) != -1)
        {
            if (ch != '\n' && ch != '\r')
            {
                String ptr = String.format("%c", ch);
                list.add(ptr);
                // System.out.println((char)ch);
            }
        }
        // System.out.println("List : " + list);

        // int position = list.indexOf("h");
        // System.out.println(position);
        String x;
        int size = list.size();
        while(size > 0){
            // System.out.println("List : " + list);
            x = list.pop();
            // list.removeFirst();
            if(x == null)
                break;
            int cnt=1, position;
            while((position = list.indexOf(x)) != -1){
                list.remove(position);
                cnt++;
            }
            size -= cnt;
            System.out.println(x+"-"+cnt);
        }
   }
}
