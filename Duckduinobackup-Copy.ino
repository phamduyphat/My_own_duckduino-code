#include <SPI.h>
#include <SD.h>
#include <EEPROM.h>
#include <Keyboard.h>



/*functions*/
void selection();
String inputData();
boolean checkifstristhesameaspayload(uint8_t payload, String test);
boolean isNumeric(String test);
void SerialInterface();
/***************************************************************************************/

void setup() {
  
  if (!SD.begin(4)) {Serial.begin(74880); SerialInterface(); return;}
  
  byte no = EEPROM.read(0);
  uint8_t exe_no = no;
  String DEFAULT_FILE_NAME = "script" + String(exe_no) + ".txt";
  File myFile = SD.open(DEFAULT_FILE_NAME);
 
  
  if (myFile) {
    Keyboard.begin();
    
    String line = "";
    while (myFile.available()) {
      char m = myFile.read();
      if (m == '\n'){
        Line(line);
        line = "";
        }
        else if((int) m != 13)
        {
          line += m;
        }
    }
    Line(line);
    
    myFile.close();
  } else {
  }

/*****************************************************************************************/
  pinMode(8,OUTPUT);
/*****************************************************************************************/
  
  Keyboard.end();
}

void Line(String l)
{
  int space_1 = l.indexOf(" ");
  if (space_1 == -1)
  {
    Press(l);
  }
  else if (l.substring(0,space_1) == "STRING")
  {
    Keyboard.print(l.substring(space_1 + 1));
  }
  else if (l.substring(0,space_1) == "DELAY")
  {
    int delaytime = l.substring(space_1 + 1).toInt();
    delay(delaytime);
  }
  else if(l.substring(0,space_1) == "REM"){}
  else
  {
      String remain = l;

      while(remain.length() > 0)
      {
        int latest_space = remain.indexOf(" ");
        if (latest_space == -1)
        {
          Press(remain);
          remain = "";
        }
        else
        {
          Press(remain.substring(0, latest_space));
          remain = remain.substring(latest_space + 1);
        }
        delay(5);
      }
  }

  Keyboard.releaseAll();
}


