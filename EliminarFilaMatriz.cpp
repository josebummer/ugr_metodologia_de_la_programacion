//Realizar un metodo para eliminar una fila de la matriz
void EliminarFila(int pos){
  if(pos>=0 && pos<nfilas){
    int **p,c=0;

    delete [] m[pos];
    m[pos]=0;

    }
    nfilas-=1;
    **p=new int *[nfilas];

    for(int i=0;i<nfilas;i++){
      if(i != pos){
        p[c]=m[i];
        c++;
      }
    }
    delete [] m;

    m=p;
  }
}

void EliminarColumnas(int col){
  if(col>=0 && col<ncolumnas){
    int *p,c=0;

    for(int i=0;i<nfilas;i++){
      p=new int [ncolumnas-1];
      for(int j=0;j<ncolumnas;j++){
        if(j != col){
          p[c]=m[i][j];
          c++;
        }
        m[i]=p;
      }
      delete [] p;
      p=0;
    }
    ncolumnas--;
  }
}
