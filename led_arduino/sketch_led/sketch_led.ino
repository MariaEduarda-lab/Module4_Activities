// C++ code
//
void setup() // base function which defines 
{
  pinMode(13, OUTPUT);
}

void loop() // base function and everything inside it will be in a loop
{
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(13, HIGH);
  delay(200); // Wait for 200 millisecond(s)
  digitalWrite(13, LOW);
  delay(500); // Wait for 500 millisecond(s)
}