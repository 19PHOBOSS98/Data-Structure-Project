//midterms  practical exam header
#ifndef MIDTEURMS_H
#define MIDTEURMS_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

static void psh(char);
static void pp();

void InfixToPostfix(string);
void InfixToPrefix(string);

void reverseStr(string&);
bool isalp(char);
static bool isop(char);
int weight(char);
bool isH(char ,char);


struct nde
{
    char data;
    nde*next;
};


void ME();

#endif
