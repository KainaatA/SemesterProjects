#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
#include<algorithm>
#include <fstream>
using namespace std;

class Author{
	public:
		string FirstName;
		string LastName;
		Author(string fn,string ln){
			this->FirstName=fn;
			this->LastName=ln;
		}
		void Display(){
			cout<<"First Name: "<<FirstName<<endl;
			cout<<"Last Name: "<<LastName<<endl;
		}
};
class AuthorNode{
	public:
		Author *data;
		AuthorNode *next;
};
class Article{
	public:
		string identifier;
		string title;
		string journal;
		string month;
		string year;
		string publisher;
		AuthorNode *author;
		Article(string identifier,string title,string journal,string month,string year,string publisher,AuthorNode *an){
			this->identifier=identifier;
			this->title=title;
			this->journal=journal;
			this->month=month;
			this->year=year;
			this->publisher=publisher;
			this->author=an;
		}
		void Display(){
			cout<<"Identifier: "<<identifier<<endl;
			cout<<"Title: "<<title<<endl;
			cout<<"Journal: "<<journal<<endl;
			cout<<"Month: "<<month<<endl;
			cout<<"Year: "<<year<<endl;
			cout<<"Publisher: "<<publisher<<endl;
		}
		void DisplayAuthors(){
			AuthorNode* temp=author;
			int count=1;
			while(temp!=NULL){
				cout<<"Author "<<count<<endl;
				temp->data->Display();
				cout<<endl;
				temp=temp->next;
				count++;
			}
		}
		void DisplayArticleName(){
			cout<<"Article: "<<title<<endl;
		}
		void DisplayJournalName(){
			cout<<"Journal: "<<journal<<endl;
		}
};

class ArticleNode{
	public:
		Article *data;
		ArticleNode *next;
};

class ListOfArticle{
	public:
		ArticleNode *start,*last;
		ListOfArticle(){
			start=NULL;
			last=NULL;
		}
		void InsertArticle(Article *article){
			ArticleNode *NN=new ArticleNode();
			NN->data=article;
			if(start==NULL){
				start=NN;
				last=start;
			}else{
				last->next=NN;
				last=NN;
			}
		}
		void Display(){
			int count=0;
			ArticleNode * temp=start;
			while(temp!=NULL){
				cout<<"\nArticle "<<count<<endl;
				temp->data->Display();
				cout<<endl;
				temp=temp->next;
				count++;
			}
		}
};

class ListOfAuthors{
	public:
		AuthorNode *start,*last;
		ListOfAuthors(){
			start=NULL;
			last=NULL;
		}
		void InsertAuthor(Author *author){
			AuthorNode *NN=new AuthorNode();
			NN->data=author;
			if(start==NULL){
				start=NN;
				last=NN;
			}
			else{
				last->next=NN;
				last=NN;
			}
		}
		void Display(){
			int count=1;
			AuthorNode *temp=start;
			while(temp!=NULL){
				cout<<"\nAuthor "<<count<<" : ";
				temp->data->Display();
				temp=temp->next;
				count++;
			}
		}
};

class AllAuthorsNode{
	public:
		string data;
		AllAuthorsNode *next;
		AllAuthorsNode *AList;
		ArticleNode *AListData;
};

class AllAuthorsList{
	public:
		
	AllAuthorsNode *start=NULL,*last=NULL,*temp=NULL;
	
	bool Exists(string name){
		bool check=false;
		temp=start;
		while(temp!=NULL){
			if(temp->data==name){
				check=true;
				break;
			}
			temp=temp->next;
		}
		return check;
	}	
	
	void InsertAllAuthors(string FirstName,string LastName){
		
		string name=FirstName+" "+LastName;
		if(Exists(name)==false){
			AllAuthorsNode *NN=new AllAuthorsNode();
			NN->data=name;
			if(start==NULL){
				start=NN;
				last=start;
			}
			else{
				last->next=NN;
				last=NN;
			}
		}
	}
	
	AllAuthorsNode* AuthorAdress(string name){
		AllAuthorsNode *temp=start;
		while(temp!=NULL){
			if(temp->data==name){
				return temp;
			}
			temp=temp->next;	
		}
	}
	
