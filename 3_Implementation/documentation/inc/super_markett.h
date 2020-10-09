/**
* @mainpage Super Market Management System  by Amrutha Kotteda with PS:ID-104712 @subpage super_markett.h
* @file super_markett.h
* supermarketmanagementsystem application with 5 applications
*
*/
#ifndef SUPER_MARKETT_H_
#define SUPER_MARKETT_H_

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct item
{
    int code,Quantity,Price;
    char name[20];
};

/**
*  adds the items and returns the result
* @param[in] c.name
* @param[in] c.code
* @param[in] c.Quantity
* @param[in] c.Price
* @return Item Added Successfully
*/
int ADD();


/**
*  adds the item and returns the result
* @return item with details of c.name c.code c.Quantity c.Price
*/

int VIEW();

/**
*  adds the item and returns the result
* @param[in] c.name
* @return item with details of c.name c.code c.Quantity c.Price
*/
int SEARCH();


/**
* edits the item and returns the result
* @param[in] c.name
* @param[in] c.code
* @param[in] c.Quantity
* @param[in] c.Price
* @return item edited Successfully
*/

int EDIT();


/**
* deletes the item and returns the result
* @return item deleted Successfully
*/
int DELETE();


#endif // SUPER_MARKETT_H_INCLUDED
