#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main ()
{
    int a, b, c[30], d, r = 0, d1,err[10]={0}, escolha; //Max bits here i kept is 30
    cout << "Digite a quantidade de bits de dados que você deseja inserir: ";
    cin >> a;
    
    cout << "Qual paridade? 1-IMPAR OU 0-PAR:";
    cin >> escolha;
    
    while (a + r + 1 > pow (2, r))
    {
      r++;
    }
    cout << "Número de bits de dados redundantes a serem adicionados " << r << " : Total de Bits(data+ redundant) :" << a +
    r << endl;
    cout << "Insira os bits de dados (UM A UM) :" << endl;
    for (int i = 1; i <= a; ++i)
        cin >> c[i];
    cout << endl << "Bits de dados inseridos : ";
    for (int i = 1; i <= a; ++i)
        cout << c[i] << " ";
    cout << endl;
    int data[a + r],res[a+r];
    d = 0;
    d1 = 1;
    for (int i = 1; i <= a + r; ++i)
    {
      if ((i) == pow (2, d))
        {
        data[i] = 0;
        ++d;
        }
      else
        {
        data[i] = c[d1];
        ++d1;
        }
    }
    cout << "Os bits de dados são codificados com bits de paridade (0): ";
    for (int i = 1; i <= a + r; ++i)
        cout << data[i] << " ";
    d1 = 0;
    int min, max = 0, parity, s, j;
    /*Parity Bit Calculation */
    for (int i = 1; i <= a + r; i = pow (2, d1))
    {
      ++d1;
      parity = 0;
      j = i;
      s = i;
      min = 1;
      max = i;
      for (j; j <= a + r;)
    {
        for (s = j; max >= min && s <= a + r; ++min, ++s)
        {
        if (data[s] == 1)
            parity++;
        }
        j = s + i;
        min = 1;
    }
      
    if(escolha == 0){    
    if (parity % 2 == 0) // Even Parity
    {
    data[i] = 0;
    }
      else
    {
    data[i] = 1;
    }
    }
    
    if(escolha == 1){    
    if (parity % 2 == 0) // odd Parity
    {
    data[i] = 1;
    }
      else
    {
    data[i] = 0;
    }
    }
    
    }
    
      
    cout << endl << "A sequencia final transmitida para paridade selecionada é : ";
    for (int i = 1; i <= a + r; ++i)
        cout << data[i] << " ";
    cout << endl << endl;

    cout<<"(Digite a mensagem recebida)"<<endl;
    cout << "Insira os bits de dados (UM A UM) :" << endl;
    for (int i = 1; i <= a+r; ++i)
        cin >> res[i];
    d1 = 0;max=0;int ec=0;
    //int min, max = 0, parity, s, j;
    /*Parity Bit Calculation */
    for (int i = 1; i <= a + r; i = pow (2, d1))
    {
      ++d1;
      parity = 0;
      j = i;
      s = i;
      min = 1;
      max = i;
      for (j; j <= a + r;)
    {
        for (s = j; max >= min && s <= a + r; ++min, ++s)
        {
        if (res[s] == 1)
            parity++;
        }
        j = s + i;
        min = 1;
    }
    
    if(escolha==0){
     if (parity % 2 == 0) // Even Parity
    {
    err[ec]=0;
    ec++;
    }
      else
    {
    err[ec]=1;
    ec++;
    }   
    }
    
    if(escolha==1){
     if (parity % 2 == 0) // Odd Parity
    {
    err[ec]=1;
    ec++;
    }
      else
    {
    err[ec]=0;
    ec++;
    }   
    } 
    
    
    }
    int flag = 1;
    for(int i =r-1;i>=0;i--)
    {
        if(err[i]==1)
        {
            flag =0;
                break;
        }
    }
    if(flag==0)
    {
        int pos=0;
    cout<<"Erro detectado em: ";
    for(int i =r-1;i>=0;i--)
    {
        cout<<err[i]<<" ";
        if(err[i]==1)
            pos+=pow(2,i);
    }
        cout<<"\nPosição de erro :"<<pos;
        res[pos]=!res[pos];
        cout<<"\nApós correção: ";
        for(int i =1;i<=a+r;i++)
          cout<<res[i]<<" ";
    }
    else
       cout<<"Nenhum erro foi detectado. ";

}
//End
