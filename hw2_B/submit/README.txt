1 . 如何編譯、執行

    cpp_hw2B :
                $make
                $./hw2_B.exe
    java_hw2B:
                $javac Largest_Subsequence.java
                $java Largest_Subsequence

2 . 吃input方法

    cpp_hw2B    :
                
                在main.cpp裡頭，第6, 7行在讀檔的，把檔案改成想要測試的檔案路徑

                就可以，兩行都要改，第7行用open是因為要使用lseek來取得檔案大小

                要用的，fopen是用來吃檔案資料的。

    java_hw2B   :
                
                在12行檔案路徑改成想要測試的測資路徑就可以。

    備註        :

                若有重新修改，要重新編譯才會正常執行。

3 . 測資
    
    cpp或者java我都有自己想一些測資來測試，就在Input_Files裡面。

4 . 如何trace code

    我有準備tag file，可以方便用來trace code，使用方法就是使用vim，先從main.cpp

    開始，當遇到function的時候，就打入:tag <function name>，在打function name的

    時候，可以用tab來自動完成(autocomplete)，打完之後vim會直接跳進那個function

    被定義的檔案而且游標會停在該function，打入<C-o>可以回去上一個來的地方（他

    可以一直跳來跳去，<C-o>就是pop stack的意思，但是這個只有在cpp_hw2B才有，

    java版本我就沒有提供了(因為都寫在main裡面)。

5 . Bonus
    
    我的實作方法是重複的走這個list，因為我的直覺作法就這樣，我是每一次都兩層for

    ，upper bound就是list size，這樣就是O(k*n^2)，因為我多次掃瞄，所以前面會有一

    個係數k，但是big-O不看前面係數，所以還是O(n^2)。

6 . 備註

    cpp_hw2B    :
                
                如果測資超級大的話，會導致stack overflow，因為讀檔是用遞迴方式

                來讀檔，stack一直堆上去就會爆炸，目前不知道怎麼解這個問題，但是

                我查了一下發現，程式一開始stack多大這個無從得知，所以有點頭痛。

                我的Input_Files裡面有一個叫做violent1.txt的測資，大小是1.4M，吃

                這個測資的話程式就會seg fault，在我的機器上跑大概堆到130000層的

                時候會爆掉，這次作業我也第一次使用lseek()來拿檔案大小，因為如果

                預設給一個值得話，萬一測資超過，就直接掛了。

    java_hw2B   :
                
                我是使用ArrayList來實作陣列，比較簡單，雖然c++可以用vector，但是

                礙於作業spec必須使用circular linked list，所以就只好用刻的，然後

                array list大小跟cpp版本一樣，先去拿檔案大小，再用這個大小去分配

                記憶體。