void Press(String b)
{
  if(b.length() == 1)
  {
    char c = b[0];
    Keyboard.press(c);
  }
  else if (b.equals("ENTER"))
  {
    Keyboard.press(KEY_RETURN);
  }
  else if (b.equals("CTRL")||b.equals("CONTROL"))
  {
    Keyboard.press(KEY_LEFT_CTRL);
  }
    else if (b.equals("SHIFT"))
  {
    Keyboard.press(KEY_LEFT_SHIFT);
  }
    else if (b.equals("ALT"))
  {
    Keyboard.press(KEY_LEFT_ALT);
  }
    else if (b.equals("GUI"))
  {
    Keyboard.press(KEY_LEFT_GUI);
  }
    else if (b.equals("UP") || b.equals("UPARROW"))
  {
    Keyboard.press(KEY_UP_ARROW);
  }
    else if (b.equals("DOWN") || b.equals("DOWNARROW"))
  {
    Keyboard.press(KEY_DOWN_ARROW);
  }
    else if (b.equals("LEFT") || b.equals("LEFTARROW"))
  {
    Keyboard.press(KEY_LEFT_ARROW);
  }
    else if (b.equals("RIGHT") || b.equals("RIGHTARROW"))
  {
    Keyboard.press(KEY_RIGHT_ARROW);
  }
    else if (b.equals("DELETE"))
  {
    Keyboard.press(KEY_DELETE);
  }
    else if (b.equals("PAGEUP"))
  {
    Keyboard.press(KEY_PAGE_UP);
  }
    else if (b.equals("PAGEDOWN"))
  {
    Keyboard.press(KEY_PAGE_DOWN);
  }
    else if (b.equals("HOME"))
  {
    Keyboard.press(KEY_HOME);
  }
    else if (b.equals("ESC"))
  {
    Keyboard.press(KEY_ESC);
  }
    else if (b.equals("INSERT"))
  {
    Keyboard.press(KEY_INSERT);
  }
    else if (b.equals("TAB"))
  {
    Keyboard.press(KEY_TAB);
  }
    else if (b.equals("END"))
  {
    Keyboard.press(KEY_END);
  }
    else if (b.equals("CAPSLOCK"))
  {
    Keyboard.press(KEY_CAPS_LOCK);
  }
    else if (b.equals("SPACE"))
  {
    Keyboard.press(' ');
  } 
    else if (b.equals("F1"))
  {
    Keyboard.press(KEY_F1);
  }
    else if (b.equals("F2"))
  {
    Keyboard.press(KEY_F2);
  }
    else if (b.equals("F3"))
  {
    Keyboard.press(KEY_F3);
  }
    else if (b.equals("F4"))
  {
    Keyboard.press(KEY_F4);
  }
    else if (b.equals("F5"))
  {
    Keyboard.press(KEY_F5);
  }
    else if (b.equals("F6"))
  {
    Keyboard.press(KEY_F6);
  }
    else if (b.equals("F7"))
  {
    Keyboard.press(KEY_F7);
  }
    else if (b.equals("F8"))
  {
    Keyboard.press(KEY_F8);
  }
    else if (b.equals("F9"))
  {
    Keyboard.press(KEY_F9);
  }
    else if (b.equals("F10"))
  {
    Keyboard.press(KEY_F10);
  }
    else if (b.equals("F11"))
  {
    Keyboard.press(KEY_F11);
  }
    else if (b.equals("F12"))
  {
    Keyboard.press(KEY_F12);
  }
  else if (b.equals("F13"))
  {
    Keyboard.press(KEY_F13);
  }
    else if (b.equals("F14"))
  {
    Keyboard.press(KEY_F14);
  }
    else if (b.equals("F15"))
  {
    Keyboard.press(KEY_F15);
  }
    else if (b.equals("F16"))
  {
    Keyboard.press(KEY_F16);
  }
    else if (b.equals("F17"))
  {
    Keyboard.press(KEY_F17);
  }
    else if (b.equals("F18"))
  {
    Keyboard.press(KEY_F18);
  }
    else if (b.equals("F19"))
  {
    Keyboard.press(KEY_F19);
  }
    else if (b.equals("F20"))
  {
    Keyboard.press(KEY_F20);
  }
    else if (b.equals("F21"))
  {
    Keyboard.press(KEY_F21);
  }
    else if (b.equals("F22"))
  {
    Keyboard.press(KEY_F22);
  }
    else if (b.equals("F23"))
  {
    Keyboard.press(KEY_F23);
  }
    else if (b.equals("F24"))
  {
    Keyboard.press(KEY_F24);
  }
}

String inputData(){
  String inputString;
  while (true){
    if (Serial.available()){
      inputString = Serial.readStringUntil('\n');
      break;
    }
  }
  return inputString;
}

void SerialInterface()
{
  selection();
  Serial.println();
  Serial.print("Are you sure that you want to quit? (Y/N): ");
  while (true)
  {
    String YesorNo = inputData();
    if (YesorNo == "Y" || YesorNo == "y") {Serial.println(YesorNo); Serial.println("Prepare to have some fun =)"); break;}
    else if (YesorNo == "N" || YesorNo == "n") {Serial.println(YesorNo); SerialInterface(); break;}
    else {
      Serial.println(YesorNo);
      Serial.print("Please type that again (Y/N): ");
      continue;
    }
  }
  return;
}

void selection()
{
  byte readed = EEPROM.read(0);
  uint8_t payload = readed;
  Serial.print("Selected payload: ");
  Serial.println(payload);
  Serial.print("Change payload to: ");
  String number = inputData();
  while (true)
  {
    if (checkifstristhesameaspayload(payload, number))
    {
      Serial.println(number);
      Serial.print("Same as before, please type a f**king different payload: ");
      number = inputData();
    }
    else if ( ! isNumeric(number))
    {
      Serial.println(number);
      Serial.print("Now type without using non-digit stuff: ");
      number = inputData();
    }
    else break;
  }
  payload = number.toInt();
  Serial.println(payload);
  EEPROM.write(0, (payload << 0) & 0xFF);
  return;
}

boolean checkifstristhesameaspayload(uint8_t payload, String test)
{
  if (test.toInt() == payload)
    return true;
  else return false;
}

boolean isNumeric(String test)
{
  for (int8_t i = 0; i < test.length(); i++)
  {
    if ( ! isDigit(test[i])) {return false; break;}
  } 
  return true;
}

void loop() {
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8, LOW);
  delay(1000);
}
