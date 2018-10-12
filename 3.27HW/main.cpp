#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int age;
  double price;
  char category;
  double discount = 0;
  double finalPrice;
  bool error = false;

  cin >> price;
  cin >> age;
  cin >> category;

  if(age>0 && age<=5){      //Checks to see if Age is greater than 0 and less than or equal to 5
    if(category == 'A' || category == 'a'){     //If category is not A or a makes discount 0%
      discount = 0.0;
    }
    else{        //If A or a makes discount 100%
      discount = 1.0;
    }
  }
  else if (age>5 && age<=12) {      //Checks to see if Age is greater than 5 and less than or equal to 12
    if(category == 'B' || category == 'b'){     //If category is not B or b makes discount 0%
      discount = 0.0;
    }
    else{        //If B or b makes discount 50%
      discount = 0.5;
    }
  }
  else if (age>12 && age<=26) {      //Checks to see if Age is greater than 12 and less than or equal to 26
    if(category == 'C' || category == 'c'){     //If category is not C or c makes discount 0%
      discount = 0.0;
    }
    else{        //If C or c makes discount 60%
      discount = 0.6;
    }
  }
  else if (age>26 && age<=60) {      //Checks to see if Age is greater than 26 and less than or equal to 60
    if(category == 'D' || category == 'd'){     //If category is not D or d makes discount 0%
      discount = 0.0;
    }
    else{        //If D or d makes discount 70%
      discount = 0.7;
    }
  }
  else if (age>60) {      //Checks to see if Age is greater than 60
    if(category == 'E' || category == 'e'){     //If category is not E or e makes discount 0%
      discount = 0.0;
    }
    else{        //If E or e makes discount 80%
      discount = 0.8;
    }
  }
  else{
    error = true;
  }

  if(error == false){
    finalPrice  =  price - ( price * discount);

    cout << fixed;
    cout << setprecision(2) << finalPrice ;
  }
  else{
    cout << endl << "Wrong input";
  }

   return 0;
}
