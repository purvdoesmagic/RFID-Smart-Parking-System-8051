#include <reg51.h>

//---------------- PIN CONFIG ----------------//
#define LCD P1

sbit doorp = P2^0;
sbit doorn = P2^1;

sbit rs = P2^5;
sbit rw = P2^6;
sbit en = P2^7;

//---------------- GLOBAL ----------------//
unsigned char rfid[11];
unsigned char i;

int slots[5] = {0,0,0,0,0};
int user_slots[6] = {-1,-1,-1,-1,-1,-1};

//---------------- DELAY ----------------//
void delay()
{
    unsigned int i,j;
    for(i=0;i<50;i++)
        for(j=0;j<200;j++);
}

//---------------- UART ----------------//
void tx(unsigned char c)
{
    SBUF = c;
    while(TI==0);
    TI = 0;
}

void tx_string(char *s)
{
    while(*s)
        tx(*s++);
}

//---------------- LCD ----------------//
void lcdcmd(unsigned char val)
{
    LCD = val;
    rs = 0;
    rw = 0;
    en = 1;
    delay();
    en = 0;
}

void lcddat(unsigned char val)
{
    LCD = val;
    rs = 1;
    rw = 0;
    en = 1;
    delay();
    en = 0;
}

void lcddis(char *s)
{
    while(*s)
        lcddat(*s++);
}

void lcd_init()
{
    lcdcmd(0x38);
    lcdcmd(0x0C);
    lcdcmd(0x01);
    lcdcmd(0x80);
}

//---------------- UART INIT ----------------//
void serial_init()
{
    SCON = 0x50;
    TMOD = 0x20;
    TH1 = -3;
    TR1 = 1;
}

//---------------- READ RFID ----------------//
void read_rfid()
{
    i = 0;

    while(i < 11)
    {
        while(RI == 0);

        if(SBUF != '\r' && SBUF != '\n')
        {
            rfid[i] = SBUF;
            tx(SBUF);
            i++;
        }

        RI = 0;
    }
}

//---------------- MATCH ----------------//
bit match(char *id)
{
    unsigned char j;
    for(j=0;j<11;j++)
        if(rfid[j] != id[j]) return 0;
    return 1;
}

//---------------- SLOT ----------------//
int get_slot()
{
    unsigned char j;
    for(j=0;j<5;j++)   // ? only 5 slots
    {
        if(slots[j]==0)
        {
            slots[j]=1;
            return j;
        }
    }
    return -1;
}

void free_slot(int s)
{
    if(s>=0 && s<5)
        slots[s]=0;
}

//---------------- DOOR ----------------//
void open_door()
{
    doorp = 1;
    doorn = 0;
    delay();

    doorp = 0;
    doorn = 1;
    delay();

    doorp = 0;
    doorn = 0;
}

//---------------- DENY ----------------//
void deny()
{
    lcdcmd(0x01);
    lcddis("INVALID USER");
    tx_string("\r\nINVALID USER\r\n");
    delay();
}

//---------------- CHECK ----------------//
void check()
{
    int user_index = -1;
    int s;

    if(match("16014024013")) user_index = 0;
    else if(match("16014024014")) user_index = 1;
    else if(match("16014024015")) user_index = 2;
    else if(match("16014024016")) user_index = 3;
    else if(match("16014024017")) user_index = 4;
    else if(match("16014024018")) user_index = 5;

    if(user_index == -1)
    {
        deny();
        return;
    }

    // EXIT
    if(user_slots[user_index] != -1)
    {
        free_slot(user_slots[user_index]);
        user_slots[user_index] = -1;

        lcdcmd(0x01);
        lcddis("EXIT");

        tx_string("\r\nEXIT\r\n");
        delay();
        return;
    }

    // ENTRY
    s = get_slot();

    if(s == -1)
    {
        lcdcmd(0x01);
        lcddis("PARKING FULL");
        tx_string("\r\nPARKING FULL\r\n");
        delay();
        return;
    }

    user_slots[user_index] = s;

    lcdcmd(0x01);

    if(user_index==0) lcddis("KAUSHIKI");
    else if(user_index==1) lcddis("CHAITANYAA");
    else if(user_index==2) lcddis("VEDANTI");
    else if(user_index==3) lcddis("PURV");
    else if(user_index==4) lcddis("UKSHAAN");
    else if(user_index==5) lcddis("MANAS");

    lcdcmd(0xC0);
    lcddat('S'); lcddat('L'); lcddat('O'); lcddat('T'); lcddat(':');
    lcddat(s + '1');

    tx_string("\r\nSLOT ");
    tx(s + '1');
    tx_string("\r\n");

    open_door();
}

//---------------- MAIN ----------------//
void main()
{
    serial_init();
    lcd_init();

    tx_string("SMART PARKING READY\r\n");

    while(1)
    {
        lcdcmd(0x01);
        lcddis("ENTER ID");

        tx_string("\r\nEnter ID:\r\n");

        read_rfid();
        check();
    }
}