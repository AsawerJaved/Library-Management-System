#include <iostream>
using namespace std;
int main()
{    
    int no_of_books,option,return_no_of_books,count=0,teacher=1,student=1;       //other variables
    
    int age[20],roll[20];           //declaration of int type arrays 
    char gndr[20],person[20];           //declaration of char type arrays
    
    int nmbr_of_books[6]={5,3,6,9,8,5};       // number of respective books
	int iban[6]={32434,53555,35654,98987,68429,48294};
	int edition[6]={4,5,2,3,1,6};
	int price[6]={550,500,350,470,700,850};
	int release_year[6]={2001,2004,1998,2013,2010,2019};         //storing books' information
    
    char choice;               //loop control variables
    int i=0;              //index variable
    
    while (choice!='e')
    {
        while(1) //data entry of student/teacher 
        {
            cout<<"\nEnter s if you are a student and t if you are a teacher: ";
            cin>>person[i];
            
            while (person[i]>='a'&&person[i]<='z')
            {
                if (person[i]=='s')
                {
                    cout<<"Enter your roll number (use only digits): ";
                    cin>>roll[i];
                    while(roll[i]<=0)
                    {
                        cout<<"Invalid... try again: ";
                        cin>>roll[i];
                    }
                    break;
                }
                else if (person[i]=='t')
                {
                    cout<<"Enter your employ ID number (use only digits): ";
                    cin>>roll[i];
                    while(roll[i]<=0)
                    {
                        cout<<"Invalid... try again: ";
                        cin>>roll[i];
                    }
                    break;
                }
                else
                    cout<<"Invalid... try again: ";
                    cin>>person[i];
            }
            cout<<"Enter your gender press m for male and f for female: ";
            cin>>gndr[i];
            while(gndr[i]!='f'&&gndr[i]!='m')
            {
                cout<<"Invalid... try again: ";
                cin>>gndr[i];
            }
            cout<<"Enter your age: ";
            cin>>age[i];
            while(age[i]<=0 )
            {
                cout<<"Invalid... try again: ";
                cin>>age[i]; 
            }
            break;
        }
        char action;
        cout<<"\nEnter 'i' if you want the library to issue you a book and 'r' if you want to return the book: ";
        cin>>action;
		while(action>='a'&&action<='z')  
		{
			if (action=='i')  //if the student/teacher want to issue
        	{
        		cout<<"--------------------------------------------------------------------"<<endl<<endl;
            	if (nmbr_of_books[0]>1)
            	cout<<"Enter 1 to select 'Jannat kay Pattay' with IBAN number "<<iban[0];
        	    if (nmbr_of_books[1]>1)
            	cout<<"\nEnter 2 to select 'Namal' with IBAN number "<<iban[1];
            	if (nmbr_of_books[2]>1)
            	cout<<"\nEnter 3 to select 'Yaram' with IBAN number "<<iban[2];
            	if (nmbr_of_books[3]>1)
            	cout<<"\nEnter 4 to select 'Bachpan ka December' with IBAN number "<<iban[3];
            	if (nmbr_of_books[4]>1)
            	cout<<"\nEnter 5 to select 'Amarbail' with IBAN number "<<iban[4];
            	if (nmbr_of_books[5]>1)
            	cout<<"\nEnter 6 to select 'Haalim' with IBAN number "<<iban[5];
            	cout<<"\n\n--------------------------------------------------------------------"<<endl;
            	cout<<"Enter your choice: ";
            	cin>>option;
            	
				while(option>7) 
				{
					cout<<"Sorry Library doesn't contain this book, try any other: ";
            		cin>>option;
				} 
            	while (nmbr_of_books[option-1]<=1)
            	{
            		cout<<"Sorry you cannot have this book, try any other: ";
            		cin>>option;
				}
				cout<<"How many books you want: ";
            	cin>>no_of_books;
            	while (nmbr_of_books[option-1]-no_of_books<=1)
            	{
            	   cout<<"Sorry you can have only "<<nmbr_of_books[option-1]-1<<" books"<<endl;
            	   cout<<"How many books you want: ";
            	   cin>>no_of_books;
            	}
            	nmbr_of_books[option-1] -= no_of_books;         // decrement no of selected books
            	break;
        	}
        	else if (action=='r') //if the student/teacher want to return
        	{
        		cout<<"--------------------------------------------------------------------"<<endl<<endl;
            	cout<<"Enter 1 to return 'Jannat kay Pattay' with IBAN number "<<iban[0];
            	cout<<"\nEnter 2 to return 'Namal' with IBAN number "<<iban[1];
            	cout<<"\nEnter 3 to return 'Yaram' with IBAN number "<<iban[2];
            	cout<<"\nEnter 4 to return 'Bachpan ka December' with IBAN number "<<iban[3];
            	cout<<"\nEnter 5 to return 'Amarbail' with IBAN number "<<iban[4];
            	cout<<"\nEnter 6 to return 'Haalim' with IBAN number "<<iban[5]<<"\n";
            	cout<<"\n--------------------------------------------------------------------"<<endl;
            	cout<<"Enter your choice: ";
            	cin>>option; 
            	
            	while(option>7) 
				{
					cout<<"Sorry this book doesn't belongs to this Library, try any other: ";
            		cin>>option;
				}
            	cout<<"How many books you are returning: ";
            	cin>>return_no_of_books; 
            	nmbr_of_books[option-1] += return_no_of_books;
            	break;
        	}
        	else
        	{
        		cout<<"Invalid... try again: ";
        		cin>>action;
			}
		}
		i++;
        cout<<"\nEnter e to exit or any other character to repeat"<<endl;
        cin>>choice;
        if (choice=='e')
            break;
    }  	 
    cout<<"----------------------------------------------------------------------------\n"<<endl;
    for(int a=0;a<i;a++)         // sorting details of student and teachers w.r.t age
    {
        for(int b=0;b<i-a-1;b++)
        {
            if(age[b]>age[b+1])
            {
            	int ag=age[b];
				age[b]=age[b+1];
				age[b+1]=ag;
				
				int rol=roll[b];
				roll[b]=roll[b+1];
				roll[b+1]=rol;
				
				char gnd=gndr[b];
				gndr[b]=gndr[b+1];
				gndr[b+1]=gnd;
				
				char per=person[b];
				person[b]=person[b+1];
				person[b+1]=per;
            }
        }
    }
    for (int j=0;j<=5;j++)          // final details of books
    {
        cout<<"Book "<<j+1<<" with IBAN number "<<iban[j]<<" edition "<<edition[j]<<" with price of "<<price[j]<<" released in year "<<release_year[j]<<" and we have "<<nmbr_of_books[j]<<" of them currently available in library."<<endl;
    }
    cout<<"\n-------------------------------------------------------------------------------"<<endl;
    for(int j=0;j<i;j++)           //final data of student/teacher issuing or returning book(s)
    {
        if (person[j]=='s')
        {
            cout<<"Student "<<student<<" has roll number "<<roll[j]<<" and age "<<age[j]<<" and gender ";
            if (gndr[j]=='m')
            cout<<"male"<<endl;
            else if (gndr[j]=='f')
            cout<<"female"<<endl;  
            student++;
        }
        else
        {
            cout<<"Teacher "<<teacher<<" has employ ID number "<<roll[j]<<" and age "<<age[j]<<" and gender ";
            if (gndr[j]=='m')
            cout<<"male"<<endl;
            else if (gndr[j]=='f')
            cout<<"female"<<endl;  
            teacher++;
        }
    }
    return 0;
}
