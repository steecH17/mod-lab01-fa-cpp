// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>

unsigned int faStr1(const char *str) {
	int count = 0;
	bool inWord = false;
	bool digitInWord = false;
	while (*str) {
		if (*str != ' ' && inWord == false) {
			inWord = true;
		}
		else if (*str == ' ' && inWord == true) {
			inWord = false;
			if (!digitInWord)
				count++;
			else
				digitInWord = false;
		}
		if (*str > -1 && *str < 256 && isdigit(*str))
			digitInWord = true;
		str++;
	}
	if (!digitInWord && inWord)
		count++;
	return count;
}

unsigned int faStr2(const char *str) {
	int count = 0;
	bool inWord = false;
	bool firstUp = false;
	bool isLowercase = false;
	while (*str) {
		if (*str != ' ' && inWord == false) {
			if (*str > -1 && *str < 256 && isupper(*str))
				firstUp = true;
			else
				firstUp = false;
			inWord = true;
			isLowercase = true;
		}
		else if (*str == ' ' && inWord == true) {
			inWord = false;
			if (firstUp && isLowercase)
				count++;
		}
		else if (firstUp)
			if (!(*str > -1 && *str < 256 && islower(*str)))
				isLowercase = false;
		str++;
	}
	if (inWord && firstUp && isLowercase)
		count++;
	return count;
}

unsigned int faStr3(const char *str) {
	int count = 0;
	int sumLenght = 0;
	int currentLenght = 0;
	bool inWord = false;
	while (*str) {
		if (*str != ' ' && inWord == false) {
			count++;
			inWord = true;
		}
		else if (*str == ' ' && inWord == true) {
			inWord = false;
			sumLenght += currentLenght;
			currentLenght = 0;
		}
		if (*str != ' ' && inWord) {
			currentLenght++;
		}
		str++;
	}
	if (inWord)
		sumLenght += currentLenght;
	return round(sumLenght / (float)count);
}
