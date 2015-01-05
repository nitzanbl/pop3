//
//  mail_inteface.h
//  mail_protocol
//
//  Created by Gabriel Manricks on 1/4/15.
//  Copyright (c) 2015 Gabriel Manricks. All rights reserved.
//

#ifndef __mail_protocol__mail_inteface__
#define __mail_protocol__mail_inteface__

#include <stdio.h>
#include "pop3_adaptor.h"
#include "str.h"

class MailInterface
{
    Pop3Adaptor pop3;
    
public:
    
    MailInterface(const char* file_name);
    void run();
    ~MailInterface();
};


#endif /* defined(__mail_protocol__mail_inteface__) */
