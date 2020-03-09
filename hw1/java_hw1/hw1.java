/*
 * OOP_HW1 :
 *      在command line編譯完程式之後$java hw1，後面加上字串，程式會把這些字串
 *      的出現次數印出來
 */
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

        int len = args.length, i=0;
        // System.out.println(len);
        // System.out.println(args[0]);
        // System.out.println(args[0].charAt(2));
        // String str = Character.toString(y);
        
        while(i<len){
            int j=0;
            while(j<args[i].length()){
                char y = args[i].charAt(j);
                String str = Character.toString(y);
                list.add(str);
                j++;
            }
            i++;
        }

        /*
         * 若要從stdin讀入就把下面這段註解打開，且把上面while迴圈註解掉
         */
        // int ch;
        // while ((ch = System.in.read()) != -1)
        // {
        //     if (ch != '\n' && ch != '\r')
        //     {
        //         String ptr = String.format("%c", ch);
        //         list.add(ptr);
        //         // System.out.println((char)ch);
        //     }
        // }


        /*
         * 把結果從linked list中印出來
         */
        String x;
        int size = list.size();
        while(size > 0){
            x = list.pop();     //  把最前面的字元pop出來
            if(x == null)       //  如果pop出來是null代表沒有東西了，直接break
                break;
            int cnt=1, position;
            while((position = list.indexOf(x)) != -1){    //  依照剛剛拿出來的字元，去看看list裡面有沒有一樣的字元，若有的話
                list.remove(position);                    //  list.indexOf會回傳位置，再用list.remove()去把那個節點刪掉，然 
                cnt++;                                    //  cnt加一，這樣就可以知道有幾個一樣的字元。                     
            }
            size -= cnt;
            System.out.println(x+"-"+cnt);
        }
   }
}
