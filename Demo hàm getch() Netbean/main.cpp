/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: haith
 *
 * Created on February 24, 2020, 8:01 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

using namespace std;

/*
 * 
 */
int getch(){

    int                 ret;
    struct termios      back;
    struct termios      tmp;
    int fd =            0;      //stdin

    tcgetattr(fd, &back);       // a backup
    tcgetattr(fd, &tmp);

    // code get from man page
    tmp.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
                   | INLCR | IGNCR | ICRNL | IXON);
    tmp.c_oflag &= ~OPOST;
    tmp.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);

    tmp.c_cflag &= ~(CSIZE | PARENB);
    tmp.c_cflag |= CS8;
    // endof man page

    // apply configuration
    tcsetattr(fd, TCSANOW, &tmp);

    ret=getchar();

    // reset back the configuration
    tcsetattr(fd, TCSANOW, &back);

    return ret;
}

int main(int argc, char** argv) {
    
    char ch=getch();
    if (ch==27)
        printf("Press esc");
    else
        printf("Press other key");
        
    return 0;
}

