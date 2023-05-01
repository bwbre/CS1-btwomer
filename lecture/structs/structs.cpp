/*
Brendan Womer 
4/11/2023
structs -- 2nd most important thing from this course, after ptrs

*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

/*
STRUCTS:
    -Structs are capitalized
    -a block of memory with two addresses.. the two addresses are next to one anothers each memory block.
    -templates can be used. call before the struct like normal and replace all the data types to the desired <TYPE>
*/

struct Rectangle {
/*The order you call the struct is sequential. with an array it goes in order from top to bottom. starting from array[0, 1, ..]*/
    float side1;
    float side2;
    float area;
    float perimeter;

    /*3 extra bytes padding at end because char 
    the order matters and the padding can change depending on type of data types used and/or compiler/computer/microcontroller/etc..
    */

} ;

/*Prototypes come after struct*/
void getSides(Rectangle&);
void calcArea(Rectangle&);
void calcPerim(Rectangle&);
void printValue(Rectangle&);


int main(int argv, char* argc[]) {
    Rectangle *rect1 = new Rectangle();
    // Rectangle *rect2;


/*using struct ptr with heap... -> is used to reference allllll the way back to the struct. */
    // rect1->side1 = 40;
    // rect1->side2 = 10;
    // rect1->area = rect1->side1 * rect1->side2;
    // rect1->perimeter = (rect1->side1*2)+(rect1->side2*2);
    //
    // cout << "rectangle with with sides: " << "\nside1: " << rect1->side1 << "\nside2: " << rect1->side2 << endl <<
    //     " \n  Area: " << rect1->area << 
    //     " \n  perim: " << rect1->perimeter << endl;


    delete rect1;



    return 0;
}

void getSides(Rectangle& rect){
    cout << "Please enter side1: ";
    cin >> rect.side1;

    cout << "\nplease enter side2: ";
    cin >> rect.side2;
}
void calcArea(Rectangle& rect){
    rect.area = rect.side1 * rect.side2;
}
void calcPerim(Rectangle& rect){
    rect.perimeter = (2 * rect.side1) + (2 * rect.side2);
}
void printValue(Rectangle& rect){
    cout << "rectangle with with sides: " << "\nside1: " << rect.side1 << "\nside2: " << rect.side2 << endl <<
        " \n  Area: " << rect.area << 
        " \n  perim: " << rect.perimeter << endl;
}

/*using structs */
//int main(int argv, char* argc[]) {
    // Rectangle rectangles[5] = {0,0,0,0,0};
    // // Rectangle rect1;
    //
    // getSides(rectangles[i]);
    // calcArea(rectangles[i]);
    // calcPerim(rectangles[i]);
    // cout << endl << "Your calculate rectangles are: " << endl;
    // for (int i = 0; i < 5; i++) {
    //     printValue(rectangles[i]);
    // }
    //return0;
//}



// int main(int argv, char* argc[]) {
//     Rectangle rectangles[5] = {0,0,0,0,0};
//     // Rectangle rect1;
//     // vector<Rectangle> rectangles;

//     for (int i = 0; i < 5; i++){
        
//         getSides(rectangles[i]);
//         calcArea(rectangles[i]);
//         calcPerim(rectangles[i]);
//         // rectangles.push_back(rect1);
//     }

//     cout << endl << "Your calculate rectangles are: " << endl;
//     for (int i = 0; i < 5; i++) {
//         printValue(rectangles[i]);
//     }

//     return 0;
// }

// void getSides(Rectangle& rect){
//     cout << "Please enter side1: ";
//     cin >> rect.side1;

//     cout << "\nplease enter side2: ";
//     cin >> rect.side2;
// }
// void calcArea(Rectangle& rect){
//     rect.area = rect.side1 * rect.side2;
// }
// void calcPerim(Rectangle& rect){
//     rect.perimeter = (2 * rect.side1) + (2 * rect.side2);
// }
// void printValue(Rectangle& rect){
    // cout << "rectangle with with sides: " << "\nside1: " << rect.side1 << "\nside2: " << rect.side2 << endl <<
    //     " \n  Area: " << rect.area << 
    //     " \n  perim: " << rect.perimeter << endl;
// }








// inefficient
// int main(int argc, char* argv[]) {
//     Rectangle rect1;
//     Rectangle rect2;

//     getSides(rect1);
//     calcArea(rect1);
//     calcPerim(rect1);
//     printValue(rect1);

//     getSides(rect2);
//     calcArea(rect2);
//     calcPerim(rect2);
//     printValue(rect2);

//     return 0;
// }






// /*Structs are capitalized
// a block of memory with two addresses.. the two addresses are next to one anothers
// each memory block */
// struct Rectangle {
//     float side1, side2;
//     float area;
//     float perimeter;

//     /*3 extra bytes padding at end because char 
//     the order matters and the padding can change depending on type of data types used and/or compiler/computer/microcontroller/etc..
//     */

// } ;

