#include <iostream>

#include "app.h"


int main(int argc, char *argv[])
{

    
    app app;
    if(app.init(argc, argv))
    {
        app.run();
    }


    return 0;
}



