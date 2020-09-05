#include"headerfile.h"

HANDLE wHnd;
HANDLE rHnd;

void gotoxy(int x, int y)
{

    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y; ///* X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void rectangle(int x,int y,int l, int b)
{

    int i,m;

    gotoxy(x,y);
    printf("%c",42);
    for(i=x+1; i<l-1; i++)
    {

        printf("%c",42);
    }
    gotoxy(i,y);
    printf("%c",42);

    for(m=y+1; m<b; m++)
    {
        gotoxy(x,m);
        for(i=x; i<l; i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m);
                printf("%c",42);
            }

        }

    }

    gotoxy(x,m);
    printf("%c",42);
    for(i=x+1; i<l-1; i++)
    {
        gotoxy(i,m);
        printf("%c",42);
    }
    gotoxy(i,m);
    printf("%c",42);
}


void resideConsole(int x,int y)
{

    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle("STUDENT COMMUNITY MANAGEMENT SYSTEM");
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, x, y};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    // Change the console window size:
    // Create a COORD to hold the buffer size:
    COORD bufferSize = {10, 10};
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    // Exitc

}


void frontinterface()
{
    CLEAR_SCREEN;
    int choice;
    int trial=0;
    CLEAR_SCREEN;
    resideConsole(70,150);
    rectangle(4,4,76,20);
    gotoxy(22,3);
    printf("STUDENT COMMUNITY MANAGEMENT SYSTEM");
    gotoxy(10,6);
    puts("\n\n\t1. >>ADMIN");
    gotoxy(10,8);
    puts("\n\n\t2. >>TREASURER");
    gotoxy(10,12);
    printf("choice: ");

    choice=getch()-48;

    if(choice<0 || choice>2)
        frontinterface();
PASSWORD:
    CLEAR_SCREEN;
    if(trial==3)
        frontinterface();
    USER tem = password(choice==1?"\tADMIN AUTHENTICATION":"\tTREASURER AUTHENTICATION");
    if(searchUser(tem,choice))
    {
        switch(choice)
        {

        case 1:
            admininterface();
            break;
        case 2:
            treasurerinterface();

            break;
        }

    }
    else
    {
        // Display Wrong Password
        trial++;
        goto PASSWORD;
    }


}
USER password(char* usertype)
{

    char username[50],password[10];
    char ch;
    int i=0;
    CLEAR_SCREEN;
    resideConsole(70,150);
    rectangle(4,4,76,24);
    gotoxy(5,5);
    printf("\t\t");
    puts(usertype);
    gotoxy(5,6);
    printf("----------------------------------------------------------------------");

    gotoxy(5,8);
    printf("USERNAME:  ");

    gotoxy(5,10);
    printf("PASSWORD:  ");

    gotoxy(15,8);
    scanf("%s",username);

    gotoxy(15,10);

    while(i<10)
    {
        ch=getch();
        if(ch==13)
            break;
        else
        {
            if(ch==8)
            {
                printf("%c",ch);
                printf(" ");
                printf("%c",ch);
                i--;
                if (i<0)
                    i=0;
            }
            else
            {
                printf("*");
                password[i]=ch;
                i++;
            }
        }


    }
    password[i]='\0';
    i=0;
    USER guest;

    strcpy(guest.username,username);
    strcpy(guest.password,password);
    guest.admin = (strcmpi(usertype,"ADMIN AUTHENTICATION")==0 ? true : false);

    return guest;

}

