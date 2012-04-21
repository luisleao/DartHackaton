#include <Wire.h>




#define  BUTTON1        A6
#define  BUTTON2        A7
#define  BUTTON3        A8

#define  LED3_RED       2
#define  LED3_GREEN     4
#define  LED3_BLUE      3

#define  LED2_RED       5
#define  LED2_GREEN     7
#define  LED2_BLUE      6

#define  LED1_RED       8
#define  LED1_GREEN     10
#define  LED1_BLUE      9



String inputString = "";


int btn1_state = HIGH;
int btn2_state = HIGH;
int btn3_state = HIGH;




void setup() {
  // initialize serial:
  Serial.begin(57600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);

  // enable the internal pullups
  digitalWrite(BUTTON1, HIGH);
  digitalWrite(BUTTON2, HIGH);
  digitalWrite(BUTTON3, HIGH);
  
  init_leds();
  
  delay(1000);

}



void init_leds()
{
  pinMode(LED1_RED, OUTPUT);
  pinMode(LED1_GREEN, OUTPUT);
  pinMode(LED1_BLUE, OUTPUT);
  
  digitalWrite(LED1_RED, HIGH);
  digitalWrite(LED1_GREEN, LOW);
  digitalWrite(LED1_BLUE, HIGH);
  
  pinMode(LED2_RED, OUTPUT);
  pinMode(LED2_GREEN, OUTPUT);
  pinMode(LED2_BLUE, OUTPUT);
  
  digitalWrite(LED2_RED, HIGH);
  digitalWrite(LED2_GREEN, LOW);
  digitalWrite(LED2_BLUE, HIGH);
  
  pinMode(LED3_RED, OUTPUT);
  pinMode(LED3_GREEN, OUTPUT);
  pinMode(LED3_BLUE, OUTPUT);
  
  digitalWrite(LED3_RED, HIGH);
  digitalWrite(LED3_GREEN, LOW);
  digitalWrite(LED3_BLUE, HIGH);


  delay(500);
  digitalWrite(LED1_GREEN, HIGH);
  digitalWrite(LED2_GREEN, HIGH);
  digitalWrite(LED3_GREEN, HIGH);

}

void loop() {
  
  if (digitalRead(BUTTON1) != btn1_state) {
    btn1_state = digitalRead(BUTTON1);
    if (btn1_state == LOW)
      Serial.print("OA\n");
  }

  if (digitalRead(BUTTON2) != btn2_state) {
    btn2_state = digitalRead(BUTTON2);
    if (btn2_state == LOW)
      Serial.print("OB\n");
  }

  if (digitalRead(BUTTON3) != btn3_state) {
    btn3_state = digitalRead(BUTTON3);
    if (btn3_state == LOW)
      Serial.print("OC\n");
  }
  


}





void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n' || inChar == '\r') {
      
      //Serial.println(inputString); 
      //Serial.print("entrada ");
      //Serial.println(inputString.substring(0, 1));
      
      if (inputString.substring(0,1).equals("C")) { //clear leds
        digitalWrite(LED1_RED, HIGH); digitalWrite(LED1_GREEN, HIGH); digitalWrite(LED1_BLUE, HIGH);
        digitalWrite(LED2_RED, HIGH); digitalWrite(LED2_GREEN, HIGH); digitalWrite(LED2_BLUE, HIGH);
        digitalWrite(LED3_RED, HIGH); digitalWrite(LED3_GREEN, HIGH); digitalWrite(LED3_BLUE, HIGH);
        
      if (inputString.substring(0,1).equals("G")) { //green leds
        digitalWrite(LED1_RED, HIGH); digitalWrite(LED1_GREEN, LOW); digitalWrite(LED1_BLUE, HIGH);
        digitalWrite(LED2_RED, HIGH); digitalWrite(LED2_GREEN, LOW); digitalWrite(LED2_BLUE, HIGH);
        digitalWrite(LED3_RED, HIGH); digitalWrite(LED3_GREEN, LOW); digitalWrite(LED3_BLUE, HIGH);
        
      } else if (inputString.substring(0,1).equals("T")) {
        digitalWrite(LED1_RED, LOW); digitalWrite(LED1_GREEN, HIGH); digitalWrite(LED1_BLUE, HIGH);
        digitalWrite(LED2_RED, LOW); digitalWrite(LED2_GREEN, HIGH); digitalWrite(LED2_BLUE, HIGH);
        digitalWrite(LED3_RED, LOW); digitalWrite(LED3_GREEN, HIGH); digitalWrite(LED3_BLUE, HIGH);
        
      } else if (inputString.substring(0,1).equals("L")) {
        String led = inputString.substring(1,2);
        String cor = inputString.substring(2,3);
        if (led.equals("A")) {
          digitalWrite(LED1_RED, cor == "R" ? LOW : HIGH);
          digitalWrite(LED1_GREEN, cor == "G" ? LOW : HIGH);
          digitalWrite(LED1_BLUE, cor == "B" ? LOW : HIGH);
          
        } else if (led.equals("B")) {
          digitalWrite(LED2_RED, cor == "R" ? LOW : HIGH);
          digitalWrite(LED2_GREEN, cor == "G" ? LOW : HIGH);
          digitalWrite(LED2_BLUE, cor == "B" ? LOW : HIGH);
          
        } else if (led.equals("C")) {
          digitalWrite(LED3_RED, cor == "R" ? LOW : HIGH);
          digitalWrite(LED3_GREEN, cor == "G" ? LOW : HIGH);
          digitalWrite(LED3_BLUE, cor == "B" ? LOW : HIGH);
          
        }
      }
      
      
      
      // clear the string:
      inputString = "";

    } else {
      // add it to the inputString:
      inputString += inChar;
    }
  }
}










      
      /*
      
        pinMode(JOY_SWITCH, INPUT);
  digitalWrite(JOY_SWITCH, HIGH);

      
        init_joystick( 5 );


      #define  JOY_SWITCH     A9      // pulls line down when pressed
      #define  JOY_nINT       A10     // active low interrupt input
      #define  JOY_nRESET     A11     // active low reset output
      
      int joy_state = HIGH;
      
      int joy_x;
      int joy_y;




      
      
void init_joystick(int threshold);




      
      int new_joy_x;
      int new_joy_y;
      
      read_joystick(&joy_x, &joy_y);





      if (inputString.equals("JOY")) {
        
        Serial.print("JOY: ");
        Serial.print(constrain(joy_x, -128, 127));
        Serial.print(",");
        Serial.println(constrain(joy_y, -128, 127));

      }
      */
      
      
