#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>

#define CAN0_INT 17                              
MCP_CAN can(5);   

#define LED 4

#endif