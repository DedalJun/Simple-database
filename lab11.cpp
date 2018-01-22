#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

 struct guildy
  {
    char naimenuvannya[15];
    char country[15];
    char data[15];
    int kaprem;
    int nguild;
    int price;
    char gab[30];
   } guild,guild1,guild2;
    

     int p=5;
     int OutPut();
     int Dop();
     int OutTextPut();
     int Cor1();
     int Cor2();
     int Corr();
     int Obr();

 int main()
  {
    int q;
     do
      {
        cout<<"Rezimi roboti programi"<<endl;
        cout<<" 1 - Organizatsia failu z informatsieu"<<endl;;
        cout<<" 2 - Dopovnenja failu novou informatsieu"<<endl;;
        cout<<" 3 - Vivid informatsii iz bazi v tekstovij fajl"<<endl;;
        cout<<" 4 - Koriguvannja failu z informatsieu"<<endl;;
        cout<<" 5 - Obrobka fajlu z informatsieu"<<endl;;
        cout<<" 0 - Vixid ";
        cin>>q;

         switch (q)
          {
            case 1: OutPut(); break;
            case 2: Dop(); break;
            case 3: OutTextPut(); break;
            case 4: Corr(); break;
            case 5: Obr(); break;
            case 0: break;
            default: printf("\n Pomilka, vkazitj pravelno rezim roboti");
           }
         }
        while(q!=0);
         return 0;
  }
    int OutPut()
     { 
       int t,i;
       char name[40],s;
        cout<<" Vkazit imja fajlu dlja zberezennja informatsii ";
        cin>>name;
         ofstream f_out;
          f_out.open(name,ios::in);
           if (!f_out)
            {
              cerr<<"out file ne moge buti vidkritim"<<endl;
              exit(1);
             }
          while(1)
           {
             cout<<" Vkazit naimenuvannja obladnannja - ";
             cin>>guild.naimenuvannya;
             t=stricmp(guild.naimenuvannya, "zzz");
              if (!t) break;
               cout<<" Vkazit krainu vyrobnika - ";
               cin>>guild.country;
                cout<<" Vkazit datu pochatku expluatacii - ";
                cin>>guild.data;
                 cout<<" Vkazit kilkist kapremontiv - ";
                 cin>>guild.kaprem;
                  cout<<" Vkazit nomer tsehu - ";
                  cin>>guild.nguild;
                   cout<<" Vkazit tsinu obladnannja - ";
                   cin>>guild.price;
                    cout<<" Vkazit gabaryty obladnannja - ";
                    cin>>guild.gab; 
               f_out.write((char*)&guild,sizeof(guild));
             }
           f_out.close();
           return 0;
        }

 int OutTextPut()
  {
    char name1[40], name2[40];
     cout<<" Vkazit imja fajlu z informatsieu ";
     cin>>name1;
      ifstream f_out;
      f_out.open(name1,ios::out);
       if (!f_out)
        {
          cerr<<"out file ne moge buti vidkritim "<<endl;
          exit(1);
         }
        cout<<" Vkazit imja failu dlja zberezennja neobxidnoi informatsii ";
        cin>>name2;
         ofstream f_in;
         f_in.open(name2,ios::in);
          if (!f_in)
           {
             cerr<<"text file ne moge buti vidkritim "<<endl;
             exit(1);
           }
            while (!f_out.eof())
             {
               f_out.read((char*) &guild, sizeof(guild));
               f_in<<guild.naimenuvannya<<" "<<guild.country<<" "<<guild.data<<" "<<guild.kaprem<<" "<<guild.nguild<<" "<<guild.price<<" "<<guild.gab ;
               f_in<<"\n";
              }
           f_out.close();
           f_in.close();
          return (0);
   }

 int Dop()
  {
    char name[40];
    int t;
     cout<<" Vkazit imja fajlu dlja dopovnenja informatsii ";
     cin>>name;
      ofstream f_dop;
      f_dop.open(name,ios::app);
       if (!f_dop)
        {
          cerr<<" file ne moge buti vidkritim "<<endl;
          exit(1);
         }
         while(1)
           {
             cout<<"Vkazit naimenuvannja obladnannja - ";
             cin>>guild.naimenuvannya;
             t=stricmp(guild.naimenuvannya, "zzz");
              if (!t) break;
               cout<<"Vkazit krainu vyrobnika - ";
               cin>>guild.country;
                cout<<" Vkazit datu pochatku expluatacii - ";
                cin>>guild.data;
                 cout<<" Vkazit kilkist kapremontiv - ";
                 cin>>guild.kaprem;
                  cout<<" Vkazit nomer tsehu - ";
                  cin>>guild.nguild;
                   cout<<" Vkazit tsinu obladnannja - ";
                   cin>>guild.price;
                    cout<<" Vkazit gabaryty obladnannja - ";
                    cin>>guild.gab; 
               f_dop.write((char*)&guild,sizeof(guild));
             }
           f_dop.close();
           return 0;
        }

  int Cor1()
   {
     int q;
     char name[100],g;
      cout<<" Vvedi imja failu dlja koriguvannja "<<endl;
      cin>>name;
       ofstream f_corr;
       f_corr.open(name,ios::ate);
        if (!f_corr)
         {
           cerr<<"file ne moge buti vidkritim"<<endl;
           exit(1);
          }
          cout<<" Vvediporjadkovyi nomer zapisu - ";
          cin>>q;
           while(1)
            {
             cout<<"Vkazit naimenuvannja obladnannja - ";
             cin>>guild.naimenuvannya;
               cout<<"Vkazit krainu vyrobnika - ";
               cin>>guild.country;
                cout<<" Vkazit datu pochatku expluatacii - ";
                cin>>guild.data;
                 cout<<" Vkazit kilkist kapremontiv - ";
                 cin>>guild.kaprem;
                  cout<<" Vkazit nomer tsehu - ";
                  cin>>guild.nguild;
                   cout<<" Vkazit tsinu obladnannja - ";
                   cin>>guild.price;
                    cout<<" Vkazit gabaryty obladnannja - ";
                    cin>>guild.gab; 
               f_corr.seekp((q-1)*sizeof(guild));
               f_corr.write((char*) &guild, sizeof(guild));
                cout<<" Zakinchiti koriguvannya? (y/n) ";
                cin>>g;
                 if (g=='y'||g=='Y'||g=='í'||g=='Í') break;
                
             }
           f_corr.close();
           return 0;   
        }

  int Cor2()
   {
     int q,r;
     char name[100],g;
      cout<<" Vvedi imja failu dlja koriguvannja - ";
      cin>>name;
       fstream f_corr;
       f_corr.open(name,ios::ate|ios::out|ios::in);
        if (!f_corr)
         {
           cerr<<"file ne moge buti vidkritim"<<endl;
           exit(1);
          }
          while(1)
           {
             cout<<"Vvedi porjadkovij nomer zapisu - ";
             cin>>q;
              f_corr.seekg((q-1)*sizeof(guild));
              f_corr.read((char*) &guild, sizeof(guild));
               cout<<" Regimi koriguvannja"<<endl;
               cout<<" 1-Naimenuvannja obladnannja"<<endl;
               cout<<" 2-Kraina vyrobnyk"<<endl;
               cout<<" 3-Data expluatacii"<<endl;
               cout<<" 4-Kilkist kapremontiv"<<endl;
               cout<<" 5-Nomer tsehu"<<endl;
               cout<<" 6-Vartist"<<endl;
               cout<<" 7-Gabarity"<<endl;
               cin>>r;
              switch(r)
               {
                 case 1: cout<<" Vkazit naimenuvannya obladnannja - ";
                         cin>>guild.naimenuvannya; break;
                 case 2: cout<<" Vvedit krainu vyrobnyka - ";
                         cin>>guild.country; break;
                 case 3: cout<<" Vvedit daty expluatacii - ";
                         cin>>guild.data; break;
                 case 4: cout<<" Vvedit kilkist kapremontiv - ";
                         cin>>guild.kaprem; break;
                 case 5: cout<<" Vedit nomer tsehu - ";
                         cin>>guild.nguild; break;
                 case 6: cout<<" Vvedit vartist - ";
                         cin>>guild.price; break;
                 case 7: cout<<" Vvedit gabaryty obladnannja - ";
                         cin>>guild.gab; break;
                 case 0: break;
                 default: cout<<" Pomilka, vkazitj pravelnjo reziroboti";
                }
                f_corr.seekp((q-1)*sizeof(guild));
                f_corr.write((char*) &guild, sizeof(guild));
                 cout<<"Zakinchiti koriguvanja? (y/n) ";
                 cin>>g;
                  if(g=='y'||g=='Y'||g=='í'||g=='Í') break;
            }
             f_corr.close();
             return 0;
   }
  
  int Corr()
   {
     char s;
      cout<<" Koriguvaty vsu zapis? (y/n) ";
      cin>>s;
       if (s=='y'||s=='Y'||s=='í'||s=='Í') Cor1();
        else Cor2();
         return 0;
    }

  int Obr()
   {
     char name1[40], name2[40];
     int s;
      cout<<" Vkazit imja fajlu z informatsieu ";
      cin>>name1;
       ifstream f_obr;
       f_obr.open(name1,ios::out);
        if(!f_obr)
         {
           cerr<<"obr_file ne moge buti vidkritim "<<endl;
           exit(1);
          }
          cout<<" Vkazit imja failu dlja zberezennja neobxidnoi informatsii ";
          cin>>name2;
           ofstream f_in;
           f_in.open(name2,ios::in);
            if(!f_in)
             {
               cerr<<"out file ne moge buti vidkritim "<<endl;
               exit(1);
              }
               cout<<"Vvedit porih tsiny - ";
               cin>>s; 
              while (!f_obr.eof())
               {
                 f_obr.read((char*) &guild, sizeof(guild));
                 if (guild.price>s) f_in<<guild.naimenuvannya<<" "<<guild.country<<" "<<guild.data<<" "<<guild.kaprem<<" "<<guild.nguild<<" "<<guild.price<<" "<<guild.gab<<" " ;
                 f_in<<"\n";
               }
           f_obr.close();
           f_in.close();
       return (0);
   }
