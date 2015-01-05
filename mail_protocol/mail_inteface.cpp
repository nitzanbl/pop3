//
//  mail_inteface.cpp
//  mail_protocol
//
//  Created by Gabriel Manricks on 1/4/15.
//  Copyright (c) 2015 Gabriel Manricks. All rights reserved.
//

#include "mail_inteface.h"

using namespace std;

MailInterface::MailInterface(const char* file_name) : pop3(file_name)
{
    cout << "CTOR for MailInterface" << endl ;
}

void MailInterface::run()
{
    while( true ){
    cout <<  " plese enter commnd number : " << endl ;
    cout << " 1 -  Authenticate " << endl ;
    cout <<  "2 - Get Mail Status" << endl ;
    cout <<  "3 - Get Mails List " << endl ;
    cout << "4 - Get One Mail " << endl ;
    cout <<  "5 - Delete mail " << endl ;
    cout << "6 - RSET " << endl;
    cout << "7 - Quit " << endl ;
    
    int x;
    cin >> x ;
        switch (x) {
            case 1: {
                char st[30] ;
                cout << " enter user name" << endl;
                cin >> st;
                Str user_status ( pop3.User(st));
                cout << " enter password" << endl;
                cin >> st;
                Str pass_status ( pop3.PASS(st));
                if(pass_status.equals("+OK") && user_status.equals("+OK") )
                    cout << "+OK" << endl;
                else
                {
                    cout<< " invalid user name or password " << endl ;
                    return ;
                }
            }
                break;
            case 2: {
                cout << pop3.STAT() << endl ;
            }
                break;
            case 3: {
                cout << pop3.LIST() << endl;
            }
                break;
            case 4: {
                cout << " enter email id " << endl;
                int y;
                cin >> y;
                cout << pop3.RETR(y) << endl;
            }
                break;
            case 5 : {
                cout << " enter email id " << endl;
                int z;
                cin >> z;
                cout << pop3.DELE(z) << endl ;
            }
                break;
            case 6 : {
                cout << pop3.RSET() << endl ;
            }
                break;
            case 7: {
                cout << pop3.QUIT() << endl ;
            }
                return;
                
        }
    }
}
MailInterface::~MailInterface()
{
    cout << "DTOR for MailInterface" << endl ;

}