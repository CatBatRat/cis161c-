#include <iostream>
#include <limits>


using namespace std;

// this will find the area of the rectangle if the user picks rectangle. it takes 2 variables defined from int main and names them lengh and width respectivly and then does the calulation and returns answer.
float rectangleArea(float length, float width)
{
    float answer = length * width;
 return answer;
}

// this will find the area of the circle if the user picks circle. it takes 1 variable defined from int main and names it radius and then does the calulation and returns answer.
float circleArea(float radius)
{
    const float PI = 3.14159;
    float answer = radius * radius * PI;
return answer;
}

// this will find the area of the triangle if the user picks triangle. it takes 2 variables defined from int main and names them height and width respectivly and then does the calulation and returns answer.
float triangleArea(float height, float width)
{
    float answer = height * width * 0.5;
return answer;
}

// this will find the area of the square if the user picks square. it takes 1 variable defined from int main and names it width and then does the calulation and returns answer.
float squareArea(float width)
{
    float answer = width * width;
return answer;
}




int main()
    {
        bool cont = true;

        float num1, num2, area; // this is defining 2 variables that can be used in the return of any of the calulations.
        char choice; //this is for the switch statement for the user to choose what shape they want to do.
        string shape;

        while (cont)
        {
        cout << "Please enter the first letter of the shape you want the area for." << endl;
        cout << "R for rectangle." << endl << "C for circle." << endl << "T for triangle." << endl << "S for square." << endl;
        cin >> choice;

        switch (choice)
        {
          case 'R': //for rectangle
          case 'r':
              cout << "Enter length: ";
              cin >> num1;
              cout << "Enter width: ";
              cin >> num2;
              area = rectangleArea(num1, num2); //this takes the user entered info from num1 and num2 and sends it to the function which then sets them respectivly to length and width to be used there. sends back the answer.
              shape = "rectangle";
            break;
          case 'C': //for circle
          case 'c':
              cout << "Enter radius: ";
              cin >> num1;
              area = circleArea(num1); //this takes the user entered info from num1 and sends it to the function which then sets it respectivly to radius to be used there. sends back the answer.
              shape = "circle";
            break;
          case 'T': //for triangle
          case 't':
              cout << "Enter height: ";
              cin >> num1;
              cout << "Enter width: ";
              cin >> num2;
              area = triangleArea(num1, num2); //this takes the user entered info from num1 and num2 and sends it to the function which then sets it respectivly to height and width to be used there. sends back the answer.
              shape = "triangle";
            break;
             case 'S': //for square
             case 's':
              cout << "Enter length or height: ";
              cin >> num1;
              area = squareArea(num1); //this takes the user entered info from num1 and sends it to the function which then sets it respectivly to width to be used there. sends back the answer.
              shape = "square";
            break;

          default:
              cout << "That choice is not valid.";

        }
    if (shape == "triangle" or shape == "rectangle" or shape == "circle" or shape == "square")
        cout << "The area of your specified " << shape << " equals " << area << "." <<endl;


        cout << endl << endl;
        cout << "Try again?" << endl << "1 for yes" << endl << "0 for no" << endl;
        cin >> cont;
        cout << "***********************************" << endl;
        }
      return 0;
    }
