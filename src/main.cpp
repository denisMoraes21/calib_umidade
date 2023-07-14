/////// Universidade do Estado do Amazonas ///////
/////// Trabalho de Conclusão de Curso ///////
/////// Aluno: Denis Moraes Guimarães ///////

/////// Versão do firmware: V1.0 ///////

// Inclusão de biblioteca necessária para utilização de framework Arduino em PlatformIO IDE
#include <Arduino.h>

// Biblioteca utilizada para interfaceamento com o sensor
#include "DHT.h"

// Definição de pino utilizado na placa de desenvolvimento
#define DHTPIN 13

// Definição de modelo de sensor DHT utilizado
#define DHTTYPE DHT11

// Criação de instância do sensor de umidade para utilização dos métodos
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);

  // Inicialização do sensor de umidade
  dht.begin();
}

void loop()
{

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Verifica se retorno é valido
  if (isnan(temperature || isnan(humidity))) 
  {
    Serial.println("Failed to read values");
  } 
  else
  {
    // Debug de informações

    // Valor de umidade em porcentagem
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %");

    Serial.print("\t");

    // Valor de temperatura em graus Celcius
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
    
  }
  delay(500);
}
