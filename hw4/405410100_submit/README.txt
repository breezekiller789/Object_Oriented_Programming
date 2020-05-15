1、Part A

    基本上就都按照spec上的要求做一遍，default constructor, copy constructor, 

    destructor，都有做，default constructor分成有傳參數跟沒有傳參數的版本，有

    傳參數就直接使用參數來當作預設，若不給參數我就都預設給0，然後copy constructor

    就是把傳進來的constructor的屬性都抄一份，destructor我就只有印東西而已，沒有

    做事情。

2、Part B

   這部分比較複雜一點，首先linked list部分，有兩個class，一個是ListNode一個是

   LinkedList，前面的是來存每一個節點的資料的，後面是拿來做insert, delete, print

   等等功能的class，當LinkedList物件一被呼叫，我會先將一個ListNode做初始化（

   Default constructor），把first指向一個節點，該節點的資料都是零，且next是NULL

   ，完全按照作業spec中的要求去做，當然這是不傳任何參數的情況下，spec中有提到

   呼叫Constructor的方式，我也就照樣的去做，如果將*c, *e, num傳給default constructor

   ，我會先呼叫add()，add()也就是直接呼叫insert的function，我insert的方法是

   insert at tail，每一次insert就是從頭開始往下掃，假如exponential一樣，就把

   coef加上去然後return，如果掃到最後了，代表這筆資料要insert，就insert進去，

   然後再來是微分，微分滿簡單的就是指數乘以係數之後把指數減一，然後從頭到尾做

   一次就結束。

   我除了spec要求的，還有多做了滿多function，我有做insert at front, delete,

   clear list, print list等等function，若助教有興趣可以玩看看^^，然後一樣我有

   提供tags檔案，助教可以在vim裡頭用:tag <function_name>來trace code。

備註：

    我把part A, B兩個部分的程式碼全部都寫在同一個header.h和func.cpp裡面，個別

    都有標示哪一部分code block是part A哪一部分是part B，main.cpp也有我預設好的

    part A和part B，都被註解起來，若助教想測試我的可以直接把註解拿掉，make一次

    就會全部都compile完成。

