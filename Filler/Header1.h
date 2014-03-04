#include "iostream"
#include "conio.h"
#include "string"
#include "windows.h"
#include "stdlib.h"
#include "fstream"
#include "time.h"
#include "fstream"

using namespace std;
using namespace System::Media;
using namespace System::Collections::Generic;
using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
  std::ifstream;


  char pnoun[10][100]={"Sally","Max","Alex","Jim","Moriarty"};
  char cnoun[10][100]={"dog","Pen","Bottle","Gloves","Knife","broom","watch"};

int pullout(int num)        //function to choose the movie according to the randno from the list of movies
{srand ((unsigned)time(0));
 return ((rand()%num));
}

void playsound(char *loc)    //function to play clip
 { SoundPlayer^ player = gcnew SoundPlayer();
   String^ temp=System::Runtime::InteropServices::Marshal::PtrToStringAnsi(IntPtr((loc)));
   player->SoundLocation = temp;
   player->Load();
   player->PlaySync();
 }

void laugh()
{char laughsound[20000]="C:\\Users\\AFREEN\\Downloads\\Kid Laughing Short-SoundBible.com-667826932.wav";			   
			   SoundPlayer^ player = gcnew SoundPlayer();
               String^ temp=System::Runtime::InteropServices::Marshal::PtrToStringAnsi(IntPtr((laughsound)));
               player->SoundLocation = temp;
               player->Load();
               player->PlaySync();
}

char* fill(char *given)    //this is the function that generates the _ _ _ array
{char arr[10000];
 strcpy(arr,given);
 arr[strlen(given)]='\0';
 
 
 int i=0,y,k,num=pullout(5);   //filling proper nouns
 for( ;arr[i]!='\0';i++)
 {if(arr[i]=='?')
    {for(y=0;pnoun[num][y+1]!='\0';y++,i++)
	  {int len1=strlen(arr);
	   arr[len1+1]='\0';
	   for(k=len1;k>i;k--)   //shifting to make 1 space in arr
		  arr[k]=arr[k-1];           
        //arr[k]='\0';                //making end null
        arr[k]=pnoun[num][y];            //putting yth elemnt of pnoun in ith place of arr
      }
     arr[i]=pnoun[num][y]; 
    }
  }
 int len=strlen(given)+strlen(pnoun[num])-1;
 arr[len]='\0';


 char arr1[10000];
 strcpy(arr1,arr);
 arr1[len]='\0';

 i=0,y,k,num=pullout(7);   //filling common nouns
 for( ;arr1[i]!='\0';i++)
 {if(arr1[i]=='!')
    {for(y=0;cnoun[num][y+1]!='\0';y++,i++)
	  {int len1=strlen(arr1);
	   arr1[len1+1]='\0';
	   for(k=len1;k>i;k--)   //shifting to make 1 space in arr
		  arr1[k]=arr1[k-1];           
        //arr[k]='\0';                //making end null
        arr1[k]=cnoun[num][y];            //putting yth elemnt of pnoun in ith place of arr
      }
     arr1[i]=cnoun[num][y]; 
    }
  }
 len=strlen(arr1)+strlen(cnoun[num])-1;
 arr1[len]='\0';




 return arr1;
}
 /*for( ;(unsigned)i<strlen(test);i++)
  {if(test[i]!=' ')
    arr[i]='_'; 
   else
    arr[i]=' ';
  }
  arr[i]='\0';*/


