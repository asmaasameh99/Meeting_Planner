#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstddef>
#include <cctype>
#include <bits/stdc++.h>
#include "BST.h"

using namespace std;

int main(int argc , char*argv[])
{
    BST t;


    ifstream file_name(argv[1]);
    /*Reading file*/
    if (!file_name.is_open())
    {
        cout<<"File not found"<<endl;
    }
	else if(argc!=2)
        {
            cout<<"Invalid arguments"<<endl;

        }
    else if  (file_name.is_open())
            {
                    string line;
                while(getline(file_name,line))
                {
                    string tmp;
                    string linee,lineee;
                    string line2="";
                    string argu[10];
                    int oper[30];
                    int cursor=1;


                    int length;
                    istringstream ss(line);
                    int counter=0;
                    while(ss>>tmp)
                    {
                        argu[counter]=tmp;
                        oper[counter]=tmp.length();
                        //cout<<argu[counter]<<endl;
                        counter++;

                    }

					bool titlee=false;
					bool hourrr=false;
					bool dayyy=false;


					if (argu[0]=="ADD")
					{
						lineee=argu[1];
						if(lineee[0]!='"')
							   {
								 cout<<"Invalid title"<<endl;
								 titlee=true;

							   }
						else
						{

							while (argu[cursor][oper[cursor] - 1]!='"')
								cursor++;
							for (int j=1;j<=cursor;j++)
								line2=line2+argu[j]+" ";
							//cout<<line2<<endl;
							line2.erase(line2.size() - 1);
						}
						//cout<<line2<<endl;
						//cout<<argu[cursor+1]<<endl<<argu[cursor+2]<<endl;
						stringstream days(argu[cursor+1]);
						stringstream hours(argu[cursor+2]);
						int day=0;
						int hour=0;
						float dayf=0;
						float hourf=0;
						days>>dayf;
						day=dayf;
						hours>>hourf;
						hour=hourf;


						if ( (day<=0)||(day>365) || !(float(day)==dayf))
						{
							cout<<"Invalid day"<<endl;
							dayyy=true;

						}
						if ((hour<0)|| (hour>23)|| !(float(hour)==hourf) )
						{
							cout<<"Invalid hour"<<endl;
							hourrr=true;
						}
					    if (titlee||dayyy||hourrr)
							continue;
						else
							t.ADD(line2,day,hour);
                        }

                    else if(argu[0]=="MOD")
					{
						lineee=argu[1];
						if(lineee[0]!='"')
							   {
								 cout<<"Invalid title"<<endl;
								 titlee=true;

							   }
						else
						{

							while (argu[cursor][oper[cursor] - 1]!='"')
								cursor++;
							for (int j=1;j<=cursor;j++)
								line2=line2+argu[j]+" ";
							//cout<<line2<<endl;
							line2.erase(line2.size() - 1);

						}
						//cout<<line2<<endl;
						//cout<<argu[cursor+1]<<endl<<argu[cursor+2]<<endl;
						stringstream days(argu[cursor+1]);
						stringstream hours(argu[cursor+2]);
						int day=0;
						int hour=0;
						days>>day;
						hours>>hour;

						if ( (day<=0)||(day>365))
						{
							cout<<"Invalid day"<<endl;
							dayyy=true;
						}
						else if ((hour<0)|| (hour>23))
						{
							cout<<"Invalid hour"<<endl;
							hourrr=true;
						}
					    if (titlee||dayyy||hourrr)
							continue;
						else
							t.modify(line2,day,hour);

					}

					else if (argu[0]=="Find")
					{

						stringstream days(argu[1]);
						stringstream hours(argu[2]);

						int day=0;
						int hour=0;
						float dayf=0;
						float hourf=0;
						days>>dayf;
						day=dayf;
						hours>>hourf;
						hour=hourf;


						if ( (day<=0)||(day>365) || !(float(day)==dayf))
						{
							cout<<"Invalid day"<<endl;
							dayyy=true;

						}
						if ((hour<0)|| (hour>23)|| !(float(hour)==hourf) )
						{
							cout<<"Invalid hour"<<endl;
							hourrr=true;
						}
					    if (dayyy||hourrr)
							continue;
						else
							t.find(day,hour);
					}

 					else if (argu[0]=="DEL")
					{

						stringstream days(argu[1]);
						stringstream hours(argu[2]);

						int day=0;
						int hour=0;
						float dayf=0;
						float hourf=0;
						days>>dayf;
						day=dayf;
						hours>>hourf;
						hour=hourf;


						if ( (day<=0)||(day>365) || !(float(day)==dayf))
						{
							cout<<"Invalid day"<<endl;
							dayyy=true;

						}
						if ((hour<0)|| (hour>23)|| !(float(hour)==hourf) )
						{
							cout<<"Invalid hour"<<endl;
							hourrr=true;
						}
					    if (dayyy||hourrr)
							continue;
						else if (t.retreive(day,hour))
                        {
                            //cout<<t.retreive(day,hour)<<endl;
							t.deletee(day,hour);
                        }
						else
							cout<<"Empty " << day<<" " <<hour<<endl;
					}

					else if (argu[0]=="Print")
					{
                        if(t.isEmpty())
                            cout<<"Empty Planner"<<endl;
                        else
                            t.Display();
					}

                    else
					{
						cout<<"Invalid command"<<endl;

					}



					}



            }

}








//    t.ADD("mariam",5,19);
//    t.ADD("aya",1,20);
//    t.ADD("ammar",3,22);
//    t.ADD("reem",4,20);
//    t.Display();
//    t.find(4,20);
//    t.find(5,20);
//    t.modify("Asmaa",1,20);
//    t.Display();
//    t.modify("Asmaa",5,20);














