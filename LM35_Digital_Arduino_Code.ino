const int sensor=A1;// Assigning analog pin A1 to variable 'sensor'
int ledPin= 12;
int prev=0;
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading
void setup()
{
pinMode(sensor,INPUT); // Configuring pin A1 as input
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}
void loop() 
{

vout=analogRead(sensor);
vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
tempf=(vout*1.8)+32; // Converting to Fahrenheit 
if (tempf>=95){
  digitalWrite(ledPin,LOW);
  prev=0;
  }
else if(tempf>=85 && tempf<95){
  if (prev==1){
    digitalWrite(ledPin,HIGH);
    prev=1;
    }
  else {
    digitalWrite(ledPin,LOW);
    prev=0;
  }
    
  }
else{
  digitalWrite(ledPin,HIGH);
  prev=1;
  
  }


delay(1000); //Delay of 1 second for ease of viewing 
}
