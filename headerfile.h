
#ifndef HEADERFILE_H_INCLUDED
#define HEADERFILE_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>

#define CLEAR_SCREEN system("cls")
#define true 1
#define false 0

typedef unsigned int bool;
typedef struct user
{
    char username[50];
    char password[50];
    bool admin;
} USER;
struct student
{
    char ID[50];
    char name[255];
    char fname[50];
    char gender[10];
    char dep[30];
    char prog[30];
    char email[40];
    int graduation,admission;
};
typedef struct student student;
struct date
{
    char day[5];
    char month[10];
    int year;
};
struct minu
{
    struct date met_date;
    char minutes[255];
};
struct minu met_min;
struct arch
{
    struct date arch_date;
    char description[2043];
};
struct arch comm_ach;

struct contri
{
    struct date contri_month;
    float amount;
    char whopays[50];
};
struct contri monthly;

struct with
{
    struct date withdrawal;
    float amnt_with;
    char reason[2043];
};
struct with usual;
FILE *fp, *fs;



void addMember();
void deletemember();
void meeting();
void achievement();
void comm_metngs();
void view_minutes();
void view_achieve();
int minutes_input();
int arch_input();
void contribution();
void withdrawals();
void indexing();
void view_contri();
void view_withdraw();
int contrib_input();
int withdra_input();
void gotoxy(int x, int y);
void rectangle(int x,int y, int l, int b);
void resideConsole(int x, int y);
void frontinterface();
USER password(char* usertype);
bool searchUser(USER ut, int optionType);
void admininterface();
void treasurerinterface();
void frontpage();
void search_member();
struct student member;
void displayList();
char* generateID();

#endif // HEADERFILE_H_INCLUDED
