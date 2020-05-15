#include "header.h"

using namespace std;

int main(int argc, char *argv[]){

    // set decimal outputs to 2 decimal places
    cout << setiosflags( ios::fixed | ios::showpoint ) << setprecision( 2 );

    Diamond d1( -5 ), d2( 7, '^' ), d3( 12, 'X', 'O' ), d4( 50 , '$' , 'o');
    cout << "d1 has size = " << d1.GetSize() << " units.\n";
    d1.Draw();
    cout << "\nd2 has size = " << d2.GetSize() << " units.\n";
    d2.Draw();
    cout << "\nd3 has size = " << d3.GetSize() << " units.\n";
    d3.Draw();
    cout << "\nd4 has size = " << d4.GetSize() << " units.\n";
    d4.Draw();

    d1.Shrink(); // demonstrate shrink 
    d2.Shrink();
    d3.Grow(); // and grow 
    d4.Grow();
    cout << "d1 now has size = " << d1.GetSize() << " units.\n"; cout << "d2 now has size = " << d2.GetSize() << " units.\n"; cout << "d3 now has size = " << d3.GetSize() << " units.\n"; cout << "d4 now has size = " << d4.GetSize() << " units.\n";
    // demonstrate perimeter
    cout << "d2 has perimeter = " << d2.Perimeter() << " units.\n"; cout << "d3 has perimeter = " << d3.Perimeter() << " units.\n"; // and area
    cout << "d2 has area = " << d2.Area() << " square units.\n\n"; cout << "d3 has area = " << d3.Area() << " square units.\n\n";
    d1.Draw();
    d1.Grow(); // show that fill character
    cout << "d1 grows:\n"; // appears only when size 
    d1.Draw(); // is at least 3
    d1.Grow();
    cout << "... and grows:\n";
    d1.Draw();
    cout << '\n';
    d1 = d2; // demonstrate the default overload of the
    // assignment operator
    cout << "d1 now has size = " << d1.GetSize() << " units.\n"; 
    d1.Draw();
    // demonstrate the changing of border and fill characters 
    d2.SetBorder('@');
    d2.SetFill('-');
    cout << "d2 now looks like:\n";
    d2.Draw();
    cout << '\n';
    d2.SetBorder('\n'); // illegal border 
    d2.SetFill('\a'); // illegal fill
    cout << "d2 now looks like:\n"; 
    d2.Draw();
    cout << '\n';
    cout << "\nHere is a summary on d3:\n"; // demonstrate summary 
    d3.Summary();






    /* Diamond d0(4), d1(10), d2(20, '%'), d3(30, '@', '-'), d4(-1), d5(100), d6(2); */
    /* Diamond d7(5); */
    

    /* d0.Summary(); */
    /* d0.Draw(); */
    /* d0.Shrink(); */
    /* d0.Shrink(); */
    /* d0.Shrink(); */
    /* d0.SetBorder('@'); */
    /* d0.SetFill('-'); */
    /* d0.Draw(); */

    /* d1.info(); */
    /* d2.info(); */
    /* d3.info(); */
    /* d4.info(); */
    /* d5.info(); */
    /* d6.info(); */
    /* d7.info(); */

    return 0;
}
