package com.yiibai;

import java.io.DataInput;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;


public class readline {
   public static void main(String[] args) throws Exception {
      
       int ch;
        while ((ch = System.in.read()) != -1)
        {
            if (ch != '\n' && ch != '\r')
            {
                System.out.println((char)ch);
                // processChar((char)ch);
            }
        }
        //// Open the file
        //FileInputStream fstream = new FileInputStream("readline.java");
        //BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

        //String strLine;
        //char xx;

        ////Read File Line By Line
        //// while ((strLine = br.readLine()) != null)   {
        //while ((xx = br.readChar()) != null)   {
        //    // Print the content on the console
        //    System.out.println (xx);
        //}

        ////Close the input stream
        //fstream.close();
   }
}