/*


// ==============================================================================
// Austria Microsystems i2c Joystick
void init_joystick(int threshold)
{
	byte status = 0;

	pinMode(JOY_SWITCH, INPUT);
	digitalWrite(JOY_SWITCH, HIGH);

	pinMode(JOY_nINT, INPUT);
	digitalWrite(JOY_nINT, HIGH);

	pinMode(JOY_nRESET, OUTPUT);

	digitalWrite(JOY_nRESET, 1);
	delay(1);
	digitalWrite(JOY_nRESET, 0);
	delay(1);
	digitalWrite(JOY_nRESET, 1);

	Wire.begin();

	do {
		status = read_joy_reg(0x0f);
	} while ((status & 0xf0) != 0xf0);

	// invert magnet polarity setting, per datasheet
	write_joy_reg(0x2e, 0x86);

	calibrate_joystick(threshold);
}



int offset_X, offset_Y;

void calibrate_joystick(int dz)
{
	char iii;
	int x_cal = 0;
	int y_cal = 0;

	// Low Power Mode, 20ms auto wakeup
	// INTn output enabled
	// INTn active after each measurement
	// Normal (non-Reset) mode
	write_joy_reg(0x0f, 0x00);
	delay(1);

	// dummy read of Y_reg to reset interrupt
	read_joy_reg(0x11);

	for(iii = 0; iii != 16; iii++) {
		while(!joystick_interrupt()) {}

		x_cal += read_joy_reg(0x10);
		y_cal += read_joy_reg(0x11);
	}

	// divide by 16 to get average
	offset_X = -(x_cal>>4);
	offset_Y = -(y_cal>>4);

	write_joy_reg(0x12, dz - offset_X);  // Xp, LEFT threshold for INTn
	write_joy_reg(0x13, -dz - offset_X);  // Xn, RIGHT threshold for INTn
	write_joy_reg(0x14, dz - offset_Y);  // Yp, UP threshold for INTn
	write_joy_reg(0x15, -dz - offset_Y);  // Yn, DOWN threshold for INTn

	// dead zone threshold detect requested?
	if (dz)
		write_joy_reg(0x0f, 0x04);
}


void read_joystick(int *x, int *y)
{
	*x = read_joy_reg(0x10) + offset_X;
	*y = read_joy_reg(0x11) + offset_Y;  // reading Y clears the interrupt
}

char joystick_interrupt()
{
	return digitalRead(JOY_nINT) == 0;
}


#define  JOY_I2C_ADDR    0x40

char read_joy_reg(char reg_addr)
{
	char c;

	Wire.beginTransmission(JOY_I2C_ADDR);
	Wire.write(reg_addr);
	Wire.endTransmission();

	Wire.requestFrom(JOY_I2C_ADDR, 1);

	while(Wire.available())
		c = Wire.read();

	return c;
}

void write_joy_reg(char reg_addr, char val)
{
	Wire.beginTransmission(JOY_I2C_ADDR);
	Wire.write(reg_addr);
	Wire.write(val);
	Wire.endTransmission();
}

*/

