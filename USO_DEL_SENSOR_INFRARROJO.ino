/*USO DEL SENSOR INFRARROJO
 * 
 * Explicación: este código controla un sensor infrarrojo para detectar obstáculos y muestra el resultado en el monitor serie del Arduino. 
 * Cuando el sensor detecta un obstáculo, envía un mensaje indicando la detección, y cuando no lo detecta, envía otro mensaje, indicando que
 * no ha detectado ningún obstaculo
 * 
 * Conexiones:
 * VCC DEL MODULO = 3.3V O 5V DEL ARDUINO
 * GND DEL SENSOR = GND DEL ARDUNO
 * OUT DEL SENSOR = AL PIN DIGITAL D2 DEL ARDUINO
 * 
 * CODIGO HECHO POR: EurekaMinds
 * 
 * SUSCRIBETE AL CANAL PARA MÁS TUTORIALES COMO ESTE*/

// Declaración de variables:
int sensor_infrarrojo = 2; // Pin donde está conectado el sensor infrarrojo
int valor_sensor_infrarrojo = 0; // Variable para almacenar el valor leído del sensor

void setup() {
  // Inicia la comunicación para enviar mensajes al monitor serie
  Serial.begin(9600);
  
  // Configura el pin del sensor infrarrojo como entrada
  pinMode(sensor_infrarrojo, INPUT);
}

void loop() {
  // Lee el estado del sensor infrarrojo (LOW si detecta un obstáculo, HIGH si no)
  valor_sensor_infrarrojo = digitalRead(sensor_infrarrojo);  // igualamos la lectura de el sensor a una variable

  // Verifica si el sensor ha detectado un obstáculo
  if(valor_sensor_infrarrojo == LOW) {
    // Si se detecta un obstáculo, imprime el mensaje en el monitor serie
    Serial.println("Se ha detectado un obstaculo");
    delay(1000); // Espera 1 segundo antes de la siguiente lectura
  } else {
    // Si no se detecta un obstáculo, imprime el mensaje correspondiente
    Serial.println("No se ha detectado ningún obstaculo");
    delay(1000); // Espera 1 segundo antes de la siguiente lectura
  }
}
