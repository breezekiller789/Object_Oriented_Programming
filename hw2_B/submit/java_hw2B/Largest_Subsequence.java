// Reference :
//           https://www.w3schools.com/java/java_files_read.asp
import java.io.*;
import java.util.*;

public class Largest_Subsequence{

    public static void main(String[] args){
        try {
            File myObj = new File("./Input_Files/input13.txt");
            Scanner myReader = new Scanner(myObj);
            long size = myObj.length();    //  Array List Size
            int File_Size = (int)size+1;
            ArrayList<Integer> list = new ArrayList<Integer>(File_Size);

            //  Parse inputs
            while (myReader.hasNextInt()) {
                int data = myReader.nextInt();
                list.add(data);
            }

            int Max=1<<31, MaxCnt=0, Min_i=list.size()-1, Max_j=0;
            boolean Index_Not_Seen = true;
            
            //  These two for loops find the max of sum, after these for loops
            //  the Max variable will be the max value of total
            for(int i=0; i<list.size(); i++){
                int sum = 0;
                for(int j=i; j<list.size(); j++){
                    sum += list.get(j);
                    //  Find Max
                    if(sum >= Max){
                        Max = sum;
                    }
                }
            }

            //  These for loops finds the Max Length of subsequences, after
            //  these for loops are done, the MaxLen variable will be the
            //  longest length of these subsequences
            MaxCnt=0;
            int MaxLen=1<<31;
            for(int i=0; i<list.size(); i++){
                int Tmp_Max=1<<31, sum=0;
                for(int j=i; j<list.size(); j++){
                    sum += list.get(j);
                    if(sum == Max){
                        Max = sum;
                        Min_i = i;      //  use index for length
                        Max_j = j;
                        if(Max_j - Min_i > MaxLen){
                            MaxLen = Max_j - Min_i;
                        }
                    }
                }
            }

            //  print out the longest and the largest subsequences
            for(int i=0; i<list.size(); i++){
                int Tmp_Max=1<<31, sum=0;
                for(int j=i; j<list.size(); j++){
                    sum += list.get(j);
                    //  The Max total value
                    if(sum == Max){
                        Min_i = i;
                        Max_j = j;
                        //  The Max value of length
                        if(Max_j - Min_i == MaxLen){
                            for(int idx=Min_i; idx<=Max_j;idx++){
                                System.out.print(list.get(idx)+" ");
                            }
                            System.out.println();
                        }
                    }
                }
            }

            myReader.close();
        }
        catch(FileNotFoundException e) {
            System.out.println("File Open Failure");
            e.printStackTrace();
        }
    }

}
