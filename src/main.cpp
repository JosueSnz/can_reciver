/*
 Esse codigo faz parte do inicio da aprendizagem sobre rede can
 O receptor recebe um pacote de dados e o exibe no monitor serial
 Utilizaremos um esp32 para o recebimento e um arduino uno para o envio
*/

#include "main.h"
void setup()
{
  Serial.begin(115200);
  
  if (can.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK) {
    Serial.println("CAN Inicializado...");
  } else {
    Serial.println("Erro ao iniciar o CAN...");
  }
  can.setMode(MCP_NORMAL);
  pinMode(CAN0_INT, INPUT);                            
}

void loop()
{
  if(!digitalRead(CAN0_INT))                          // O interrupt serve para verficar se há dados disponiveis
  {
    // Digite aqui o codigo para receber os dados
  }
}


