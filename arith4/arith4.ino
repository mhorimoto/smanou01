/* 
 *  Arithmetic Sample Program
 *
 *    Masafumi Horimoto <horimoto@holly-linux.com>
 *    22nd Nov. 2021
 *    This software is released under the MIT License.
 */

#define MAXBUF 64

int x,y,c;
char buf[64],*pbuf;

void setup(void) {
  int i;
  // Start serial port at 9600 bps
  Serial.begin(9600);
  Serial.println("---------------------");
  Serial.println("ARITH4 START VER:1.00");
  Serial.println("---------------------");
  x = 0;
  y = 0;
  c = 0;
  for(i=0;i<MAXBUF;i++) {
    buf[i] = (char)NULL;
  }
  pbuf = &buf[0];
  Serial.println("Enter X");
}

void loop(void) {
  long vadd,vsub,vmul,vdiv;
  int inb,i;

  if (Serial.available() > 0) {
    if (c==0) {
      inb = Serial.read();
      if (inb=='\n') {
        x = atoi(buf);
        c++;
        for(i=0;i<MAXBUF;i++) {
          buf[i] = (char)NULL;
        }
        pbuf = &buf[0];
        Serial.print("X=");
        Serial.println(x);
        Serial.println("Enter Y");
      } else {
        *pbuf = (char)inb;
        pbuf++;
      }
    } else if (c==1) {
      inb = Serial.read();
      if (inb=='\n') {
        y = atoi(buf);
        c++;
        for(i=0;i<MAXBUF;i++) {
          buf[i] = (char)NULL;
        }
        pbuf = &buf[0];
        Serial.print("Y=");
        Serial.println(y);
      } else {
        *pbuf = (char)inb;
        pbuf++;
      }
    }
  }
  if (c==2) {
    Serial.println("\nAnswers");
    vadd = (long)x + (long)y;
    vsub = (long)x - (long)y;
    vmul = (long)x * (long)y;
    vdiv = (long)x / (long)y;
    c=0;
    Serial.print(x);
    Serial.print("+");
    Serial.print(y);
    Serial.print("=");
    Serial.println(vadd);
    Serial.print(x);
    Serial.print("-");
    Serial.print(y);
    Serial.print("=");
    Serial.println(vsub);
    Serial.print(x);
    Serial.print("*");
    Serial.print(y);
    Serial.print("=");
    Serial.println(vmul);
    Serial.print(x);
    Serial.print("/");
    Serial.print(y);
    Serial.print("=");
    Serial.println(vdiv);
    Serial.println("\nEnter X");
  }
}

