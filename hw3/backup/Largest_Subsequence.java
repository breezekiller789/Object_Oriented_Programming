// https://www.w3schools.com/java/java_files_read.asp
import java.io.*;
import java.util.*;

public class Largest_Subsequence{

    public static void main(String[] args){
        try {
            int n = 100;
            ArrayList<Integer> list = new ArrayList<Integer>(n);
            File myObj = new File("./Input_Files/input8.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextInt()) {
                int data = myReader.nextInt();
                list.add(data);
                // System.out.println(data);
            }
            // System.out.println(list.size());
            int Max=1<<31, MaxCnt=0, Min_i=list.size()-1, Max_j=0;
            boolean Index_Not_Seen = true;
            for(int i=0; i<list.size(); i++){
                int sum = 0;
                Index_Not_Seen = true;
                // System.out.println("================================");
                // System.out.println("i = "+i);
                for(int j=i; j<list.size(); j++){
                    sum += list.get(j);
                    // System.out.println("\t\tj = "+j+"\tsum = "+sum);
                    if(sum >= Max){
                        if(sum == Max && Index_Not_Seen == true){
                            MaxCnt++;
                            Index_Not_Seen = false;
                        }
                        Max = sum;
                        Min_i = i;
                        Max_j = j;
                    }
                }
                // System.out.println("Min_i = "+Min_i+"\tMax_j = "+Max_j);
                // System.out.println("Max = "+max+"\tSum = "+sum);
            }
            // System.out.println("Max = "+Max);
            // System.out.println("MaxCnt = "+MaxCnt);
            // System.out.println("Min_i = "+Min_i+"\tMax_j = "+Max_j);

            MaxCnt=0;
            int MaxLen=1<<31;
            int Final_I=0, Final_J=0;
            for(int i=0; i<list.size(); i++){
                int Tmp_Max=1<<31, sum=0;
                for(int j=i; j<list.size(); j++){
                    sum += list.get(j);
                    if(sum == Max){
                        Max = sum;
                        Min_i = i;
                        Max_j = j;
                        if(Max_j - Min_i > MaxLen){
                            MaxLen = Max_j - Min_i;
                            Final_I = Min_i;
                            Final_J = Max_j;
                        }
                        // System.out.println("===========");
                        // System.out.println("Min_i = "+Min_i+"\tMax_j = "+Max_j);
                        // System.out.println("MaxLen = "+MaxLen);
                    }
                }
            }
            // System.out.println("===========");
            // System.out.println("Final_I = "+Final_I+"\tFinal_J = "+Final_J);



            for(int i=Final_I; i<=Final_J;i++){
                System.out.print(list.get(i)+" ");
            }
            System.out.println();



            // if(Min_i != 0){
            //     for(int i=Min_i-1; list.get(i) == 0; i--){
            //         System.out.print(list.get(i)+" ");
            //     }
            // }
            // for(int i=Min_i; i<=Max_j; i++){
            //     System.out.print(list.get(i)+" ");
            // }
            // System.out.println();
            myReader.close();
        }
        catch(FileNotFoundException e) {
            System.out.println("File Open Failure");
            e.printStackTrace();
        }
    }

}
