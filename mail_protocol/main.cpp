//
//  main.cpp
//  mail_protocol
//
//  Created by Gabriel Manricks on 1/4/15.
//  Copyright (c) 2015 Gabriel Manricks. All rights reserved.
//

#include <iostream>
#include "mail_inteface.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    MailInterface m("Example.txt");
    m.run();
    return 0;
}