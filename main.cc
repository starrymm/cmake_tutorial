#include <iostream>
#include <cmath>
#include "TutorialConfig.h"


#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

using namespace std;
int main(int argc, char **argv) {
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
                << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    
    #ifdef USE_MYMATH
        const double outvalue = getSquare(9);
    #else
        const double outvalue = sqrt(3);
    #endif
    cout << "output is : " << outvalue << endl;    
    return 0 ;
}
