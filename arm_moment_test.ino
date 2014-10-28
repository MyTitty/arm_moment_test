#include <string.h>

int valX = 0;
int valY = 0;
int valZ = 0;
long sumX = 0;
long sumZ = 0;
int avgX = 0;
int avgZ = 0;
long count = 0;
int maxX = 0;
int maxZ = 0;
int minX = 1000;
int minZ = 1000;
char* First = "null";
char* Second = "null";

void setup(){
  Serial.begin(38400);
}

void loop(){
  valX = getX();
  sumX = sumX + valX;
  count++;
  avgX = sumX / count;

  if( valX > avgX + 100 ){
    if( strcmp( First, "null") == 0 ){
      First = "Over";
    }else if ( strcmp( First, "Under") == 0 ){
      Second = "Over";
    }
  }else if ( avgX - 100 > valX){
    if( strcmp( First, "null" ) == 0 ){
      First = "Under";
    }else if ( strcmp( First, "Over") == 0 ){
      Second = "Under";
    }
  }
  
  if( strcmp( First, "Over") == 0 && strcmp( Second, "Under") == 0 ){
    Serial.println("Right");
    First = "null";
    Second = "null";
  }else if( strcmp( First, "Under") == 0 && strcmp( Second, "Over") == 0 ){
    Serial.println("Left");
    First = "null";
    Second = "null";
  }
  
}

int getX(){
  
  return analogRead(0);
  
}

int getY(){
  
  return analogRead(1);
  
}

int getZ(){
  
  return analogRead(2);
  
}
