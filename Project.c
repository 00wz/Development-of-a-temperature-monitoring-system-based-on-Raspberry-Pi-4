#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MIN_TEMP 20.0
#define MAX_TEMP 30.0

char _ip[] = "192.168.0.11";
char _port[] = "1883";
char _topic[] = "/node-red/temp";
char _bucket[] = "IoT";
char _password[] = "student1";

void pub(char message[], char ip[], char port[], char topic[], char bucket[], char password[])
{
  char command[256];
  command[0] = '\0';
  strcat(command, "mosquitto_pub -h ");
  strcat(command, ip);
  strcat(command, " -p ");
  strcat(command, port);
  strcat(command, " -t \"");
  strcat(command, topic);
  strcat(command, "\" -m \"");
  strcat(command, message);
  strcat(command, "\" -u \"");
  strcat(command, bucket);
  strcat(command, "\" -P \"");
  strcat(command, password);
  strcat(command, "\"");
  system(command);
}

float getRandom(float min, float max)
{
  return min + ( (float)rand() / (float)(RAND_MAX) ) * (max - min);
}

int main (void)
{
  while(1)
  {
    float temperature = getRandom(MIN_TEMP, MAX_TEMP);
    char msg[50];
    sprintf(msg, "%g", temperature);
    pub(msg, _ip, _port, _topic, _bucket, _password);
    sleep(1);
  }

  return 0 ;
}
