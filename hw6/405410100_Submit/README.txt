1 . 編譯方式和刪除object file, executable file

    $make

    $make clean

2 . 執行方式

    $./hw6.exe <input_file> <output_file>

3 . 程式說明
    
    在main.cpp裡頭我一開始就檢查argument對不對，要執行程式必須要附上input檔名和

    output檔名，如果沒有附的話我會印錯誤訊息，然後再印使用說明，最後直接exit()

    ，exit code我給1，再來就開始做正式的事情，詳細的註解都在程式碼裡頭，這邊就

    不寫了。

4 . Trace Code

    我有附上tags檔案，方便助教在trace code的時候可以穿梭自如，在vim裡頭，想要

    看function definition的話，直接輸入:tag <function_name>，打入function_name

    的時候，可以按tab來autocomplete。

5 . 備註

    這次作業一開始有要做input的parsing，因為做parsing已經養成使用C的方式來做了

    ，所以前面做Parsing的時候，寫起來很像C code，大量使用string.h。



