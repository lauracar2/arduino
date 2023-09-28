

#define sensorsinal A1 /* sensor ligado ao pino analógico A1 do Arduino */

int val = 0; /* declara val para armazenamento de dados */
int ledverde1 = 8; /* declara led verde 1 como pino 8*/
int ledverde2 = 9; /* declara led verde 2 como pino 9*/
int ledazul1 = 10; /* declara led azul 1 como pino 10*/
int ledazul2 = 11; /* declara led azul 2 como pino 11*/
int ledvermelho1 = 12; /* declara led vermelho 1 como pino 12*/
int ledvermelho2 = 13; /* declara led vermelho 2 como pino 13*/

void setup() { /* abre laço de configuração */
  pinMode (ledverde1, OUTPUT); /* define led verde 1 como saída do Arduino*/
  pinMode (ledverde2, OUTPUT); /* define led verde 2 como saída do Arduino*/
  pinMode (ledazul1, OUTPUT); /* define led azul 1 como saída do Arduino*/
  pinMode (ledazul2, OUTPUT); /* define led azul 2 como saída do Arduino*/
  pinMode (ledvermelho1, OUTPUT); /* define led vermelho 1 como saída do Arduino*/
  pinMode (ledvermelho2, OUTPUT);  /* define led vermelho 2 como saída do Arduino*/
  
  Serial.begin(9600); /*Baudrate de 9600*/
}

void loop() { /* laço de repetição */
  int level = readSensor(); /* level é o equivalente a leitura do sensor */

  Serial.print("Nível de água: "); /*Printa "Nível de água:" no monitor serial*/
  Serial.println(level); /* Printa o dado level no monitor serial*/
  if (level>=0 && level<280 ){  /* Se o nível está entre 0 e 279*/
    digitalWrite(ledverde1, HIGH); /* Nível lógico de Led verde 1 é alto*/
    digitalWrite(ledverde2, LOW); /* Nível lógico de Led verde 2 é baixo*/
    digitalWrite(ledazul1, LOW); /* Nível lógico de Led azul 1 é baixo*/
    digitalWrite(ledazul2, LOW); /* Nível lógico de Led azul 2 é baixo*/
    digitalWrite(ledvermelho1, LOW); /* Nível lógico de Led vermelho 1 é baixo */
    digitalWrite(ledvermelho2, LOW);  /* Nível lógico de Led vermelho 2 é baixo */ 
  }
  if (level>=280 && level<360 ){ /* Se o nível está entre 280 e 359*/
    digitalWrite(ledverde1, HIGH); /* Nível lógico de Led verde 1 é alto*/
    digitalWrite(ledverde2, HIGH); /* Nível lógico de Led verde 2 é alto*/
    digitalWrite(ledazul1, LOW); /* Nível lógico de Led azul 1 é baixo*/
    digitalWrite(ledazul2, LOW); /* Nível lógico de Led azul 2 é baixo*/
    digitalWrite(ledvermelho1, LOW);/* Nível lógico de Led vermelho 1 é baixo*/
    digitalWrite(ledvermelho2, LOW); /* Nível lógico de Led vermelho 2 é baixo*/
  }
  
  if (level>=360 && level<390 ){ /* Se o nível está entre 360 e 389*/
    digitalWrite(ledverde1, HIGH); /* Nível lógico de Led verde 1 é alto*/
    digitalWrite(ledverde2, HIGH); /* Nível lógico de Led verde 2 é alto*/
    digitalWrite(ledazul1, HIGH); /* Nível lógico de Led azul 1 é alto*/
    digitalWrite(ledazul2, LOW); /* Nível lógico de Led azul 2 é baixo*/
    digitalWrite(ledvermelho1, LOW); /* Nível lógico de Led vermelho 1 é baixo*/
    digitalWrite(ledvermelho2, LOW); /* Nível lógico de Led vermelho 2 é baixo*/   
  }
  if (level>=390 && level<420 ){ /* Se o nível está entre 360 e 389*/
    digitalWrite(ledverde1, HIGH); /* Nível lógico de Led verde 1 é alto*/
    digitalWrite(ledverde2, HIGH); /* Nível lógico de Led verde 2 é alto*/
    digitalWrite(ledazul1, HIGH); /* Nível lógico de Led azul 1 é alto*/
    digitalWrite(ledazul2, HIGH); /* Nível lógico de Led azul 2 é alto*/
    digitalWrite(ledvermelho1, LOW); /* Nível lógico de Led vermelho 1 é baixo*/
    digitalWrite(ledvermelho2, LOW); /* Nível lógico de Led vermelho 2 é baixo*/  
  }

  if (level>=420 && level<450 ){ /* Se o nível está entre 420 e 449*/
    digitalWrite(ledverde1, HIGH); /* Nível lógico de Led verde 1 é alto*/
    digitalWrite(ledverde2, HIGH); /* Nível lógico de Led verde 2 é alto*/
    digitalWrite(ledazul1, HIGH); /* Nível lógico de Led azul 1 é alto*/
    digitalWrite(ledazul2, HIGH); /* Nível lógico de Led azul 2 é alto*/
    digitalWrite(ledvermelho1, HIGH); /* Nível lógico de Led vermelho 1 é alto*/
    digitalWrite(ledvermelho2, LOW); /* Nível lógico de Led vermelho 2 é baixo*/  
  }
  if (level>=450){ /* Se o nível é maior ou igual a 450*/
    digitalWrite(ledverde1, HIGH); /* Nível lógico de Led verde 1 é alto*/
    digitalWrite(ledverde2, HIGH); /* Nível lógico de Led verde 2 é alto*/
    digitalWrite(ledazul1, HIGH); /* Nível lógico de Led azul 1 é alto*/
    digitalWrite(ledazul2, HIGH); /* Nível lógico de Led azul 2 é alto*/
    digitalWrite(ledvermelho1, HIGH); /* Nível lógico de Led vermelho 1 é alto*/
    digitalWrite(ledvermelho2, HIGH);  /* Nível lógico de Led vermelho 2 é alto*/ 
  }
  
  delay(1000); /* atraso de 1s entre uma leitura e outra */
}

int readSensor() {  /* leitura do sensor */
  val = analogRead(sensorsinal);    /* Realiza a leitura analógica do sinal do sensor */
  return val;             /* envia leitura */
}