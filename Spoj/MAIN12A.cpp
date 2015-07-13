#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
class BUFFER
{
  static const int BUFSIZE = 1<<16;
  char *buffer;
  char *bufpos;
  char *bufend;
public:
  BUFFER() { bufpos = buffer = new char[BUFSIZE]; }
  ~BUFFER() { delete[] buffer; }
protected:
  void grabBuffer()
  {
    bufpos = buffer;
    bufend = buffer + fread(buffer, sizeof(char), BUFSIZE, stdin);
  }
  void flushBuffer()
  {
    fwrite(buffer, sizeof(char), bufpos - buffer, stdout);
    bufpos = buffer;
  }
  inline char getChar()
  {
    if (bufpos==bufend) grabBuffer();
    return *bufpos++;
  }
  inline void putChar(char c)
  {
    *bufpos++ = c;
    if (bufpos >= buffer+BUFSIZE) flushBuffer();
  }
};
 
class IN : BUFFER
{
public:
  IN() { grabBuffer(); }
  int readInt()
  {
    int result = 0, c;
    do { c = getChar(); } while (c <= ' ');
    while (('0' <= c) && (c <= '9'))
    {
      result *= 10;
      result += c - '0';
      c = getChar();
    }
    return result;
  }
};
 
class OUT : BUFFER
{
public:
  ~OUT() { flushBuffer(); }
  inline void write(char c)
  {
    putChar(c);
  }
  inline void write(int x)
  {
    if (x == 0) { putChar('0'); return; }
    char tmp[10];
    int tp = 0;
    while (x) { tmp[tp++] = x%10; x /= 10; }
    while (tp--) putChar(tmp[tp] + '0');
  }
  inline void write(const char*s)
  {
    while(*s) write(*s++);
  }
};

IN input;
OUT output;


int ar[1000005] = {0};

void solve()
{
  ar[1] = 1;
  ar[2] = 2;
  int st = 3;
  int count = 2; // number 
  int j = 2;
  int i = 3;
  while(1)
  {
    for(int k = 0;k<count;k++)
    {
      if(i+k > 1000000) return;
      ar[i+k] = st;
    } 
    i = i+count;
    count = ar[++j];
    st++; 
  }
}

int main()
{
  int t;
  solve();
  t = input.readInt();
  for(int i=1;i<=t;i++)
  {
    int n;
    n = input.readInt();
    printf("Case #%d: %d\n",i,ar[n]);
  }
}
