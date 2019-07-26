//           ®jed@
#define max_char 12
char message[max_char];    // almacena tu mensaje
char r_char;               // lee cada caracter
byte index = 0;            //define la posición en su matriz
int i;

int redPin = 5;     // Red RGB pin -> D5
int greenPin = 6;   // Green RGB pin -> D6
int bluePin = 3;     // Blue RGB pin -> D3

int redValue = 255;     // Red RGB pin -> D5
int greenValue = 255;   // Green RGB pin -> D6
int blueValue = 255;     // Blue RGB pin -> D3

String redTempValue;     // Red RGB pin -> D5
String greenTempValue;   // Green RGB pin -> D6
String blueTempValue;     // Blue RGB pin -> D3

int flag = 0;
char currentColor;  

void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin, OUTPUT);
  // inicializa serial communication  9600 bits por segundo:
  Serial.begin(9600);
}
void loop() {
  //Mientras esta leyendo el mensaje 
  while(Serial.available() > 0){
    flag = 0;
    //El mensaje puede tener hasta 12 caracteres.
    if(index < (max_char-1)){         
      r_char = Serial.read();      // Reads a character
      message[index] = r_char;     // Stores the character in message array
      if(r_char=='R'){
         currentColor = 'R';
         redTempValue = "";
      }
      else if(r_char=='G'){
         currentColor = 'G';
         greenTempValue = "";
      }
      else if(r_char=='B'){
         currentColor = 'B';
         blueTempValue = "";
      }
      if(currentColor == 'R' && r_char!='R'){
         redTempValue += r_char;
      }
      else if(currentColor == 'G' && r_char!='G'){
         greenTempValue += r_char;
      }
      else if(currentColor == 'B' && r_char!='B'){
         blueTempValue += r_char;
      }
      index++;                     // Increment position
      message[index] = '\0';       // Delete the last position
   }
 }
 
 if(flag == 0){
   analogWrite(redPin, 255-redTempValue.toInt());
   analogWrite(greenPin, 255-greenTempValue.toInt());
   analogWrite(bluePin, 255-blueTempValue.toInt());
   Serial.println(message);
   flag=1;
       for(i=0; i<12; i++){
      message[i] = '\0';
    } 
    //resests the index
    index=0;  
 }
}
