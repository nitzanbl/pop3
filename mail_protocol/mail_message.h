//
//  mail_message.h
//  mail_protocol
//
//  Created by Gabriel Manricks on 1/4/15.
//  Copyright (c) 2015 Gabriel Manricks. All rights reserved.
//

#ifndef __mail_protocol__mail_message__
#define __mail_protocol__mail_message__

#include <iostream>
#include "str.h"
#include "datetime.h"

class MailMessage
{
    int _id;
    Str _from;
    Str _to;
    DateTime _mailtime;
    Str _data;
    int _size;
    
public:
    
    MailMessage();
    MailMessage(int id , Str from , Str to , DateTime d , Str data , int size);
    MailMessage(const MailMessage& m);
    MailMessage( Str& st);
    
    MailMessage& operator= (const MailMessage& m);
    void print_mailmessage();
    
    int get_id();
    int get_size();
    const Str &get_from();
    const Str &get_to();
    const Str &get_data();
    const DateTime &get_date();
    
    ~MailMessage();
    
};


#endif /* defined(__mail_protocol__mail_message__) */