// /*Prototypes come after struct*/
// void getSides(Rectangle);
// void calcArea(Rectangle);
// void calcPerim(Rectangle);
// void printValue(Rectangle);


// int main(int argc, char* argv[]) {
//     Rectangle rect1;
//     Rectangle rect2;

//     getSides(rect1);
//     calcArea(rect1);
//     calcPerim(rect1);
//     printValue(rect1);

//     getSides(rect2);
//     calcArea(rect2);
//     calcPerim(rect2);
//     printValue(rect2);

//     return 0;
// }

// void getSides(Rectangle& rect){
//     cout << "Please enter side1: ";
//     cin >> rect.side1;

//     cout << "\nplease enter side2: ";
//     cin >> rect.side2;
// }
// void calcArea(Rectangle& rect){
//     rect.area = rect.side1 * rect.side2;
// }
// void calcPerim(Rectangle& rect){
//     rect.perimeter = (2 * rect.side1) + (2 * rect.side2);
// }
// void printValue(Rectangle& rect){
//     cout << "rectangle with with sides: " << rect.side1 << "\nside2: " << rect.side2 <<
//         " \n  Area: " << rect.area << 
//         " \n  perim: " << rect.perimeter << endl;
// }

// /*Structs are capitalized
// a block of memory with two addresses.. the two addresses are next to one anothers
// each memory block */
// struct Rectangle {
//     float side1, side2;
//     float area;
//     float perimeter;

//     /*3 extra bytes padding at end because char 
//     the order matters and the padding can change depending on type of data types used and/or compiler/computer/microcontroller/etc..
//     */
// } ;
// /*Prototypes come after struct*/
// void getSides(Rectangle);
// void calcArea(Rectangle);
// void calcPerim(Rectangle);
// void printValue(Rectangle);
// int main(int argc, char* argv[]) {
//     Rectangle rect1;
//     Rectangle rect2;
//     getSides(rect1);
//     calcArea(rect1);
//     calcPerim(rect1);
//     printValue(rect1);
//     getSides(rect2);
//     calcArea(rect2);
//     calcPerim(rect2);
//     printValue(rect2);
//     return 0;
// }
// void getSides(Rectangle& rect){
//     cout << "Please enter side1: ";
//     cin >> rect.side1;
//
//     cout << "\nplease enter side2: ";
//     cin >> rect.side2;
// }
// void calcArea(Rectangle& rect){
//     rect.area = rect.side1 * rect.side2;
// }
// void calcPerim(Rectangle& rect){
//     rect.perimeter = (2 * rect.side1) + (2 * rect.side2);
// }
// void printValue(Rectangle& rect){
//     cout << "rectangle with with sides: " << rect.side1 << "\nside2: " << rect.side2 <<
//         " \n  Area: " << rect.area << 
//         " \n  perim: " << rect.perimeter << endl;
// }



// /*Structs are capitalized
// a block of memory with two addresses.. the two addresses are next to one anothers
// each memory block */
// struct Point {
//     int x;
//     int y;
//     float num4;
//     int a;
//     char apple;
//     int z;
//     long newlong;
//     string firstname;
//     /*3 extra bytes padding at end because char 
//     the order matters and the padding can change depending on type of data types used and/or compiler/computer/microcontroller/etc..
//     */

// };
// int main(int argc, char* argv[]) {
//     Point point1;
//     Point point2;


//     cout << "sizeof(point1): " << sizeof(point1) << endl;
//     cout << "sizeof(point2): " << sizeof(point2) << "\n" << endl;

//     // 
//     // cout << "&point1: " << &point1 << endl;
//     // cout << "&point1.x" << &point1.x << endl;
//     // cout << "&point1.y" << &point1.y << endl;
//     // cout << "&point1.z" << &point1.z << endl;
//     // cout << "&point1.a" << &point1.a << "\n" << endl;

//     // cout << "&point2: " << &point2 <<  endl;
//     // cout << "&point2.x" << &point2.x << endl;
//     // cout << "&point2.y" << &point2.y << endl;
//     // cout << "&point2.z" << &point2.z << endl;
//     // cout << "&point2.a" << &point2.a << endl;


//     return 0;
// }



// /*Structs are capitalized
// a block of memory with two addresses.. the two addresses are next to one anothers
// each memory block */
// struct Point {
//     int x;
//     int y;
//     /*extra bytes padding at end
//     the order matters and the padding can change depending on type of data types used and/or compiler/computer/microcontroller/etc..
//     */
// int main(int argc, char* argv[]) {
//     Point point1;
//     Point point2;

//     /* point1.y  -- use the . modifier similar to strings.*/
//     point1.x = 0;
//     point2.y = 0;

//     point2.x = 5;
//     point2.y = 5;

//     printf("(%d, %d) and (%d, %d) \n", point1.x, point1.y, point2.x, point2.y);

//     distance = sqrt(pow(point1.x - point2.x) + pow(point1.y - point2.y));

//     printf("the distance between the two lines is: %f", distance);

//     return 0;
// }