	void LinkArticleNodeWithAllAuthor(ArticleNode *article,AllAuthorsNode *author){
		AllAuthorsNode *node=new AllAuthorsNode();
		node->AListData=article;
		AllAuthorsNode *loc=new AllAuthorsNode();
		loc=author->AList;
		AllAuthorsNode *ploc=NULL;
		
		if(loc==NULL){
			author->AList=node;		
		}
		else{
			while(loc!=NULL){
				ploc=loc;
				loc=loc->next;
			}
			ploc->next=node;
		}
	}
	
	void DisplayAuthorArticle(string name){
		ArticleNode *article;
		int count=1;
		AllAuthorsNode *ArticleData;
		ArticleData=AuthorAdress(name)->AList;
		while(ArticleData!=NULL){
			article=ArticleData->AListData;
			cout<<"Article "<<count<<" : ";
			article->data->DisplayArticleName();
			cout<<endl;
			ArticleData=ArticleData->next;
			count++;
		}
		cout<<" Total no of Article published by "<<name<<" are: "<<count-1<<endl;
		cout<<endl;
	}
	void DisplayAuthor(){
		ofstream file_("Atuhors.txt");
		int count=0;
		AllAuthorsNode *temp=start;
		while(temp!=NULL){
			count++;
			if(file_.is_open()){
				if(count>5){
					file_<<temp->data<<"\n";
					cout<<temp->data<<endl;
				}
			}
			temp=temp->next;
		}
		
		file_.close();
	}
};

class coAuthorNode
{
    public:
    Article *data;
    int coAuthorCount;
    coAuthorNode *next;
};
class coAuthorList
{
    public:
    coAuthorNode *start=NULL,*current=NULL,*last=NULL;
    void insertData(Article *ArticleData,int coAuthor)
    {
        coAuthorNode *NN=new coAuthorNode();
        NN->data=ArticleData;
        NN->coAuthorCount=coAuthor;
        if(start==NULL)
        {
            start=NN;
            last=start;
        }
        else
        {
            last->next=NN;
            last=NN;
        }
    }
    void PrintALL()
    {
        coAuthorNode *temp=start;
        while(temp!=NULL)
        {
            temp->data->DisplayArticleName();
            cout<<"CO-AUTHORS: "<<temp->coAuthorCount<<endl;
            temp=temp->next;
        }
    }
};
class JournalNode
{
    public:
    Article *data;
    int JournalCount;
    JournalNode *next;
};
class JournalList
{
    public:
    JournalNode *start=NULL,*current=NULL,*last=NULL;
    void insertData(Article *ArticleData,int JournalCount)
    {
        JournalNode *NN=new JournalNode();
        NN->data=ArticleData;
        NN->JournalCount=JournalCount;
        if(start==NULL)
        {
            start=NN;
            last=start;
        }
        else
        {
            last->next=NN;
            last=NN;
        }
    }

    void PrintALL()
    {
        JournalNode *temp=start;
        while(temp!=NULL)
        {
            temp->data->DisplayJournalName();
            temp=temp->next;
        }
    }
};

class ReadFile{
	
