/*==================================

  CLEAN BOX SOURCE CODE
  
   Codigo fonte de afericao dos sensores de PH e TURBIDEZ
   
   AUTOR: NEWTON R. DOS SANTOS
   DATA: 28 de julho de 2019
   
*/

//FUNCOES

double calcNTU(double volt_TURB);
double calcPH(double volt_PH);

//PORTAS Analogicas
int pin_PH = A2;
int pin_TURB = A0;


//variaveis globais
double NTU = 0.0;
double PH = 0.0;

//configuracoes iniciais

void setup(){
  Serial.begin(115200);
}

//LOOP

void loop(){
 
  // faz a leitura das portas analogicas A0 e A2
  int turbidSensor = analogRead(pin_TURB);
  int phSensor = analogRead(pin_PH);
  
  //converte em volts
  double volt_TURB = turbidSensor * (5.0 / 1024.0);
  double volt_PH = phSensor * (5.0 / 1024.0);
  
  
  // calcula NTU e PH
  NTU = calcNTU(volt_TURB);
  PH = calcPH(volt_PH);
 
  
  //envia os dados para a porta Serial
  Serial.print(NTU);  
  Serial.print(" | ");
  Serial.println(PH);
  
  // pausa de 2 SEG para a prox leitura
  delay(2000);
  
} 


//Funcoes

//calcula NTU
double calcNTU(double volt_TURB){
   
 double NTU = -(1120.4*volt_TURB*volt_TURB)+(5742.3*volt_TURB)-4352.9;
 
 return NTU; 
}

//calcula PH
double calcPH(double volt_PH){
 
  double PH = 7 + ((2.5 - volt_PH) / 0.18);
  
  return PH;
}  
