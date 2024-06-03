const int res=A1;// Assigning analog pin A1 to variable 'sensor'
int ledPin= 12;
int prev=0;
float V1;  //variable to store temperature in degree Celsius
float Vt;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading
void setup()
{
pinMode(res,INPUT); // Configuring pin A1 as input
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}
void loop() 
{

vout=analogRead(res);
vout=(vout*500)/1023;
V1=vout; // Storing value in Degree Celsius
Vt=(vout*1.8)+32; // Converting to Fahrenheit 
if (Vt>=216){
  digitalWrite(ledPin,HIGH);
  prev=0;
  }
else if(Vt>=204 && Vt<216){
  if (prev==1){
    digitalWrite(ledPin,LOW);
    prev=1;
    }
  else {
    digitalWrite(ledPin,HIGH);
    prev=0;
  }
    
  }
else{
  digitalWrite(ledPin,LOW);
  prev=1;
  
  }


delay(1000); //Delay of 1 second for ease of viewing 
}