	public:
		 string Fname;
		 string Lname;
		 ListOfArticle *listOfAA = new ListOfArticle();
		 AllAuthorsList *listAllAuthors=new AllAuthorsList();
		void Read()
		{
		  int field;
		  ifstream myFile("BibtexFileCS.csv");
		
		  if(!myFile.is_open())
		  {
		  	cout<<"Error opening File!";
		  }
		  else
		  {
		
			  string line;
			  string Identifier;
			  string Title;
			  string Journal;
			  string Month;
			  string Year;
			  string Publisher;
			  ListOfAuthors *list;
			  while(myFile.good())
			  {
					list=new ListOfAuthors();
					getline(myFile,line);
				
				    stringstream ss(line);
					
					field=1;
					
				
				while( ss.good() )
					{
						string substr;
					    getline( ss, substr,',');
					    substr.erase(std::remove(substr.begin(), substr.end(), '"'), substr.end());
					    if(field==1)
					    {
					    	Identifier=substr;
						}
						if(field==2)
					    {
					    	Title=substr;
						}
						if(field==3)
						{
							Journal=substr;
						}
						if(field==4)
					    {
					    	Month=substr;
						}
						if(field==5)
					    {
					    	Year=substr;
						}
						if(field==6)
					    {
					    	Publisher=substr;
						}
					    if(field>=7 && field<=26  )
						{

					    	if(substr!="")
					    	{
					    		substr.erase(std::remove(substr.begin(), substr.end(), ' '), substr.end());
					    		if(field%2!=0)
							    	{
							    		Lname=substr;
									}
								else
									{
										Fname=substr;
										string name=Fname+" "+Lname;
										
										Author *author=new Author(Fname,Lname);
										listAllAuthors->InsertAllAuthors(Fname,Lname);
										list->InsertAuthor(author);										
									}	
							}
					    	
						}
						
						field++;
						
					}
					
					AuthorNode *start=list->start;
					Article *article=new Article(Identifier,Title,Journal,Month,Year,Publisher,start);
					listOfAA->InsertArticle(article);
				}
				
				AddArticleToAuthor();
				
				MenuCases();
			  	myFile.close();
			  	
			}
		}
		void MenuCases(){
			string inputName= "Mohsen Guizani";
			//listAllAuthors->DisplayAuthor();
			cout<<endl;
			cout << "<< Menu >>"<<endl;
            cout <<"1. No of Articles Published by "<<inputName<<endl;
            cout<<"2. No of Articles Published by "<<inputName<<" Sorted Years."<<endl;
            cout<<"3. No of Co-Authors of Articles published by "<<inputName<<endl;
            cout<<"4. No of papers for each position of "<<inputName<<endl;
            cout<<"5. Sorted Journals in which "<<inputName<<" has published his Reaseach"<<endl;
            
            char userInput;
            cout<<endl;
            cout << "Enter your Choice: ";
            cin >> userInput;
            cout<<endl;
            switch (userInput) 
			{
				case '1':
					listAllAuthors->DisplayAuthorArticle(inputName);
					MenuCases();
					break;
				case '2':
					CountAuthorPublication(inputName);
					MenuCases();
					break;
				case '3':
					coAuthorOfAuthor(inputName);
					MenuCases();
					break;
				case '4':
					CountAuthorPosition(inputName);
					MenuCases();
					break;
				case '5':
					JournalPublishedByAuthor(inputName);
					MenuCases();
					break;
				default:
					cout<<endl;
					cout<<"Invalid Option"<<endl;
					
			}
				
		}
	
		void AddArticleToAuthor(){
			ArticleNode *ListArticleStart=listOfAA->start;
			AllAuthorsNode *ListAuthorsStart=listAllAuthors->start;
			string Fname,Lname,name;
			while(ListArticleStart!=NULL){
				AuthorNode *ArticleAuthorStart=ListArticleStart->data->author;
				while(ArticleAuthorStart!=NULL){
					Fname=ArticleAuthorStart->data->FirstName;
					Lname=ArticleAuthorStart->data->LastName;
					name=Fname+" "+Lname;
					if(listAllAuthors->Exists(name)==true){
						AllAuthorsNode *AuthorAdress;
						AuthorAdress=listAllAuthors->AuthorAdress(name);
						listAllAuthors->LinkArticleNodeWithAllAuthor(ListArticleStart,AuthorAdress);
					}
					ArticleAuthorStart=ArticleAuthorStart->next;
				}
				ListArticleStart=ListArticleStart->next;
			}
		}
		
