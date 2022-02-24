/* Sketch realiza a comunicação de 3 servos pelo protocolo 
ModBus RTU com uma IHM remota simulada pelo software 
Easybuilder Pro.
O projeto foi desenvolvido pelos alunos do curso técnico em
Automação Industrial, turma 613. 
Código Escrito por Thiago Costa Nunes
IHM desenvolvida por Yan Cauê
*/


#include <Servo.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>

modbusDevice regBank;
modbusSlave slave;
// Nomeação dos Servos 

Servo altura;
Servo garra;
Servo comprimento;
Servo base;

// Variáveis de Manipulação de dados:
// Para serem usadas pelos Botões na IHM 
int cond = 0;
int cond1 = 0;
int cond2 = 0;
int cond3 = 0;

// Para controlar o laço que comanda as posições dos servos
int pos = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;

// Variaveis para inpedir o loop dos servos
int a;
int b;
int c;
int d;

void setup()
{   
  regBank.setId(1); //Set Slave ID
  altura.attach(9); 
  garra.attach(11);
  comprimento.attach(12);
  base.attach(10);

  regBank.add(1); // Altura
  regBank.add(2); // Garra
  regBank.add(3); // Comprimento
  regBank.add(4); // Base

  slave._device = &regBank; 
  slave.setBaud(9600);
}
void loop(){

  //Controle da Altura: 
    int p_altura = regBank.get(1);
      if (p_altura <= 0){
      cond = 1;
      }
 
      if (p_altura >= 1){
        cond = 0;
      }
  //Controle da Garra: 
    int p_garra = regBank.get(2);
      if (p_garra <= 0){
      cond1 = 1;
      }
 
      if (p_garra >= 1){
        cond1 = 0;
      }
  //Controle do comprimento: 
    int p_comprimento = regBank.get(3);
      if (p_comprimento <= 0){
      cond2 = 1;
      }
 
      if (p_comprimento >= 1){
        cond2 = 0;
      }
  //Controle da Base: 
    int p_base = regBank.get(4);
      if (p_base <= 0){
      cond3 = 1;
      }
 
      if (p_base >= 1){
        cond3 = 0;
      }

programa (); 
slave.run(); 
}

void programa () {
  // Comando da Altura:
  if (cond == 1 && a == 1) {
       for (pos = 0; pos <= 180; pos += 1) { 
           altura.write(pos);              
           delay(15);                
           a = 0;
           }
   } 
   
  if (cond == 0 && a == 0){
      for (pos = 180; pos >= 0; pos -= 1) { 
          altura.write(pos);             
          delay(15);                       
          a = 1;
          } 
   }
  // Comando da Garra:
  if (cond1 == 1 && b == 1) {
       for (pos1 = 0; pos1 <= 180; pos1 += 1) { 
           garra.write(pos1);              
           delay(15);                
           b = 0;
           }
   } 
   
  if (cond1 == 0 && b == 0){
      for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
          garra.write(pos1);             
          delay(15);                       
          b = 1;
          } 
   }

  // Comando do Comprimento:
  if (cond2 == 1 && c == 1) {
       for (pos2 = 0; pos2 <= 180; pos2 += 1) { 
           comprimento.write(pos2);              
           delay(15);                
           c = 0;
           }
   } 
   
  if (cond2 == 0 && c == 0){
      for (pos2 = 180; pos2 >= 0; pos2 -= 1) { 
          comprimento.write(pos2);             
          delay(15);                       
          c = 1;
          } 
   }

   // Comando da Base:
  if (cond3 == 1 && d == 1) {
       for (pos3 = 0; pos3 <= 180; pos3 += 1) { 
           base.write(pos3);              
           delay(15);                
           d = 0;
           }
   } 
   
  if (cond3 == 0 && d == 0){
      for (pos3 = 180; pos3 >= 0; pos3 -= 1) { 
          base.write(pos3);             
          delay(15);                       
          d = 1;
          } 
   }
   
}
