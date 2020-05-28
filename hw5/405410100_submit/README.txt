1 . 編譯方式和刪除object file, executable file

    $make

    $make clean

2 . 執行方式

    $./hw5.exe

3 . 程式說明

    我預設的main是用公開測資下去改的，因為原始有一點點錯誤，所以有做一些修正，

    我也有將標頭檔和函式實作分開寫，更詳細、細節的程式流程我有很仔細的寫在func.cpp

    裡面，因為寫起來會太多，這邊就不寫了，投影片和spec中要求的我都有做，特別的是

    ==和!=還有+和-，我都有支援物件和一個整數做運算，不單單可以物件和物件運算，

    也可以使用類似1+2+obj，if(obj1 == 1), if(1 == obj1)等等。

4 . 追蹤程式碼

    我有附上tags檔案，方便助教在trace code的時候可以穿梭自如，在vim裡頭，想要

    看function definition的話，直接輸入:tag <function_name>，打入function_name

    的時候，可以按tab來autocomplete。
