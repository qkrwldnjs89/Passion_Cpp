#ifndef __FUNC_H__
#define __FUNC_H__

#include "AddressStruct.h"

void PrintMenu(void);
void CreateAddress(AddressStruct arr[], int * iptCnt);
void Deposit(AddressStruct arr[], int size);
void Withdraw(AddressStruct arr[], int size);
void PrintAll(AddressStruct arr[], int size);

#endif

