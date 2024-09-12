#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>
#include "can.h"

CAN can(5); // verificar a pinagem

float temperatura;
float pressao;
float atmosfera;
float altitude;
int potenciometro;
uint32_t valor[5];

int potValue = 0;
#define LED 13
int variacao = 0;
int i = 0;

#endif