bool searchUser(USER ut, int optionType)
{
    int i=0;
    /**
    * Create a Searching Function to find the correct user
    * using the given parameter below
    * @parameters ut.username && ut.password && ut.admin
    * if the user is found then return true, otherwise return false.
    */
    if(stricmp(ut.username,"charif")==0 && stricmp(ut.password,"charif253")==0 && optionType==1)
    {
        gotoxy(25,15);
        puts("LOGIN IS SUCCESSFUL");
        gotoxy(25,17);
        puts("LOADING PLEASE WAIT.");
        for(i=0; i<3; i++)
        {
            gotoxy(45+i,17);
            printf(".");
            Sleep(500);
        }
        gotoxy(20,20);
        printf("Press any key to continue...");
        getch();//holds the screen
        return true;
    }
    else if(stricmp(ut.username,"user")==0 && stricmp(ut.password,"123")==0 && optionType==2)
    {
        gotoxy(25,15);
        puts("LOGIN IS SUCCESSFUL");
        gotoxy(25,17);
        puts("LOADING PLEASE WAIT.");
        for(i=0; i<3; i++)
        {
            gotoxy(45+i,17);
            printf(".");
            Sleep(500);
        }
        gotoxy(20,20);
        printf("Press any key to continue...");
        getch();//holds the screen
        return true;
    }
    else
    {
        printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
        getch();//holds the screen
        return false;
    }
}

