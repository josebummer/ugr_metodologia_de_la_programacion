#include <iostream>
#include <cstring>

using namespace std;

void suma(char *v, char *n){
  for(int i=0;i<strlen(n);i++)
    v[i]=n[i];
  v[strlen(n)]='\0';
}

int main(int argc, char const *argv[]) {
  char v[] = "Hola";
  char *p =new char [strlen(v)];
  char n[5];
  cout << strlen(v);
  int i=0;

  suma(n,v);

  while(n[i]!='\0'){
    cout << n[i];
    i++;
  }

  return 0;
}
