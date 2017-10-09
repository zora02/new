#include<iostream>
#include <time.h>
#include <stdlib.h>
#include<time.h>
#include<fstream>

#define STUNUM 300
#define DEPNUM 20
using namespace std;


int main()
{
	ofstream file;
	file.open("input_data.text");
	srand((unsigned)time(NULL)); 
	string tags[10]={"study","film","English","music","reading","chess","football","dance","programming","basketball"};
	  //10个标签 
	string applicationDep[20]={"D001","D002","D003","D004","D005","D006","D007","D008","D009","D010","D011","D012","D013",
	"D014","D015","D016","D017","D018","D019","D020"};
	string a="031502001";
	int num=atoi(a.c_str() );
	file<<"{\n";
	file<<"    \"students\": [\n";
	for(int i=0;i<STUNUM;i++)
	{
		file<<"        {\n            \"free_time\": [\n";
		
		
		int randTime;
	    int TimeNum;
	    TimeNum=4+rand()%6;   //产生4-9个空闲时间
	    for(int i=0;i<TimeNum;i++)
	    { 
	    string day[7]={"Sun","Mon","Tues","Wed","Thur","Fri","Sat"};
	    file<<"                \"";
	    file<<day[rand()%7];
	    file<<".";
	    randTime=8+rand()%15;
	    file<<randTime<<":00~"<<randTime+2;
	    if(i<TimeNum-1)
	    file<<":00\","<<endl;
	    else
	    file<<":00\""<<endl;
        }
		
		
		//这里是输入时间
		file<<"            ],\n";
		file<<"            \"student_no\": \""; 
		file<<"0"<<num;
		num++;
		file<<"\",\n";
		file<<"            \"applications_department\": [\n";
		int applyDepNum=rand()%5+1;
		int randNum[20];
		int state[20]={0};
		for(int j=0;j<applyDepNum;j++)
		{
			randNum[j]=rand()%20;
			while(state[randNum[j]]==1)
			{
				randNum[j]=rand()%20;
			}
			state[randNum[j]]=1;
		}
		for (int j=0;j<applyDepNum;j++)
		{
			if(j<applyDepNum-1)
			{
			    file<<"                \""<<applicationDep[randNum[j]]<<"\",\n";
			}
			else
			{
				file<<"                \""<<applicationDep[randNum[j]]<<"\"\n";
			}
		}
		file<<"            ],\n";
		file<<"            \"tags\": [\n";

		int tagsNum=2+rand()%3;
		int randNum2[10];
		int state2[10]={0};
		for(int j=0;j<tagsNum;j++)
		{
			randNum2[j]=rand()%10;
			while(state2[randNum2[j]]==1)
			{
				randNum2[j]=rand()%10;
			}
			state2[randNum2[j]]=1;
		}
		for(int j=0;j<tagsNum;j++)
		{
			if(j<tagsNum-1)
			{
			    file<<"                \""<<tags[randNum2[j]]<<"\",\n";
			}
			else
			{
				file<<"                \""<<tags[randNum2[j]]<<"\"\n";
			}
			
		}
		if(i<STUNUM-1)
		file<<"            ]\n        },\n";	
		else
		{
			file<<"            ]\n        }\n    ],\n";
		}	
	}
	
	//生成社团信息
	file<<"    \"departments\": [\n";
	for (int i=0;i<DEPNUM;i++)
	{
		file<<"        {\n            \"event_schedules\": [\n";
		//
		
		int randTime2;
	    int TimeNum2;
	    TimeNum2=1+rand()%5;   //产生1-5个会议时间
	    for(int i=0;i<TimeNum2;i++)
	    { 
	    string day[7]={"Sun","Mon","Tues","Wed","Thur","Fri","Sat"};
	    file<<"                \"";
	    file<<day[rand()%7];
	    file<<".";
	    randTime2=8+rand()%15;
	    file<<randTime2<<":00~"<<randTime2+1;
	    if(i<TimeNum2-1)
	    file<<":00\","<<endl;
	    else
	    file<<":00\""<<endl;
        }
		
		
		
		//
		
		file<<"            ],\n";
		file<<"            \"member_limit\": ";
		file<<(10+rand()%6);
		file<<",\n";
		if(i<9)
		{
		    file<<"            \"department_no\": \"D00"<<i+1<<"\",\n";
		}
		if(i>=9)
		{
			file<<"            \"department_no\": \"D0"<<i+1<<"\",\n";
		}
		
		
		
		
		int tagsNum=2+rand()%6;
		int randNum3[10];
		int state3[10]={0};
		file<<"            \"tags\": [\n";
		for(int j=0;j<tagsNum;j++)
		{
			randNum3[j]=rand()%10;
			while(state3[randNum3[j]]==1)
			{
				randNum3[j]=rand()%10;
			}
			state3[randNum3[j]]=1;
		}
		for(int j=0;j<tagsNum;j++)
		{
			if(j<tagsNum-1)
			{
			    file<<"                \""<<tags[randNum3[j]]<<"\",\n";
			}
			else
			{
				file<<"                \""<<tags[randNum3[j]]<<"\"\n";
			}
			
		}
		if(i<DEPNUM-1)
		file<<"            ]\n        },\n";	
		else
		{
			file<<"            ]\n        }\n    ]\n}";
		}			
	}
	file.close();
	return 0;		
} 

