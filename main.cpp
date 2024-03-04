#include <iostream>
#include "damierexc.h"

int main()
{
    try{
        DamierExc D(3, 5);
        D.Set(2, -1, 8);    // levée d'exception car -1 n'est pas une coord. admissible
    }
    catch(const std::range_error &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}