		void CountAuthorPublication(string name){
			int Y1998 = 0, Y2015 = 0, Y2017 = 0, Y2018 = 0, Y2019 = 0;
			if(listAllAuthors->Exists(name)==true)
				{
					AllAuthorsNode *AuthorAdress;
					AuthorAdress=listAllAuthors->AuthorAdress(name);
					AllAuthorsNode *start=AuthorAdress->AList;
					ArticleNode *article;
			
					while(start!=NULL){
						article=start->AListData;
						string year=article->data->year;
						year.erase(std::remove(year.begin(), year.end(), '{'), year.end());
						year.erase(std::remove(year.begin(), year.end(), '}'), year.end());
						if(year=="1998")
						{
							Y1998+=1;
						}
						if(year=="2015")
						{
							Y2015+=1;
						}
						if(year=="2017")
						{
							Y2017+=1;
						}
						if(year=="2018")
						{
							Y2018+=1;
						}
						if(year=="2019")
						{
							Y2019+=1;
						}
						
						start=start->next;
					}
					cout<<"Author name:  "<<name<<endl;
					cout<<"     1998"<<"     2015"<<"     2017"<<"     2018"<<"     2019"<<endl;
					cout<<"\t"<<Y1998<<"\t"<<Y2015<<"\t"<<Y2017<<"\t"<<Y2018<<"\t"<<Y2019<<endl;					
				}

				
				
		}
		    void coAuthorOfAuthor(string name){
				ArticleNode *ArticleData;
				AuthorNode *AuthorStart;
				coAuthorList *start1998 = new coAuthorList();
				coAuthorList *start2015 = new coAuthorList();
				coAuthorList *start2017 = new coAuthorList();
				coAuthorList *start2018 = new coAuthorList();
				coAuthorList *start2019 = new coAuthorList();
				int y98 = 0, y15 = 0, y17 = 0, y2018 = 0, y19 = 0;
				if(listAllAuthors->Exists(name)==true){
		            AllAuthorsNode *AuthorAdress=listAllAuthors->AuthorAdress(name);
		            AllAuthorsNode *ArticleStart=AuthorAdress->AList;

		            while(ArticleStart!=NULL)
		            {
		            //	cout<<"1st loop"<<endl;
		                int coAuthorCount=0;
		                ArticleData=ArticleStart->AListData;
		                AuthorStart=ArticleData->data->author;
		                string year=ArticleData->data->year;
		        		year.erase(std::remove(year.begin(), year.end(), '{'), year.end());
						year.erase(std::remove(year.begin(), year.end(), '}'), year.end());
		                while(AuthorStart!=NULL)
		                {
		               //	cout<<"2nd Loop"<<endl;
		                    coAuthorCount++;
		                    AuthorStart=AuthorStart->next;
		                }
		                if(year=="1998")
		                {
		                    y98++;
		                    start1998->insertData(ArticleData->data,coAuthorCount-1);
		                }
		                if(year=="2015")
		                {
		                    y15++;
		                    start2015->insertData(ArticleData->data,coAuthorCount-1);
		                }
		                if(year=="2017")
		                {
		                    y17++;
		                    start2017->insertData(ArticleData->data,coAuthorCount-1);
		                }
		                if(year=="2018")
		                {
		                    y2018++;
		                    start2018->insertData(ArticleData->data,coAuthorCount-1);
		                }
		                if(year=="2019")
		                {
		                    y19++;
		                    start2019->insertData(ArticleData->data,coAuthorCount-1);
		                }
		
		                ArticleStart=ArticleStart->next;
		
		            }
		            cout<<endl;
		            if(y98!=0){
			            cout<<"YEAR: 1998"<<endl;
			            cout<<"TOTAL PUBLICATIONS: "<<y98<<endl;
			            start1998->PrintALL();
					}
		            if(y15!=0){
			            cout<<"\n\nYEAR: 2015"<<endl;
			            cout<<"TOTAL PUBLICATIONS: "<<y15<<endl;
			            start2015->PrintALL();}
		            if(y17!=0){
			            cout<<"\n\nYEAR: 2017"<<endl;
			            cout<<"TOTAL PUBLICATIONS: "<<y17<<endl;
			            start2017->PrintALL();}
		            if(y2018!=0){
		            	cout<<"\n\nYEAR: 2018"<<endl;
		             	cout<<"TOTAL PUBLICATIONS: "<<y2018<<endl;
		            	start2018->PrintALL();}
		            if(y19!=0){
			            cout<<"\n\nYEAR: 2019"<<endl;
			            cout<<"TOTAL PUBLICATIONS: "<<y19<<endl;
			            start2019->PrintALL();}
		    	}
		    	cout<<endl;
    		}
    		void JournalPublishedByAuthor(string name){
				if(listAllAuthors->Exists(name)==true){
					AllAuthorsNode *AuthorAdress=listAllAuthors->AuthorAdress(name);
		            AllAuthorsNode *ArticleStart=AuthorAdress->AList;
		            ArticleNode *ArticleData;
		            AuthorNode *AuthorStart;
		            JournalList *start1998=new JournalList();
		            JournalList *start2015=new JournalList();
		            JournalList *start2017=new JournalList();
		            JournalList *start2018=new JournalList();
		            JournalList *start2019=new JournalList();
		            int y98=0,y15=0,y17=0,y2018=0,y19=0;
		            cout<<endl;
					cout<<"Author name: "<<name<<endl;
					while(ArticleStart!=NULL)
					{
						int JournalCount=0;
						ArticleData=ArticleStart->AListData;
		                AuthorStart=ArticleData->data->author;
		                string year=ArticleData->data->year;
		        		year.erase(std::remove(year.begin(), year.end(), '{'), year.end());
						year.erase(std::remove(year.begin(), year.end(), '}'), year.end());
						while(AuthorStart!=NULL){
							JournalCount++;
							AuthorStart=AuthorStart->next;
						}
						 if(year=="1998")
		                {
		                    y98++;
		                    start1998->insertData(ArticleData->data,JournalCount);
		                }
		                if(year=="2015")
		                {
		                    y15++;
		                    start2015->insertData(ArticleData->data,JournalCount);
		                }
		                if(year=="2017")
		                {
		                    y17++;
		                    start2017->insertData(ArticleData->data,JournalCount);
		                }
		                if(year=="2018")
		                {
		                    y2018++;
		                    start2018->insertData(ArticleData->data,JournalCount);
		                }
		                if(year=="2019")
		                {
		                    y19++;
		                    start2019->insertData(ArticleData->data,JournalCount);
		                }
		
		                ArticleStart=ArticleStart->next;
		
		            }
		            cout<<endl;
		            if(y98!=0){
			            cout<<"\tYEAR: 1998"<<endl;
			            cout<<"TOTAL PUBLICATIONS: "<<y98<<endl;
			            start1998->PrintALL();
			            cout<<endl;
					}
		            if(y15!=0){
			             cout<<"\tYEAR: 2015"<<endl;
			            cout<<"TOTAL PUBLICATIONS: "<<y15<<endl;
			            start2015->PrintALL();
						cout<<endl;
						}
		            if(y17!=0){
			             cout<<"\tYEAR: 2017"<<endl;
			            cout<<"TOTAL PUBLICATIONS: "<<y17<<endl;
			            start2017->PrintALL();
			            cout<<endl;
						}
		            if(y2018!=0){
		            	cout<<"\tYEAR: 2018"<<endl;
		             	cout<<"TOTAL PUBLICATIONS: "<<y2018<<endl;
		            	start2018->PrintALL();
						cout<<endl;
						}
		            if(y19!=0){
			             cout<<"\tYEAR: 2019"<<endl;
			            cout<<"TOTAL PUBLICATIONS: "<<y19<<endl;
			            start2019->PrintALL();
						cout<<endl;
						}
		    	}
		    	cout<<endl;
			}
		void CountAuthorPosition(string name){
			if(listAllAuthors->Exists(name)==true)
				{
					int AuthorPosition[11];
					for(int i=0;i<11;i++)
					{
						AuthorPosition[i]=0;
					}
					AllAuthorsNode *AuthorAdress;
					AuthorAdress=listAllAuthors->AuthorAdress(name);
					AllAuthorsNode *start=AuthorAdress->AList;
					ArticleNode *article;
					AuthorNode *authorStart;
					string AuthorName;
					int count=0;
					while(start!=NULL)
					{
						count=1;
						article=start->AListData;
						authorStart=article->data->author;
						while(authorStart!=NULL)
						{
							AuthorName=authorStart->data->FirstName+" "+authorStart->data->LastName;
							if(AuthorName==name)
							{
								AuthorPosition[count]=AuthorPosition[count]+1;
								break;
							}
							count+=1;
							authorStart=authorStart->next;
						}
						start=start->next;
					}
					cout<<"------Articles Published by "<<name<<" at -------\n\n";
					for(int i=1;i<11;i++)
					{
						cout<<"Position "<<i<<" : "<<AuthorPosition[i]<<"\n\n";
					}
				}
		}	
};
int main()
{

	ReadFile *read=new ReadFile();
	read->Read();
}