void admininterface()
{
    int choice;

    CLEAR_SCREEN;
    resideConsole(70,150);
    rectangle(4,4,76,25);
    gotoxy(5,5);
    printf("_______________________________WELCOME________________________________");
    puts("\n\n\t 1. ADD MEMBER");
    puts("\n\n\t 2. DELETE MEMBER");
    puts("\n\n\t 3. COMMUNITY MEETING");
    puts("\n\n\t 4.  DISPLAY ");
    puts("\n\n\t 5. SEARCH ID");
    puts("\n\t 6. MAIN MENU ");
    printf("\n\t  CHOICE: ");
    choice=getche()-48;

    switch(choice)
    {

    case 1:
        addMember();
        break;
    case 2:
        deletemember();
        break;
    case 3:
        comm_metngs();
        break;
    case 4:
        displayList();
        break;
    case 5:
        search_member();
    case 6:
        frontinterface();
    }
}
void treasurerinterface()
{
    CLEAR_SCREEN;
    rectangle(4,4,76,20);
    gotoxy(10,5);
    indexing();
}
void addMember()
{

    void print_heading(const char st[])///
    {
        gotoxy(4,4);
        printf("START: %s",st);///

    }
    FILE *fp;
    CLEAR_SCREEN;
    struct student member;
    gotoxy(8,4);
    printf("Add Record");
    int print = 20;
    fp=fopen("member.DAT","ab");
    if(fp==NULL)
    {
        //MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);
        printf("FILE CANNOT OPEN SORRY");
        exit(1);
    }
    else
    {
        resideConsole(70,150);
        rectangle(4,4,76,29);

        //fseek(fp,0,SEEK_END);
        fflush(stdin);
        gotoxy(print,6);
        printf("@Given ID: #");
        strcpy(member.ID,generateID());
        strupr(member.ID);
        puts(member.ID);
        gotoxy(print,8);
        printf("First name: ");
        gets(member.name);
        gotoxy(print,10);
        printf("Least name: ");
        gets(member.fname);
        gotoxy(print,12);
        printf("Gender: ");
        gets(member.gender);
        gotoxy(print,14);
        printf("Email: ");
        gets(member.email);
        gotoxy(print,16);
        printf("Department: ");
        gets(member.dep);
        gotoxy(print,18);
        printf("Program: ");
        gets(member.prog);
        gotoxy(print,20);
        printf("Year of admission: ");
        scanf("%d",&member.admission);
        gotoxy(print,21);
        printf("Expected year of graduation: ");
        scanf("%d",&member.graduation);

        fwrite(&member,sizeof(member),1,fp);
        fclose(fp);
    }
    gotoxy(print,22);
    printf("The record is successfully saved\n");
    gotoxy(print,23);
    printf("Do you wish to new information?(Y / N):");
    char ch=getch();
    if(ch=='n'||ch=='N')
        admininterface();
    else
        system("cls");
    addMember();

    //fprintf(fp,"\nID member: %s\n\nName:%s\nFurther name: %s\nGender: %s\nEm@il: %s\n",member.ID,member.name,member.fname,member.gender,member.email);
    //fprintf(fp,"\nDepartment: %s\nProgram: %s\n",member.dep,member.prog);
    //fprintf(fp,"\nYear of admission: %d\nExpected year of graduation: %d",member.admission,member.graduation);
}
void deletemember()
{

    void print_heading(const char st[])///
    {
        //SetColorAndBackground(30,27);
        gotoxy(15,8);
        printf("START: %s",st);///
        //SetColorAndBackground(17,15);
    }

    CLEAR_SCREEN;
    rectangle(4,4,76,29);

    print_heading("Delete Record");
    struct student member ;
    char m_id[50];
    //int isFound = 0, print = 37;

    gotoxy(15,10);
    printf("Enter ID to delete:  ");
    fflush(stdin);
    gets(m_id);
    FILE *fp, *temp;
    fp = fopen("member.DAT","rb");
    temp = fopen("alumni.DAT","wb");
    bool found = false;
    while(fread(&member, sizeof(member),1,fp) == 1)
    {
        if(stricmp(m_id, member.ID)!=0)
        {
            fwrite(&member,sizeof(member),1,temp);
        }
        else
        {
            found = true;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("member.DAT");
    rename("alumni.DAT","member.DAT");
    if(found)
    {
        gotoxy(20,12);
        printf("The record is successfully deleted\n");
        gotoxy(24,13);
        printf("Do you wish to new information?(Y / N):");
        char ch=getch();
        if(ch=='n'||ch=='N')
            admininterface();
        else
            deletemember();
    }
    else
    {
        gotoxy(15,13);
        printf("SORRY!!!!! NO MEMBER IS AVAILABLE.");
        gotoxy(10,15);
        printf(" PRESS ENTER TO RETRY OR ANYOTHER KEY TO RETURN: ");
        if(getch()==13)
            deletemember();
        else
            admininterface();
    }
    //SetColor(28);
}
void search_member()
{
    void print_heading(const char st[])///
    {
        //SetColorAndBackground(30,27);
        gotoxy(20,5);
        printf("%s",st);///
        //SetColorAndBackground(17,15);
    }
    CLEAR_SCREEN;
    rectangle(4,4,76,29);
    print_heading("____________SEARCH ID_____________ ");

    char m_id[15];
    int isFound = 0;
    gotoxy(27,7);
    printf("Enter ID to Search: ");
    fflush(stdin);
    gets(m_id);
    FILE *fp = NULL;
    fp = fopen("member.DAT","rb");
    while(fread(&member,sizeof(member),1,fp) == 1)
    {
        if(stricmp(m_id,member.ID) == 0)
        {
            isFound = 1;
            break;
        }
    }
    fclose(fp);
    if(isFound == 1)
    {
        gotoxy(37,9);printf("your data is found: ");
        gotoxy(37,10);printf("ID: %s",member.ID);
        gotoxy(37,11);printf("First Name: %s",member.name);
        gotoxy(37,12);printf("Last name: %s",member.fname);
        gotoxy(37,13);printf("Gender : %s",member.gender);
        gotoxy(37,14);printf("Em@il: %s",member.email);
        gotoxy(37,15);printf("Department: %s",member.dep);
        gotoxy(37,16);printf("Program: %s",member.prog);
        gotoxy(37,17);printf("Year of admission: %d",member.admission);
        gotoxy(37,18);printf("Expected year of graduation: %d",member.graduation);


         gotoxy(37,20);printf("Press ENTER to return ");
        if(getch()==13)
            admininterface();
    }
    else
    {
        gotoxy(7,12);printf("SORRY!!!!! NO MEMBER IS AVAILABLE. ");
        gotoxy(5,14);printf(" PRESS ENTER TO RETRY OR ANYOTHER KEY TO RETURN: ");
        if(getch()==13)
            search_member();
        else
            admininterface();
    }
}
void meeting()
{
    CLEAR_SCREEN;
    fp=fopen("minutes.DAT","ab+");
    if(minutes_input()==1)
    {
        fseek(fp,0,SEEK_END);
        fwrite(&met_min,sizeof(met_min),1,fp);
        fclose(fp);
        gotoxy(10,15);printf("The record is successfully saved\n");
        gotoxy(10,17);printf("Do you wish to new information?(Y / N):");
        if(getch()=='n')
            comm_metngs();
        else
            meeting();
    }
}

void achievement()
{
    CLEAR_SCREEN;
    fs=fopen("achievements.DAT","ab+");
    if(arch_input()==1)
    {
        fseek(fs,0,SEEK_END);
        fwrite(&comm_ach,sizeof(comm_ach),1,fs);
        fclose(fs);
        gotoxy(10,18);printf("The record is successfully saved\n");
        gotoxy(10,19);printf("Do you wish to new information?(Y / N):");
        if(getch()=='n')
            comm_metngs();
        else
            achievement();
    }
}
void view_minutes()
{

    CLEAR_SCREEN;
    rectangle(4,4,100,25);
    gotoxy(5,5);
    printf("_______________________________Community Minutes and timestamps_______________________________");
    gotoxy(8,7);
    printf("*Date of the Meetings**************Minutes of the corresponding Meeting******************\n");
    fp=fopen("minutes.DAT","rb");
    int i=0;
    while(fread(&met_min,sizeof(met_min),1,fp)==1)
    {
        gotoxy(7,9+i);
        printf("%s %s %d",met_min.met_date.day,met_min.met_date.month,met_min.met_date.year);
        gotoxy(60,9+i);
        printf("%s",met_min.minutes);
        printf("\n\n");
        i++;
    }
    fclose(fp);
    gotoxy(10,24);////how to put enter at the end
    printf(" Press ENTER to return ");
    if(getch()==13)
        comm_metngs();

}
void view_achieve()
{
    CLEAR_SCREEN;
    rectangle(4,4,100,25);
    gotoxy(5,5);
    printf("_________________________Community Achievements and timestamps________________________________");
    gotoxy(8,7);
    printf("*Date of the Achievement***********Description of the corresponding achievement**********\n");
    fs=fopen("achievements.DAT","rb");
    int i=0;
    while(fread(&comm_ach,sizeof(comm_ach),1,fs)==1)
    {
        gotoxy(7,9+i);//////how to arrange the display in order

        printf("%s %s %d ",comm_ach.arch_date.day,comm_ach.arch_date.month,comm_ach.arch_date.year);
        gotoxy(50,9+i);
        printf("%s",comm_ach.description);
        printf("\n\n");
        i++;
    }
    fclose(fs);
    gotoxy(10,24);/////how to put at the end
    printf(" Press ENTER to return ");
    if(getch()==13)
        comm_metngs();

}
int minutes_input()
{


    CLEAR_SCREEN;
    rectangle(4,4,76,29);
    gotoxy(5,5);
    puts("__________________________Minutes Inputing____________________________");
    gotoxy(10,8);
    puts(" Enter date of the meeting in the format (1st january 2020): ");
    gotoxy(10,9);
    scanf("%s %s %d",met_min.met_date.day,met_min.met_date.month,&met_min.met_date.year);
    fflush(stdin);
    gotoxy(10,11);
    printf(" Please input the minutes of the meeting: ");
    gotoxy(55,11);
    gets(met_min.minutes);
    return 1;
}
int arch_input()
{
    system("cls");
    rectangle(4,4,76,29);
    gotoxy(5,5);
    puts("_______________________Achievement Inputing___________________________");
    gotoxy(10,8);
    puts("Enter date of the meeting in the format (1st january 2020)");
    gotoxy(10,9);
    scanf("%s %s %d",comm_ach.arch_date.day,comm_ach.arch_date.month,&comm_ach.arch_date.year);
    fflush(stdin);
    gotoxy(10,11);
    puts("Please input the description of the achievements");
    gotoxy(10,12);
    gets(comm_ach.description);
    return 1;
}
void comm_metngs()
{

    CLEAR_SCREEN;
    rectangle(4,4,76,29);
    gotoxy(5,5);
    printf("_____________________The community meetings___________________________");
    gotoxy(10,8);
    puts("1.Enter Meeting Details");
    gotoxy(10,9);
    puts("2.Enter Achievement Details");
    gotoxy(10,10);
    puts("3.View Minutes");
    gotoxy(10,11);
    puts("4.View Achievements");
    gotoxy(10,12);
    puts("5.RETURN");
    gotoxy(10,16);
    printf("Enter your choice: ");
    switch(getch())
    {
    case '1':
        meeting();
        break;
    case '2':
        achievement();
    case '3':
        view_minutes();
    case '4':
        view_achieve();
    case '5':
        admininterface();
    default:
    {
        gotoxy(6,17);
        puts("Please re-try you just entered a wrong input");
        if(getch())
            comm_metngs();
    }
    }
}
void indexing()
{
    CLEAR_SCREEN;
    rectangle(4,4,76,29);
    gotoxy(5,5);
    printf("_______________________The community Treasury________________________");
    gotoxy(10,8);
    printf("1.Enter monthly Details");
    gotoxy(10,9);
    printf("2.Enter withdrawals Details");
    gotoxy(10,10);
    printf("3.View contributions");
    gotoxy(10,11);
    printf("4.View withdrawals");
    gotoxy(10,13);
    printf("5. MAIN MENU");
    gotoxy(10,16);
    printf("Enter your choice: ");
    switch(getch())
    {
    case '1':
        contribution();
        break;
    case '2':
        withdrawals();
    case '3':
        view_contri();
    case '4':
        view_withdraw();
    case'5':
            frontinterface();
    default:
        puts("Please re-try you just entered a wrong input");
        if(getch())
            indexing();

    }

}
void contribution()
{
    CLEAR_SCREEN;
    fp=fopen("contr.DAT","ab+");
    if(contrib_input()==1)
    {
        fseek(fp,0,SEEK_END);
        fwrite(&monthly,sizeof(monthly),1,fp);
        fclose(fp);
        gotoxy(8,20);
        printf("The record is successfully saved\n");
        gotoxy(8,22);
        printf("Do you wish to new information?(Y / N):");
        if(getch()=='n')
            indexing();
        else
            contribution();
    }

}

void withdrawals()
{
    CLEAR_SCREEN;
    fs=fopen("withdraw.DAT","ab+");
    if(withdra_input()==1)
    {
        fseek(fs,0,SEEK_END);
        fwrite(&usual,sizeof(usual),1,fs);
        fclose(fs);
        gotoxy(8,20);
        printf("The record is successfully saved\n");
        gotoxy(8,22);
        printf("Do you wish to new information?(Y / N):");
        if(getch()=='n')
            indexing();
        else
            withdrawals();
    }
}
void view_contri()
{
    CLEAR_SCREEN;

    int i=0;
    rectangle(4,4,100,25);
    gotoxy(5,5);
    printf("__________________________Community Contributions and timestamps______________________________");
    gotoxy(7,7);
    printf("*Name*******************************Amount*********************Day, Month and Year*******\n");
    fp=fopen("contr.DAT","rb");
    while(fread(&monthly,sizeof(monthly),1,fp)==1)
    {
        gotoxy(5,8+i);
        printf("    %s",monthly.whopays);
        gotoxy(40,8+i);
        printf(" %.2f$",monthly.amount);
        gotoxy(70,8+i);
        printf(" %s %s %d",monthly.contri_month.day,monthly.contri_month.month,monthly.contri_month.year);
        printf("\n\n");
        i++;
    }
    fclose(fp);

    gotoxy(10,20);
    printf(" Press ENTER to return ");
    if(getch()==13)
        indexing();
}
void view_withdraw()
{
    CLEAR_SCREEN;

    rectangle(4,4,100,25);
    gotoxy(5,5);
    printf("_____________________________Community withdrawals and timestamps_____________________________");
    gotoxy(8,8);
    printf("**Date of the withdrawals****************Amount*****************Reason*********************\n");
    fs=fopen("withdraw.DAT","rb");
    int i=0;
    while(fread(&usual,sizeof(usual),1,fs)==1)
    {
        gotoxy(9,10+i);
        printf("  %s %s %d ",usual.withdrawal.day,usual.withdrawal.month,usual.withdrawal.year);
        gotoxy(48,10+i);
        printf("%.2f$",usual.amnt_with);
        printf("\t\t");
        gotoxy(750,10+i);
        puts(usual.reason);
        printf("\n\n");
        i++;
    }
    fclose(fs);

    gotoxy(10,24);
    printf(" Press ENTER to return ");
    if(getch()==13)
        indexing();
}
int contrib_input()
{
    CLEAR_SCREEN;
    rectangle(4,4,100,25);
    gotoxy(5,5);
    puts("_________________________________Contributions Inputing______________________________________");
    gotoxy(8,8);
    puts("Enter month and year of the contribution in the format ( 2nd january 2020)");
    gotoxy(8,9);
    scanf("%s %s %d",monthly.contri_month.day,monthly.contri_month.month,&monthly.contri_month.year);
    fflush(stdin);
    gotoxy(8,11);
    puts("Please input the name of the person who has contributed");
    gotoxy(8,12);
    gets(monthly.whopays);
    fflush(stdin);
    gotoxy(8,14);
    puts("Please input the amount");
    gotoxy(8,15);
    scanf("%f",&monthly.amount);
    return 1;
}
int withdra_input()
{
    CLEAR_SCREEN;
    rectangle(4,4,100,25);
    gotoxy(5,5);
    puts("___________________________________Withdrawals Inputing_______________________________________");
    gotoxy(8,8);
    puts(" Enter date of the withdrawal in the format (1st january 2020)");
    gotoxy(8,9);
    scanf("%s %s %d",usual.withdrawal.day,usual.withdrawal.month,&usual.withdrawal.year);
    fflush(stdin);
    gotoxy(8,11);
    puts("Please input the reason for this withdrawal");
    gotoxy(8,12);
    gets(usual.reason);
    gotoxy(8,14);
    puts("Please input the amount to be withdrawn");
    gotoxy(8,15);
    scanf("%f",&usual.amnt_with);
    fflush(stdin);
    return 1;
}
void displayList()
{
    FILE *fp = fopen("member.DAT","rb");
    if(fp==NULL)
    {
        puts("Error while reading DATA!!!!");
        exit(0);
    }
    student *dataEmp=NULL;

    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //const SMALL_RECT WinSize = {20,30,40,120};

    //SetConsoleWindowInfo( hConsole, true, &WinSize);

    CLEAR_SCREEN;
    resideConsole(70,150);
    rectangle(4,4,107,30);
    gotoxy(40,2);
    puts("_________________________");
    gotoxy(40,3);
    puts("| COMUNITY MEMBERS LIST |");
    gotoxy(5,5);
    puts("__ID________Full Name_________Gender_________Email__________Dept._____Prog._____Init.Yr____Grad.Year");
    gotoxy(5,6);
    int i=0;
    while(1)
    {
        if( feof(fp) )
        {
            fclose(fp);
            break ;
        }
        dataEmp = (student*) calloc(1,sizeof(student));
        fflush(stdout);
        fflush(stdin);
        fread(dataEmp,sizeof(student),1,fp);

        gotoxy(6,6+i);
        printf(dataEmp->ID);

        gotoxy(13,6+i);
        printf("%s %s\t\t",dataEmp->name,dataEmp->fname);

        gotoxy(35,6+i);
        printf(dataEmp->gender);

        gotoxy(45,6+i);
        printf(dataEmp->email);

        gotoxy(67,6+i);
        printf(dataEmp->dep);

        gotoxy(76,6+i);
        printf(dataEmp->prog);

        gotoxy(85,6+i);
        printf(" \t%d",dataEmp->admission);

        gotoxy(94,6+i);
        printf(" \t   %d",dataEmp->graduation);

        i++;
    }
    gotoxy(10,24);
    printf(" Press ENTER to return ");
    if(getch()==13)
        admininterface();
}

char* generateID()
{
    char* id = (char*) calloc(1,sizeof(char)*10);
    time_t t;
    srand(time(&t));
    int num = rand();
    itoa(num,id,16);
    return id;
}


