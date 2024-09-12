/*
 Esse codigo faz parte do inicio da aprendizagem sobre rede can
 O receptor recebe um pacote de dados e o exibe no monitor serial
 Utilizaremos um esp32 para o recebimento e um arduino uno para o envio
*/

#include "main.h"

void setup()
{
  Serial.begin(115200);
  
  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(can.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK)
    Serial.println("MCP2515 Initialized Successfully!");
  else
    Serial.println("Error Initializing MCP2515...");
  
  can.setMode(MCP_NORMAL);                     // Set operation mode to normal so the MCP2515 sends acks to received data.

  pinMode(CAN0_INT, INPUT_PULLUP);                            // Configuring pin for /INT input
  
  Serial.println("MCP2515 Library Receive Example...");
}

void loop()
{
  if(!digitalRead(CAN0_INT))                         // If CAN0_INT pin is low, read receive buffer
  {
    can.readCan();      
    switch (can.rxId)
    {
    case 0x01:
      temperatura = convertByte(can.rxBuf);
      Serial.print("Temperatura: ");
      Serial.println(temperatura);
      break;
    case 0x02:
      pressao = convertByte(can.rxBuf);
      Serial.print("Pressao: ");
      Serial.println(pressao);
      break;
    case 0x03:
      atmosfera = convertByte(can.rxBuf);
      Serial.print("Atmosfera padrao : ");
      Serial.println(atmosfera);
      break;
    case 0x04:
      altitude = convertByte(can.rxBuf);
      Serial.print("Altitude: ");
      Serial.println(altitude);
      break;
    case 0x05:
      potenciometro = (can.rxBuf[0] << 8) | can.rxBuf[1]; 
      Serial.print("Potenciometro: ");
      Serial.println(potenciometro);
      break;
    default:
      Serial.println("ID não reconhecido");
      break;
    }
    i++;
  }
  if (i == 5)
  {
    i = 0;
    Serial.println();
    can.sendFloat(temperatura, 0x01);
    can.sendFloat(pressao, 0x02);
    can.sendFloat(atmosfera, 0x03);
    can.sendFloat(altitude, 0x04);
    can.sendInt(potenciometro, 0x05);
    Serial.println();
  } 
}