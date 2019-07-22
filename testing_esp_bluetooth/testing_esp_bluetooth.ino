include <BluetoothSerial.h>

BluetoothSerial ESP_BT;
int LED_BUILTIN = 2;
int incoming;

void setup() 
{
  Serial.begin(9600);
  ESP_BT.begin("ESP_BLUETOOTH");
  Serial.println("Device ready to pair");
  pinMode (LED_BUILTIN, OUTPUT);
}
void loop() 
{
  if(ESP_BT.available())
  {
    incoming = ESP_BT.read();
    Serial.print("received:");
    Serial.println("incoming");

    if(incoming == 49) //int value for '1'
    {
      digitalWrite(LED_BUILTIN, HIGH);
      ESP_BT.println("LED turned ON");
    }

    else if(incoming == 48) //int value for '0'
    {
      digitalWrite(LED_BUILTIN, LOW);
      ESP_BT.println("LED turned OFF");
    }
  }
